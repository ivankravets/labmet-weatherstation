#ifndef DS18B20_T
#define  DS18B20_T

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <unity.h>
#include "DS18b20.hpp"

#define ONE_WIRE_BUS D3


// //----------Dallas Temperature----- //
void test_ds18B20_begin (void);
void test_ds18B20_improper_value(void);
//------------------------------------ //

#endif
