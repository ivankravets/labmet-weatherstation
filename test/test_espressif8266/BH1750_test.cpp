#include "BH1750_test.h"

// -------------------------BH1750------------------------------------------- //

BH1750 bh1750;

// -------------------------Init bh1750-------------------------------------- //

void bh1750Begin()
{
  bh1750.begin();
}

// -------------------------Unit tests--------------------------------------- //


void test_bh1750_lum_raw_working(void)
{
  uint16_t luminance = bh1750.readRawValue();
  TEST_ASSERT_NOT_EQUAL(65535, luminance);
}

// ---------------------------------------------------------------------------//


void test_bh1750_lum_working(void)
{
  uint16_t luminance = bh1750.readIlluminanceLevel();
  TEST_ASSERT_NOT_EQUAL(54612, luminance);
}

// -------------------------End of unit tests--------------------------------- //
