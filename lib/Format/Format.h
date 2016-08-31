#ifndef FORMAT
#define  FORMAT

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <stdarg.h>

String format(const char *strFormat, ...);

#endif
