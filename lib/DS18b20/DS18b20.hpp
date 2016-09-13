/*DS18b20
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Interface of the DS18b20 Sensor object

Created by: Barbara Panosso
*/

#ifndef DS18B20_HPP
#define DS18B20_HPP

// -------------------------Errors------------------------------------------- //
#define ERROR_DS18B20_NOT_FOUND "DS18B20 sensor not found"
#define ERROR_DS18B20_START "Can't begin the ds18b20 sensor"
#define ERROR_DS18B20_NEGATIVE_TEMP "Negative temperature"

// -------------------------Error codes-------------------------------------- //

#define ERROR_DS18B20_SENSOR_CODE 91
#define ERROR_DS18B20_START_CODE 92
#define ERROR_DS18B20_NEGATIVE_TEMP_CODE 93

// -------------------------------------------------------------------------- //

#include <DallasTemperature.h>
#include "Errors.hpp"


class DS18b20
{
      public:
        uint16_t teste2;
        DS18b20(uint8_t one_wire_bus,  uint32_t updateInterval, int oversampling,
        bool errorPrinting);
        // ~DS18y20();
        void begin(bool debug = false);
        bool checkSensor();
        void printAddress(DeviceAddress deviceAddress);

      private:
        inline void printErrors(const char *msg);
        bool setTemperature();
        bool update();
        bool getTemperature();
        bool errorPrinting;
        bool debuging;
        int oversampling;

        uint8_t one_wire_b;
        uint32_t updateInterval;
        uint32_t previousUpdate;
        double temperature;
        float temp;

        OneWire oneWire;
        DallasTemperature *sensors;
        DeviceAddress thermometerAddr;
        Errors erro;

};

#endif
