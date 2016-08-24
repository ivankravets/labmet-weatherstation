/*Pressure Sensor
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Interface of the Pressure Sensor object

Created by: Joao Trevizoli Esteves
*/

#ifndef PRESSURESENSOR_HPP
#define PRESSURESENSOR_HPP

// -----------------------------------------------//

#include <SFE_BMP180.h>

class PressureSensor
{
public:
PressureSensor(SFE_BMP180 &bmp180Ptr, uint32_t updateInterval);
void begin();
float getTemperature();
float getPressure(int oversampling = 2);
float getAltitude(float seaPressure = 1013.25);


private:
void printErrors(const char[]);
bool setTemperature();
bool setPressure(int oversampling);
bool setAltitude(float seaPressure);
char status;
uint32_t previousMillis;
uint32_t updateInterval;
double temperature;
double pressure;
double altitude;
SFE_BMP180 bmp180;
};
#endif
