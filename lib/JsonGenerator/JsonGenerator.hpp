#ifndef JSONGENERATOR_HPP
#define JSONGENERATOR_HPP

// ----------------------------------Include--------------------------------- //

#include "ArduinoJson.h"
#include <PubSubClient.h>

// -------------------------------------------------------------------------- //

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

// ------------------------------------Struct--------------------------------- //

struct climate_data_t
{
  char date[20];
  float_t bmp180Temp = NAN;
  float_t bmp180Alt = NAN;
  float_t bmp180Press = NAN;
  float_t ds18b20Temp = NAN;
  float_t dht22Temp = NAN;
  float_t dht22Humid = NAN;
  uint16_t illuminance = NAN;
  float_t soilMoisture = NAN;
  uint16_t id = NAN;
};

// --------------------------------Class Interface---------------------------- //

class JsonGenerator
{

public:
  JsonGenerator(climate_data_t &data);
  void prepareData();
  String writeResponseToSerial();
  ~JsonGenerator();
private:
  climate_data_t &collectedData;
  StaticJsonBuffer<168> jsonbuffer;
  JsonObject &newRoot;
  char* payload;
};

#endif
