/*  

Library:     pwm01.h (version 02)
Date:        2/11/2013 - 2/7/2015
Written By:  randomvibe, Collin Kidder

Purpose:     
   Setup one or two unique PWM frequenices directly in sketch program,
   set PWM duty cycle, and stop PWM function.

User Functions:     
   pwm_set_resolution(int res) ~  setup PWM resolution; up to 16 bit
   pwm_setup( uint32_t pwm_pin, uint32_t pwm_freq, int iclock) ~ Setup PWM on clock-A (iclock=1) or clock-B (iclock-2)
   pwm_write_duty( uint32_t pwm_pin, uint32_t pwm_duty) ~ Write PWM duty cycle
   pwm_stop( uint32_t pwm_pin) ~ Force PWM stop
   pwm_update_clocks
   pwm_set_clockA_freq(uint32_t  val)

Notes:
   - Applies to Arduino-Due board, PWM pins 6, 7, 8 & 9.
   - Libary Does not operate on the TIO pins.
   - Unique frequencies set via PWM Clock-A ("CLKA") and Clock-B ("CLKB")
     Therefore, up to two unique frequencies allowed.
   - Set max duty cycle counts (pwm_max_duty_Ncount) equal to 255
     per Arduino approach.  This value is best SUITED for low frequency
     applications (2hz to 40,000hz) such as PWM motor drivers, 
     38khz infrared transmitters, etc.
   - Future library versions will address high frequency applications.
   - Arduino's "wiring_analog.c" function was very helpful in this effort.
      
*/

#include "Arduino.h"

void pwm_set_resolution(int res);
void pwm_set_clockA_freq(uint32_t  freq);
void pwm_set_clockB_freq(uint32_t  freq);
static inline uint32_t mapResolution(uint32_t value, uint32_t from, uint32_t to);
static inline void pwm_update_clocks();
void  pwm_setup( uint32_t  pwm_pin,  uint32_t  pwm_freq,  int iclock  );
void  pwm_write_duty( uint32_t  pwm_pin,  uint32_t  pwm_duty );
void  pwm_stop( uint32_t  pwm_pin );

