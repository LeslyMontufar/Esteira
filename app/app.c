/*
 * Lesly Montúfar
 * app.c
 *
 *
*/

#include <stdint.h>
#include <stdbool.h>
#include "main.h"
#include "app.h"
#include "hw.h"

#define APP_DEBOUNCING_TIME_MS 100

bool app_started = false;

void app_button_interrupt(void){
	static uint32_t debouncing_time_ms = 0;

	if(!app_started)
		return;

	if((hw_tick_ms_get() - debouncing_time_ms) >= APP_DEBOUNCING_TIME_MS){
		hw_toggle_led();
		hw_input_capture_set(0); // pra ter certeza
		debouncing_time_ms = hw_tick_ms_get();
	}
}

void app_init(void){
	app_started = true;
	hw_input_capture_init();
}

void app_loop(void){
	uint16_t cnt = hw_input_capture_get();

	if(cnt > 10){
		hw_input_capture_set(0);
		hw_toggle_led();
	}
}
