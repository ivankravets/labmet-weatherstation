#include "JsonGenerator.hpp"

JsonGenerator::JsonGenerator(climate_data_t &data):
collectedData(data), newRoot(jsonbuffer.createObject())
{

}
// -------------------------------------------------------------------------- //
JsonGenerator::~JsonGenerator()
{
}
// -------------------------------------------------------------------------- //

void JsonGenerator::prepareData()
{
  newRoot["collected_at"] = collectedData.date;
  newRoot["bmp180_temp"] = collectedData.bmp180Temp;
  newRoot["bmp180_alt"] = collectedData.bmp180Alt;
  newRoot["bmp180_press"] = collectedData.bmp180Press;
  newRoot["ds18b20_temp"] = collectedData.ds18b20Temp;
  newRoot["dht22_temp"] = collectedData.dht22Temp;
  newRoot["dht22_humid"] = collectedData.dht22Humid;
  newRoot["bh1750_illuminance"] = collectedData.illuminance;
  newRoot["analog_soil_moisture"] = collectedData.soilMoisture;
}
// -------------------------------------------------------------------------- //
String JsonGenerator::writeResponseToSerial()
{
  this->prepareData();
  char buffer[256];
  this->newRoot.printTo(buffer, sizeof(buffer));
  return buffer;
}
