#include "I2CDevices_test.h"

// -------------------------Generic Functions-------------------------------- //
byte wire_setup(byte addr)
{
  byte error;
  Wire.beginTransmission(addr);
  error = Wire.endTransmission();
  return error;
}

// -------------------------Unit tests--------------------------------------- //

void test_count_i2c_devices(void)
{
  byte addr, error;
  uint8_t nDevices = 0;
  for(addr; addr < 127; addr++)
  {
    Wire.beginTransmission(addr);
    error = Wire.endTransmission();
    if(error == 0)
    {
      nDevices++;
    }
  }
  TEST_ASSERT_EQUAL(5, nDevices);
}

// -------------------------------------------------------------------------- //

void test_lcd_screen_addr(void)
{
  byte error = wire_setup(0x27);
  TEST_ASSERT_EQUAL(0, error);
}

// -------------------------------------------------------------------------- //

void test_bh1750_addr(void)
{
  byte error = wire_setup(0x23);
  TEST_ASSERT_EQUAL(0, error);
}

// -------------------------------------------------------------------------- //

void test_bmp180_addr(void)
{
  byte error = wire_setup(0x77);
  TEST_ASSERT_EQUAL(0, error);
}

// -------------------------------------------------------------------------- //

void test_rtc_addr(void)
{
  byte error = wire_setup(0x68);
  TEST_ASSERT_EQUAL(0, error);
}

// -------------------------------------------------------------------------- //

void test_rtc_addr_2(void)
{
  byte error = wire_setup(0x50);
  TEST_ASSERT_EQUAL(0, error);
}

// -------------------------End of unit tests--------------------------------- //
