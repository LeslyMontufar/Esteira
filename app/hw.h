/*
 * hw.h
 *
 *  Created on: August 14, 2022
 *      Author: lesly
 */

#ifndef HW_H_
#define HW_H_

void hw_input_capture_init(void);
uint16_t hw_input_capture_get(void);
void hw_input_capture_set(uint16_t cnt);

void hw_toggle_led(void);
uint32_t hw_tick_ms_get(void);

#endif /* HW_H_ */
