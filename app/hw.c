/*
 *  hw.c
 *  Abstrai as funções do HAL e CMSIS
 *
 *  Created on: August 14, 2022
 *      Author: lesly
 */

#include <stdbool.h>
#include <stdint.h>
#include "main.h"
#include "app.h"
#include "hw.h"

extern TIM_HandleTypeDef htim1;

void hw_input_capture_init(void){
	HAL_TIM_Base_Start(&htim1);
	hw_input_capture_set(0);
}

uint16_t hw_input_capture_get(void){
	return __HAL_TIM_GET_COUNTER(&htim1);
}

void hw_input_capture_set(uint16_t cnt){
	__HAL_TIM_SET_COUNTER(&htim1,cnt);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(GPIO_Pin == BUTTON_Pin){
		app_button_interrupt();
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if(htim == &htim1) {
		hw_toggle_led();
		__HAL_TIM_SET_COUNTER(&htim1, 0);
	}
}

void hw_toggle_led(void){
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}

uint32_t hw_tick_ms_get(void){
	return HAL_GetTick();
}



