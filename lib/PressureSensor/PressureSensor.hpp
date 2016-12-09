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
// --------------------------------Debug Directives--------------------------- //

#define BMP_DEBUG 1

// --------------------------------Error messages----------------------------- //

#define ERROR_BMP180_START "can't begin the bmp180 sensor"
#define ERROR_OVERSAMPLIMP "The parameter oversampling must be with a integer between 0 and 3"
#define ERROR_BMP180_TEMP_START "Error while starting the temperature sensor of the bmp180 module"
#define ERROR_BMP180_PRESSURE_START "Error while starting the pressure sensor of the bmp180 module"

// -------------------------------Error codes--------------------------------- //

#define ERROR_BMP180_START_CODE 31
#define ERROR_OVERSAMPLIMP_CODE 32
#define ERROR_BMP180_TEMP_START_CODE 33
#define ERROR_BMP180_PRESSURE_START_CODE 34

// --------------------------------------------------------------------------- //

#include <SFE_BMP180.h>
#include "Format.h"

// -------------------------Class Interface---------------------------------- /

class PressureSensor
{
public:
PressureSensor(SFE_BMP180 &bmp180Ptr, uint32_t updateInterval,
  int oversampling = 2, double seaPressure = 1013.25);
void begin();
float getTemperature();
float getPressure();
float getAltitude();
bool printAll();
bool getSensorStarted();

private:
inline void printErrors(const char *msg);
bool setTemperature();
bool setPressure();
bool setAltitude();
void update();
char status;
uint32_t previousUpdate;
uint32_t updateInterval;
int oversampling;
bool started;
double seaPressure;
double temperature;
double pressure;
double altitude;
SFE_BMP180 bmp180;
};
#endif
