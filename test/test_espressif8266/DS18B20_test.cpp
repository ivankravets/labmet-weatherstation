#include "DS18B20_test.h"

// -------------------------DS18B20------------------------------------------ //

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature ds18b20Sensor(&oneWire);
DS18b20 ds18b20(ds18b20Sensor, 500);

// -------------------------Unit tests--------------------------------------- //

void test_ds18B20_begin (void)
{
  bool test_soil_temp_sensor = ds18b20.checkSensor();
  TEST_ASSERT_TRUE(test_soil_temp_sensor);
}

// -------------------------------------------------------------------------- //

void test_ds18B20_improper_value(void)
{
  float temp = ds18b20.getTemperature();
  TEST_ASSERT_FLOAT_WITHIN(100.0, 0.0, temp);
}

// -------------------------End of unit tests--------------------------------- //
