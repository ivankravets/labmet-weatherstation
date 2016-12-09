#ifndef BH1750_TEST
#define  BH1750_TEST

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <unity.h>
#include "BH1750.hpp"


//----------BH1750----------------- //
void bh1750Begin(void);
void test_bh1750_lum_raw_working(void);
void test_bh1750_lum_working(void);
//--------------------------------- //

#endif
