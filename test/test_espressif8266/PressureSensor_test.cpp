#include "PressureSensor_test.h"

// ------------------------BMP180 Pressure----------------------------------- //

SFE_BMP180 bmp180;
PressureSensor pressureSensor(bmp180, 1000);

// -------------------------Unit tests--------------------------------------- //

void pressureBegin(void)
{
    pressureSensor.begin();
}

void test_bmp180_started(void)
{
  TEST_ASSERT_TRUE(pressureSensor.getSensorStarted());
}

void test_bmp180_temperature(void)
{
  TEST_ASSERT_FLOAT_IS_NOT_NAN(pressureSensor.getTemperature());
}

void test_bmp180_pressure(void)
{
  TEST_ASSERT_FLOAT_IS_NOT_NAN(pressureSensor.getPressure());
}

void test_bmp180_altitude(void)
{
  TEST_ASSERT_FLOAT_IS_NOT_NAN(pressureSensor.getAltitude());
}

void test_bmp180_printall(void)
{
  TEST_ASSERT_TRUE(pressureSensor.printAll());
}
// -------------------------------------------------------------------------- //
