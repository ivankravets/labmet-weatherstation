#ifndef FORMAT
#define  FORMAT

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <stdarg.h>

String format(String strFormat, ...)
{
  int replacePosition = 0, lastPosition = 0, count = 0;
  String strToFormat = String(strFormat);
  String concatedString = "";
  for (size_t i=0; i<strToFormat.length(); i++) if(strToFormat[i]=='%') count++;

  va_list argv;
  va_start(argv, count);

  for (size_t i = 0; i <count; i++)
  {
    replacePosition = strToFormat.indexOf('%', replacePosition + i);
    switch (strToFormat[replacePosition + 1])
    {
      case 'd':
        concatedString += strToFormat.substring(lastPosition, replacePosition);
        concatedString += va_arg(argv, int);
        break;
      case 'f':
        concatedString += strToFormat.substring(lastPosition, replacePosition);
        concatedString += va_arg(argv, double);
        break;
      case 'c':
        concatedString += strToFormat.substring(lastPosition, replacePosition);
        concatedString += (char)va_arg(argv, int);
        break;
      case 's':
        concatedString += strToFormat.substring(lastPosition, replacePosition);
        concatedString += va_arg(argv, const char *);
        break;
      default: ;
    }
    lastPosition = replacePosition + 2;
  }
  return concatedString;
}

#endif
