#include "Format.h"

String format(const char *strFormat, ...)
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
      case 'D':
        concatedString += strToFormat.substring(lastPosition, replacePosition);
        concatedString += va_arg(argv, int);
        break;
      case 'f':
      case 'F':
      case 'l':
      case 'L':
        concatedString += strToFormat.substring(lastPosition, replacePosition);
        concatedString += va_arg(argv, double);
        break;
      case 'c':
      case 'C':
        concatedString += strToFormat.substring(lastPosition, replacePosition);
        concatedString += (char)va_arg(argv, int);
        break;
      case 's':
      case 'S':
        concatedString += strToFormat.substring(lastPosition, replacePosition);
        concatedString += va_arg(argv, const char *);
        break;
      default: ;
    }
    lastPosition = replacePosition + 2;
  }
  return concatedString;
}
