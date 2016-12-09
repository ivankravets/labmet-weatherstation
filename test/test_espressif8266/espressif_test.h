#ifndef ESPRESSIF_TEST
#define ESPRESSIF_TEST

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <unity.h>

// -------------------------Espressif tests---------------------------------- //

void test_nodemcu_defines_pinage();

// -------------------------------------------------------------------------- //

#endif
