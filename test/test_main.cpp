#ifdef UNIT_TEST

#include <unity.h>
#include <Wire.h>
#include <Arduino.h>
#include "DS18b20.hpp"


byte wire_setup(byte addr);
void test_count_i2c_devices(void);
void test_lcd_screen_addr(void);
void test_bh1750_addr(void);
void test_bmp180_addr(void);
void test_rtc_addr(void);
void test_ds18B20_begin (void);
void test_led_builtin_pin_number(void);
void test_led_state_high(void);
void test_led_state_low(void);

// -------------------------Defines------------------------------------------ //

#define ONE_WIRE_BUS D3

// -------------------------One Wire Devices--------------------------------- //

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature ds18b20Sensor(&oneWire);
DS18b20 ds18b20(ds18b20Sensor, 500);
// -------------------------------------------------------------------------- //

void setup() {
    Wire.begin();
    ds18b20.begin();
    pinMode(LED_BUILTIN, OUTPUT);
    UNITY_BEGIN();
}

void loop()
{
// -------------------------I2C Devices-------------------------------------- //

    RUN_TEST(test_count_i2c_devices);
    RUN_TEST(test_lcd_screen_addr);
    RUN_TEST(test_bh1750_addr);
    RUN_TEST(test_bmp180_addr);
    RUN_TEST(test_rtc_addr);
// -------------------------Dallas Temperature------------------------------- //

    RUN_TEST(test_ds18B20_begin);

    RUN_TEST(test_led_builtin_pin_number);
    RUN_TEST(test_led_state_high);
    RUN_TEST(test_led_state_low);
    UNITY_END();
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
  TEST_ASSERT_EQUAL(3, nDevices);
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

// -------------------------Dallas Temperature------------------------------- //

void test_ds18B20_begin (void)
{
  bool test_soil_temp_sensor = ds18b20.checkSensor();
  TEST_ASSERT_TRUE(test_soil_temp_sensor);
}

// -------------------------Generic Tests------------------------------------ //
void test_led_builtin_pin_number(void)
{
    TEST_ASSERT_EQUAL(LED_BUILTIN, 16);
}
void test_led_state_high(void) {
    digitalWrite(LED_BUILTIN, HIGH);
    TEST_ASSERT_EQUAL(digitalRead(LED_BUILTIN), HIGH);
}

void test_led_state_low(void) {
    digitalWrite(LED_BUILTIN, LOW);
    TEST_ASSERT_EQUAL(digitalRead(LED_BUILTIN), LOW);
}

#endif
