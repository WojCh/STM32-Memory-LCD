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
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "gps.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "digits5x9.h"
#include "digits8x16.h"
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

gpsTime now = {"00", "00", "00"};

uint8_t buffer[600];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

//void getGpsMsg(struct gpsObj *obj){
//	uint8_t a;
//	uint8_t msg[166];
//	while(a != '$'){
//		HAL_UART_Receive(&huart6, &a, 1, 0);
//	}
//	HAL_UART_Receive(&huart6, &msg, 166, 0);
//
//	uint16_t index = 0;
//	while((strcmp(msg[index], "GNZDA") != 0) & (index < 166)){
//		index++;
//	}
//	obj->hour[0] = msg[index+6];
//	obj->hour[1] = msg[index+7];
//}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  /* USER CODE BEGIN 2 */
//  HAL_UART_Receive_IT(&huart6, &znak, 1);

  //  Initialize VCOMIN pulse on CH1 (PIN PE9) for Sharp Memory LCD
  HAL_TIM_Base_Init(&htim1);
  HAL_TIM_Base_Start_IT(&htim1);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  // Initialize Timer 10 - generating LCD refresh Interrupt
  HAL_TIM_Base_Start_IT(&htim10);

  char text[] = "Pik!";

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	  lcdClearBuffer();
	  lcdRefresh();
  while (1)
  {


	  HAL_UART_Receive(&huart6, &buffer, 600, 1000);
	  test(&buffer, &now);

//	  getGpsMsg(struct gpsObj &gpsTime);
//	  uint16_t index = 0;
//	  while(index < 166){
//		  if((msg[index] == '$') & (index <= 166-83)){
//			  ppp[0] = msg[index+1];
//			  ppp[1] = msg[index+2];
//			  ppp[2] = msg[index+3];
//			  ppp[3] = msg[index+4];
//			  ppp[4] = msg[index+5];
//			  ppp[5] = 0;
//			//	  $GNZDA,191126.000,27,03,2022,00,00*40   [37B]
//			  if(strcmp(ppp, "GNZDA") == 0){
////				  strncpy(qqq, msg[index+6],10);
//				  qqq[0] = msg[index+7];
//				  qqq[1] = msg[index+8];
//				  qqq[2] = ':';
//				  qqq[3] = msg[index+9];
//				  qqq[4] = msg[index+10];
//				  qqq[5] = ':';
//				  qqq[6] = msg[index+11];
//				  qqq[7] = msg[index+12];
//				  qqq[8] = 0;
//				  break;
//			  }
//		  }
//		index++;
//		}
	  lcdClearBuffer();
//	  lcdPutStr(0,0, ppp,dig5x9);
//	  lcdPutStr(0,1, qqq,dig5x9);
	  lcdPutStr(0,0, now.hour ,dig5x9);
	  lcdPutStr(0,1, now.minute ,dig5x9);
	  lcdPutStr(0,2, now.second ,dig5x9);
	  lcdRefresh();
//	  HAL_Delay(1000);

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
}
char currChar, index;

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

