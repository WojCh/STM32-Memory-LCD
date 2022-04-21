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
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "lcd.h"
#include "font13.h"
#include "gps.h"
#include "bmp180.h"
#include "buttons.h"
#include "customTimer.h"

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
	  char buttonA[50] ={0};
	  char prevActionA[50] ={0};

	int posCounter = 100;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

void increment(void){
	posCounter++;
}
void resetCnt(void){
	posCounter = 100;
}
void decrement(void){
	posCounter--;
}
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
  MX_USART6_UART_Init();
  MX_I2C1_Init();
  MX_TIM11_Init();
  /* USER CODE BEGIN 2 */
//  HAL_UART_Receive_IT(&huart6, &znak, 1);

  //  Initialize VCOMIN pulse on CH1 (PIN PE9) for Sharp Memory LCD
  HAL_TIM_Base_Init(&htim1);
  HAL_TIM_Base_Start_IT(&htim1);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  // Initialize Timer 10 - generating LCD refresh Interrupt
  HAL_TIM_Base_Start_IT(&htim10);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  gpsDevice gpsModule;
  gpsModule = initGps(&huart6);

  bmp_t bmp180module;
//  bmp_t bmp;
  bmp_init(&bmp180module);
//  bmp_init (&bmp);

  btns.BC_handler = &increment;
  btns.BB_handler = &doSomeTiming;
  btns.BA_handler = &decrement;

  initButtons(btnsPtrs);
  btn_BA.continuousLongPressHandler = &decrement;
  btn_BC.continuousLongPressHandler = &increment;
  btn_BB.singleLongPressHandler = &resetCnt;

  initTimer();
  setTimeout(1);
  startClock();


  lcdClearBuffer();
  lcdRefresh();
  while (1)
  {
	  baroDataSet bmpData = getBmpData(&bmp180module);

	  char temp[50] = {0};
	  char pres[50] = {0};
	  char alti[50] = {0};
	  char guiPos[50] ={0};
	  sprintf(&temp, "Temperature: %4.2f degC", bmpData.temperature);
	  sprintf(&pres, "Pressure: %d Pa", bmpData.pressure);
	  sprintf(&alti, "Altitude: %6.2f m", bmpData.altitude);
	  sprintf(&guiPos, "Position: %d", posCounter);

	  lcdClearBuffer();
	  lcdPutStr(0, 0, temp, font13);
	  lcdPutStr(0, 1, pres, font13);
	  lcdPutStr(0, 2, alti, font13);
	  lcdPutStr(0, 3, guiPos, font13);
	  lcdPutStr(0, 4, buttonA, font13);
	  lcdPutStr(0, 8, prevActionA, font13);
	  lcdPutStr(0, 9, buttonHandlers, font13);
	  lcdPutStr(0, 10, buttonHandler2, font13);

	  lcdPutStr(0,5, "B3:", font13);
	  lcdPutChar(45, 110, ('x'-'o')*btns.B3 + 'o', font13);
	  lcdPutStr(0,6, "B2:", font13);
	  lcdPutChar(45, 132, btns.B2 + 'o', font13);
	  lcdPutStr(0,7, "B1:", font13);
	  lcdPutChar(45, 154, btns.B1 + 'o', font13);
	  lcdPutStr(300,5, "BC:", font13);
	  lcdPutChar(345, 110, btns.BC + 'o', font13);
	  lcdPutStr(300,6, "BB:", font13);
	  lcdPutChar(345, 132, btns.BB + 'o', font13);
	  lcdPutStr(300,7, "BA:", font13);
	  lcdPutChar(345, 154, btns.BA + 'o', font13);
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
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
	if(htim->Instance == TIM10){
		HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
//		lcdRefresh();
	}
	if(htim->Instance == TIM11){
//		scanButton(&btn_BA);
//		scanButton(&btn_BB);
//		scanButton(&btn_BC);
//		scanButton(&btn_B1);
//		scanButton(&btn_B2);
//		scanButton(&btn_B3);
		scanButtons(btnsPtrs);
	}
}
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
//	if(GPIO_Pin == BA_Pin){
//		btns.BA = HAL_GPIO_ReadPin(BA_GPIO_Port, BA_Pin) == 0;
////		check if assigned
//		btns.BA_handler();
//	}
//	if(GPIO_Pin == BB_Pin){
//		btns.BB = HAL_GPIO_ReadPin(BB_GPIO_Port, BB_Pin) == 0;
//		btns.BB_handler();
//	}
//	if(GPIO_Pin == BC_Pin){
//		btns.BC = HAL_GPIO_ReadPin(BC_GPIO_Port, BC_Pin) == 0;
//		btns.BC_handler();
//	}
//	if(GPIO_Pin == B1_Pin){
//		btns.B1 = HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == 0;
//		btns.B1_handler();
//	}
//	if(GPIO_Pin == B2_Pin){
//		btns.B2 = HAL_GPIO_ReadPin(B2_GPIO_Port, B2_Pin) == 0;
//		btns.B2_handler();
//	}
//	if(GPIO_Pin == B3_Pin){
//		btns.B3 = HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin) == 0;
//		btns.B3_handler();
//	}
//}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){

	if(huart->Instance == USART6){

//		if(znak == '$'){
//			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
//			HAL_UART_Receive_IT(&huart6, &symbol,5);
//		} else {
////			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
//			HAL_UART_Receive_IT(&huart6, &znak,1);
//		}
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
