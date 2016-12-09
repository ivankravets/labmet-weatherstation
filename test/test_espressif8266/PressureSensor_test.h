#ifndef PRESSURESENSOR_TEST
#define  PRESSURESENSOR_TEST

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <unity.h>
#include "PressureSensor.hpp"

// ------------------------Pressure Sensor BMP180---------------------------- //
void pressureBegin(void);
void test_bmp180_started(void);
void test_bmp180_temperature(void);
void test_bmp180_pressure(void);
void test_bmp180_altitude(void);
void test_bmp180_printall(void);

// -------------------------------------------------------------------------- //

#endif
