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
	int GLOBAL_timezone = 2;		// [h] east+ west-
	location_t location;

	RTC_TimeTypeDef RtcTime;
	RTC_DateTypeDef RtcDate;
//	ring buffers for sensor data
//	RingBuffer_t baroRing;
	cbuf_t baroRing;
	RingBuffer_t tempRing;
	gpsDevice_t gpsDev;
//	char dmaBuffer[GPS_BUFFER_SIZE];


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
  /* USER CODE BEGIN 2 */
  //  Initialize VCOMIN pulse on CH1 (PIN PE9) for Sharp Memory LCD
  HAL_TIM_Base_Init(&htim1);
  HAL_TIM_Base_Start_IT(&htim1);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  // Initialize Timer 10 - generating LCD refresh Interrupt
//  HAL_TIM_Base_Start_IT(&htim10);

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
	  // functions executed along with the menu
		bmpData = getBmpData(&bmp180module);
		HAL_RTC_GetTime(&hrtc, &RtcTime, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&hrtc, &RtcDate, RTC_FORMAT_BIN);
	  lcdClearBuffer();
	  // functions executed through GUI
	  showGui();

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
	if(htim->Instance == TIM10){
		if(stwS.state){
			stwTick();
		}
	}
	// APB2 168MHz -> after PSCL 100Hz
	if(htim->Instance == TIM11){
		scanButtons(btnsPtrs);
	}
	// APB1 84MHz -> after PSCL 1Hz
	if(htim->Instance == TIM13){
//		HAL_UART_Receive_DMA(&huart6, &dmaBuffer, GPS_BUFFER_SIZE);
		if(gpsDev.isReady != 0) gpsDev.getData(&gpsDev);

		HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
		if(tempRing.isReady) add_ovw_ring_buffer(&tempRing, (int)(10*bmpData.temperature));
		uint16_t aaa = (uint16_t)(bmpData.pressure/10);
		if(baroRing.isReady) cbuf_ovw(&baroRing, &aaa);

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
