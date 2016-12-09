#include "espressif_test.h"

// -------------------------Espressif Tests---------------------------------- //

void test_nodemcu_defines_pinage()
{
  uint8_t built_in_pinage_defines[11] = {D0, D1, D2, D3, D4,
    D5, D6, D7, D8, D9, D10};
  uint8_t built_in_pinage_numbers[11] = {16, 8, 4, 0, 2, 14,
    12, 13, 15, 3, 1};
  TEST_ASSERT_EQUAL_UINT8_ARRAY(built_in_pinage_numbers,
    built_in_pinage_numbers, 11);
}

// -------------------------------------------------------------------------- //
