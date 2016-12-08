#ifdef UNIT_TEST

#include <unity.h>
#include <Wire.h>
#include <Arduino.h>
#include "DS18b20.hpp"
#include "BH1750.hpp"
#include "PressureSensor.hpp"

//----------One Wire Devices-------- //
byte wire_setup(byte addr);
void test_count_i2c_devices(void);
void test_lcd_screen_addr(void);
void test_bh1750_addr(void);
void test_bmp180_addr(void);
void test_rtc_addr(void);
void test_rtc_addr_2(void);
//----------Dallas Temperature----- //
void test_ds18B20_begin (void);
void test_ds18B20_improper_value(void);
//----------BH1750----------------- //
void test_bh1750_lum_raw_working(void);
void test_bh1750_lum_working(void);
//----------BMP180 Pressure-------- //
void test_bmp180_temperature(void);

// -------------------------Defines------------------------------------------ //

#define ONE_WIRE_BUS D3

// -------------------------One Wire Devices--------------------------------- //

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature ds18b20Sensor(&oneWire);
DS18b20 ds18b20(ds18b20Sensor, 500);

// -------------------------BH1750------------------------------------------- //

BH1750 bh1750;

// ------------------------BMP180 Pressure----------------------------------- //

SFE_BMP180 bmp180;
PressureSensor pressureSensor(bmp180, 1000);

// -------------------------------------------------------------------------- //


void setup()
{
  Wire.begin();
  ds18b20.begin();
  bh1750.begin();
  pressureSensor.begin();
  delay(1000);
  pinMode(LED_BUILTIN, OUTPUT);
  UNITY_BEGIN();

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

  for (size_t i = 0; i < 5; i++)
  {
    test_bmp180_temperature();
    delay(5000);
  }


// -------------------------------------------------------------------------- //

  UNITY_END();
}

void loop()
{
}

// -------------------------Unittests---------------------------------------- //

// -------------------------I2C Devices-------------------------------------- //

byte wire_setup(byte addr)
{
  byte error;
  Wire.beginTransmission(addr);
  error = Wire.endTransmission();
  return error;
}

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

void test_lcd_screen_addr(void)
{
  byte error = wire_setup(0x27);
  TEST_ASSERT_EQUAL(0, error);
}

void test_bh1750_addr(void)
{
  byte error = wire_setup(0x23);
  TEST_ASSERT_EQUAL(0, error);
}

void test_bmp180_addr(void)
{
  byte error = wire_setup(0x77);
  TEST_ASSERT_EQUAL(0, error);
}

void test_rtc_addr(void)
{
  byte error = wire_setup(0x68);
  TEST_ASSERT_EQUAL(0, error);
}

void test_rtc_addr_2(void)
{
  byte error = wire_setup(0x50);
  TEST_ASSERT_EQUAL(0, error);
}

// -------------------------Dallas Temperature------------------------------- //

void test_ds18B20_begin (void)
{
  bool test_soil_temp_sensor = ds18b20.checkSensor();
  TEST_ASSERT_TRUE(test_soil_temp_sensor);
}

void test_ds18B20_improper_value(void)
{
  float temp = ds18b20.getTemperature();
  TEST_ASSERT_FLOAT_WITHIN(100.0, 0.0, temp);
}

// ------------------------BH1750-------------------------------------------- //

void test_bh1750_lum_raw_working(void)
{
  uint16_t luminance = bh1750.readRawValue();
  TEST_ASSERT_NOT_EQUAL(65535, luminance);
}

void test_bh1750_lum_working(void)
{
  uint16_t luminance = bh1750.readIlluminanceLevel();
  TEST_ASSERT_NOT_EQUAL(54612, luminance);
}
// ------------------------BMP180 Pressure----------------------------------- //

void test_bmp180_temperature(void)
{
  pressureSensor.printAll();
}

// -------------------------Generic Tests------------------------------------ //

// -------------------------------------------------------------------------- //
#endif
