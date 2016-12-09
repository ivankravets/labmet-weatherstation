#ifdef UNIT_TEST

#include <unity.h>
#include <Arduino.h>
#include "I2CDevices_test.h"
#include "DS18B20_test.h"
#include "BH1750_test.h"
#include "PressureSensor_test.h"
#include "espressif_test.h"


void setup()
{

  Wire.begin();
  bh1750Begin();
  pressureBegin();

  delay(1000);

  UNITY_BEGIN();
// -------------------------NodeMCU------------------------------------------ //

RUN_TEST(test_nodemcu_defines_pinage);

// -------------------------I2C Devices-------------------------------------- //

  RUN_TEST(test_count_i2c_devices);
  RUN_TEST(test_lcd_screen_addr);
  RUN_TEST(test_bh1750_addr);
  RUN_TEST(test_bmp180_addr);
  RUN_TEST(test_rtc_addr);
  RUN_TEST(test_rtc_addr_2);

// -------------------------Dallas Temperature------------------------------- //

  RUN_TEST(test_ds18B20_begin);
  RUN_TEST(test_ds18B20_improper_value);

// ------------------------BH1750-------------------------------------------- //

  RUN_TEST(test_bh1750_lum_raw_working);
  RUN_TEST(test_bh1750_lum_working);

// ------------------------BMP180 Pressure----------------------------------- //

  RUN_TEST(test_bmp180_started);
  RUN_TEST(test_bmp180_temperature);
  RUN_TEST(test_bmp180_pressure);
  RUN_TEST(test_bmp180_altitude);
  RUN_TEST(test_bmp180_printall);

// -------------------------------------------------------------------------- //

  UNITY_END();
}

void loop()
{
}

#endif
