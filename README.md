# Labmet Weather Station

The labmet is a platform that were build with a simple goal, to help people know what they are doing when the question is agriculture by seamlessly using the agronomical best practices on their own planted food and to help them have the best with the lowest possible environmental impact.

![download](https://raw.githubusercontent.com/lab804/labmet-server/labmet_libraries/app/static/img/Logo.png)

The agricultural monitoring platform is composed by NodeMCU clients and one or more
RaspberryPi servers. The NodeMCUs captures environmental weather data with its
sensors and sends them to the RaspberryPi. The RaspberryPi treats the data and uses them as input for crop models such as the FAOs
[AquaCrop](http://www.fao.org/nr/water/docs/irrigationdrainage66.pdf) model.
With the data the server feeds a website, a mobile app and a non-relational database.
The labmet project is divided in three sub-projects, the [physical implementation](https://github.com/lab804/labmet-weatherstation)
of the weather station that is consisted by the electronic circuit and C/C++
low level firmware and the RaspberryPi [Flask](http://flask.pocoo.org/) web server
and [MQTT](http://mqtt.org/) broker, hosted in [here](https://github.com/lab804/labmet-server).The last piece of the platform is the algorithm implementation of several crop models and weather/agronomic variables estimation and calculus, the url for the project will be soon available [here](https://github.com/lab804)

### ![download](https://avatars1.githubusercontent.com/u/9865736?v=3&s=40)  NodeMCU


The [NodeMCU](http://nodemcu.com/index_en.html) is a development platform that allows prototyping Internet of Things devices (ioT). Despite its firmware been originally based on the [eLua](http://www.eluaproject.net/) Espressif NON-OS SDK, there is plenty of support to interface through the Arduino SDK with ESP8266 boards. Its GPIO pins has almost the same capabilities of an Arduino UNO such as 1-Wire, I2C, SPI, PWM, ADC and etc. It also has a built-in Wi-Fi antenna.

### System Architecture


The station NodeMCU performs the function of both a data logger and an web client, and has sensors attached that measure meteorological and agronomic data. The project of the station intends to be pluggable, so it should be possible to seamlessly attache any sensor and collect virtually any environmental index. The system architecture is Illustrated below in Figure 1.

#### Figure 1

![demonstrativo_1_labmet](https://cloud.githubusercontent.com/assets/22622042/19085103/771c335a-8a3f-11e6-8490-23a1b3c566d1.png)

In this example there is only one NodeMCU and one Raspberry Pi. However, multiple
NodeMCU can be added to one single Raspberry Pi, so that you have several stations
in different locations using a single manager, as observed in figure 2. It is
important to mention that the same goes for the Raspberry Pi and servers,
where you have a Raspberry Pi connected to one or more servers.

#### Figure 2
![demonstrativo_2_labmet](https://cloud.githubusercontent.com/assets/22622042/19085120/902669d8-8a3f-11e6-85ad-532257b41262.png)

This condition is only possible if the stations are in range of the manager's
WiFi network. Remember the Raspberry Pi must be connected to the Internet, so the
data and information are processed in real time, which is indispensable for
the components work properly.


## Getting Started

#### Hardware Requirements
* NodeMCU V1.0
* RaspberryPi 3
* BH1750 - Luminosity
* DS18B20 - Soil temperature
* BMP180 - Temperature, Pressure, Altitude
* DS1307 - Real Time Clock
* DHT22 - Temperature and Relative Humidity
* Analogical Soil Moisture Sensor with I2C
* Display LCD 16x2
* 5V Power supply

#### Languages
* C/C++
* Python
* HTML5, Javascript...

#### Technologies
* Arduino development framework
* Socket IO
* MQTT

#### Installation
1. Install PlatformIO IDE from http://platformio.org/platformio-ide
2. Download and open the project in the IDE (Open Project -> Select the directory-> Ok )
3. The project dependencies will be installed on the fly, so the Internet connection is required.
4. Compile the code and execute in NodeMCU using the respective sensors.
5. Enjoy!

Don't worry about the weather station management and RaspberryPi server configuration, just run this [shell script](https://github.com/lab804/generate-ap) on your raspbian based RaspberryPi and all will be automatically set for you ;)

#### Notes

* If you need all the fritzing schematics are available on the project root
* If you need anything, don't hesitate to get in touch with us, it would be awesome!

## Weather station circuit

![circuito](https://cloud.githubusercontent.com/assets/22622042/19351694/26adbb3c-9133-11e6-9deb-8bcb81a0384c.png)

## Contributing & License

Copyright (c) 2016, Lab804 - All rights reserved.
