/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "fatfs.h"
#include "i2c.h"
#include "rtc.h"
#include "sdio.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "lcd.h"
#include "bmp180.h"
#include "buttons.h"
#include "gui.h"
#include "fonts/fonts.h"
#include "fatfs.h"
#include "File_Handling.h"
#include "countdownTimer.h"

#include "utils/timerUtils.h"


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
	int GLOBAL_timezone = 1;		// [h] east+ west-
	location_t location;

	RTC_TimeTypeDef RtcTime;
	RTC_DateTypeDef RtcDate;
//	ring buffers for sensor data
//	RingBuffer_t baroRing;
	cbuf_t baroRing;
	RingBuffer_t tempRing;
	gpsDevice_t gpsDev;
//	char dmaBuffer[GPS_BUFFER_SIZE];
	uint8_t tim13_prescaler = 3; // 1Hz/(x+1) = 1Hz/4 = 4s period
	uint8_t tim13_counter = 0; // 1Hz/4 = 4s period
	// flag to execute BMP180 update in the main program loop
	uint8_t updateBmpData_flag = 1;
	countdown_t countDown1 = {5, 5, 0};
	extern uint8_t animationFrameNum;



/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int __io_putchar(int ch){
	ITM_SendChar(ch);
	return(ch);
}


uint8_t timeoutState = 0;
uint16_t timeoutValue;
uint16_t timeoutSetpoint;
void (*timeoutClbkPtr)(void);
void setTimeout(uint16_t ms,  void (*callback)(void)){
	// set timeout setpoint
	timeoutSetpoint = ms;
	// reset timeout value
	timeoutValue = 0;
	// set callback function
	timeoutClbkPtr = callback;
	// flag timeout running
	timeoutState = 1;
}

uint8_t alertFlag = 0;
void showAlert(void){
	lcdRect2(50, 350, 50, 190, 3, 0, 1);
	lcdPutStr(90, 90, "Alert!", zekton24font);
}
void hideAlert(void){
	alertFlag = 0;
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART3_UART_Init();
  MX_SPI1_Init();
  MX_TIM1_Init();
  MX_TIM10_Init();
  MX_I2C1_Init();
  MX_TIM11_Init();
  MX_RTC_Init();
  MX_TIM13_Init();
  MX_SDIO_SD_Init();
  MX_FATFS_Init();
  MX_USART6_UART_Init();
  MX_TIM14_Init();
  /* USER CODE BEGIN 2 */
  //  Initialize VCOMIN pulse on CH1 (PIN PE9) for Sharp Memory LCD
  HAL_TIM_Base_Init(&htim1);
  HAL_TIM_Base_Start_IT(&htim1);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  // Initialize Timer 10 (1Hz) - for stopwatch
  stwInit(&htim10);
  // Vibration motor PWM
  HAL_TIM_PWM_Start(&htim14, TIM_CHANNEL_1);

  // TIMER 11 - 20Hz button scanner
  HAL_TIM_Base_Start_IT(&htim11);
  initButtons(btnsPtrs);

  // TIMER 13 - 1Hz sensors logger
  HAL_TIM_Base_Start_IT(&htim13);
  gpsDev = initGps(&huart6);
  // bmp180module defined inside of c file
  bmp_init(&bmp180module);
//  init_ring_buffer(&baroRing, 399);
  init_ring_buffer(&tempRing, 399);
  cbuf_init(&baroRing, sizeof(uint16_t), 399);

	HAL_GPIO_WritePin(SD_CS_GPIO_Port, SD_CS_Pin, GPIO_PIN_SET);
  	Mount_SD("/");
  	Create_File("FILE1.TXT");
  	Update_File("FILE1.TXT", "Hello world, SD cart write \n");
  	Create_File("FILE4.TXT");
  	char fileText[50];
  	Read_File("config.txt", &fileText);

  	// log state after reset
  	HAL_RTC_GetTime(&hrtc, &RtcTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &RtcDate, RTC_FORMAT_BIN);
	char tmpl[50] = {0};
	sprintf(&tmpl, "%02d:%02d:%02d --- Initialized ---\n", RtcTime.Hours, RtcTime.Minutes, RtcTime.Seconds);
	SD_logger(tmpl);
//  	Unmount_SD("/");
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  lcdClearBuffer();
  lcdRefresh();
  while (1)
  {
	  // periodic execution driven by flag modified inside of timer interrupt
	  if(updateBmpData_flag){
		bmpData = getBmpData(&bmp180module);
		updateBmpData_flag = 0;
	  }
	  // functions executed along with the menu
		HAL_RTC_GetTime(&hrtc, &RtcTime, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&hrtc, &RtcDate, RTC_FORMAT_BIN);
		if(RtcTime.Minutes == 0 && RtcTime.Seconds==0){
			pulseVib(40, 60);
		}
	  lcdClearBuffer();
	  // functions executed through GUI
	  showGui();

	  if(alertFlag){
		  showAlert();
		btn_B2.onSinglePressHandler = &hideAlert;

	  }

	  lcdRefresh();

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	// APB2 168MHz -> after PSCL 1Hz
	// used to time stopwatch
	if(htim->Instance == TIM10){
		stwTick();
		// animation frame tick
		animationFrameNum++;
	}
	// APB2 168MHz -> after PSCL 100Hz
	// button polling
	if(htim->Instance == TIM11){
		scanButtons(btnsPtrs);
		// check timeouts
		if(timeoutState){
			if(timeoutValue == timeoutSetpoint){
				(*timeoutClbkPtr)();
				timeoutState = 0;
			} else {
				timeoutValue++;
			}
		}
	}
	// APB1 84MHz -> after PSCL 1Hz
	if(htim->Instance == TIM13){
		// watchface module timer value incrementing
		tickTimAAB();
//		HAL_UART_Receive_DMA(&huart6, &dmaBuffer, GPS_BUFFER_SIZE);
		if(gpsDev.isReady != 0) gpsDev.getData(&gpsDev);

		HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
		if(tempRing.isReady) add_ovw_ring_buffer(&tempRing, (int)(10*bmpData.temperature));
		uint16_t aaa = (uint16_t)(bmpData.pressure/10);
		if(baroRing.isReady) cbuf_ovw(&baroRing, &aaa);

		tim13_counter++;
		if(tim13_counter == tim13_prescaler){
			HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
			// set flag up - causes to update temp/baro data to update in the main loop
			updateBmpData_flag = 1;
//			bmpData = getBmpData(&bmp180module);
			tim13_counter = 0;
		}
		if(isTimerRunning(&countDown1)){
			if(countDown1.remainingSec == 0){
				alertFlag = 1;
				pauseTimer(&countDown1);
			} else {
				countDown1.remainingSec--;
			}
		}
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(huart->Instance == USART6){
		HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
	}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
	HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
