#ifndef JSONGENERATOR_HPP
#define JSONGENERATOR_HPP

#include "ArduinoJson.h"

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

struct climate_data_t
{
  char date[20];
  float_t bmp180Temp = NAN;
  float_t bmp180Alt = NAN;
  float_t bmp180Press = NAN;
  float_t ds18b20Temp = NAN;
  float_t dht22Temp = NAN;
  float_t dht22Humid = NAN;
};

class JsonGenerator
{

public:
  JsonGenerator(climate_data_t &data);
  void prepareData();
  void writeResponseToSerial();
  ~JsonGenerator();
private:
  climate_data_t &collectedData;
  StaticJsonBuffer<120> jsonbuffer;
  JsonObject &newRoot;
};

#endif