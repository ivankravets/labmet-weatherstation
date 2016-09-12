#ifndef DS18B20_HPP
#define DS18B20_HPP

// --------------------Errors------------------------ //

#define ERROR_DS18B20_NOT_FOUND "DS18B20 sensor not found"
#define ERROR_DS18B20_START "Can't begin the ds18b20 sensor"
#define ERROR_DS18B20_NEGATIVE_TEMP "Negative temperature"



// ----------------Error codes-------------------- //

#define ERROR_DS18B20_SENSOR_CODE 91
#define ERROR_DS18B20_START_CODE 92
#define ERROR_DS18B20_NEGATIVE_TEMP_CODE 93


// ----------------------------------------------- //

//nodeMCU v1.0 (black) with Arduino IDE
//stream temperature data DS18B20 with 1wire on ESP8266 ESP12-E (nodeMCU v1.0)
//shin-ajaran.blogspot.com
//nodemcu pinout https://github.com/esp8266/Arduino/issues/584
// #include <Arduino.h>


#include <DallasTemperature.h>
#include "Errors.hpp"


class DS18b20
{
      public:
        uint16_t teste2;
        DS18b20(uint8_t one_wire_bus,  uint32_t updateInterval, int oversampling,
        bool errorPrinting);
        // ~DS18y20();
        bool checkSensor();
        void begin();
        void printAddress(DeviceAddress deviceAddress);

      private:
        inline void printErrors(const char *msg);
        bool setTemperature();
        bool update();
        bool getTemperature();
        OneWire oneWire;
        DallasTemperature *sensors;
        DeviceAddress insideThermometer;
        uint8_t one_wire_b;
        Errors erro;
        uint32_t updateInterval;
        int oversampling;
        bool errorPrinting;
        uint32_t previousUpdate;
        double temperature;
        float temp;

};

#endif
