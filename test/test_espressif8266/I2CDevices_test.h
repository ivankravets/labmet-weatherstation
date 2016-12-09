#ifndef I2CDEVICES_TEST
#define  I2CDEVICES_TEST

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Wire.h>
#include <unity.h>

// -------------------------I2C Devices-------------------------------------- //

byte wire_setup(byte addr);
void test_count_i2c_devices(void);
void test_lcd_screen_addr(void);
void test_bh1750_addr(void);
void test_bmp180_addr(void);
void test_rtc_addr(void);
void test_rtc_addr_2(void);

// -------------------------------------------------------------------------- //

#endif
