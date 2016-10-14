# Weather monitoring platform with NodeMCU and Raspberry

The weather monitoring platform is composed by NodeMCU clients and one or more
RaspberryPi servers. The NodeMCUs captures environmental weather data with its
sensors and sends them to the RaspberryPi. The RaspberryPi server treats the
collected data and uses them as input for the FAO
[AquaCrop](http://www.fao.org/nr/water/docs/irrigationdrainage66.pdf) model.
With the processed data, the server feeds the website, application and database.
The project is subdivided in three sub-projects, the
[physical implementation](https://github.com/lab804/labmet-weatherstation)
of the weather station that is consisted by the electronic circuit and C/C++
low level firmware, the RaspberryPi [Flask](http://flask.pocoo.org/) web server
and [MQTT](http://mqtt.org/) broker, hosted [here](https://github.com/lab804),
and the [algorithm implementation](https://github.com/lab804) of the AquaCrop model.

![download](https://cloud.githubusercontent.com/assets/22622042/19200013/2f33d736-8c9d-11e6-9320-64f6caaec629.png)

The [NodeMCU](http://nodemcu.com/index_en.html) is a firmware and kit to development that allows the programming of prototypes for the Internet of Things (IoT). The firmware uses event-driven paradigm for easy development of applications that require Internet access. Moreover, modules includes GPIO, 1-Wire, I2C, SPI, PWM, ADC, among others, to facilitate handling modules based on ESP8266 chip. Also, it has antenna Wi-Fi built-in.

The station has a NodeMCU which performs the function of a microcontroller and has a connected sensors to he. The capture of meteorological data held by the station is through the sensors connected to it. The sensors used in our station: light, soil temperature, pressure, relative altitude and humidity. It is possible to add or remove sensors, according to the needs.

Figure 1 Illustrates the operation and the relationship between components: NodeMCU,
Raspberry Pi, Server, Web, App and MongoDB.

#### Figure 1
![demonstrativo_1_labmet](https://cloud.githubusercontent.com/assets/22622042/19085103/771c335a-8a3f-11e6-8490-23a1b3c566d1.png)

In this example we use only one NodeMCU and one Raspberry Pi. However, multiple
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
#### Requirements
* NodeMCU V1.0
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

#### Technologies
* Arduino development framework
* Socket IO
* MQTT

#### Installation
1. Install PlatformIO from http://platformio.org/
2. Open project LabMet Station (Open Project -> Select the directory-> Ok )
3. Install project dependencies.
4. Compile the code and execute in NodeMCU using the respective sensors.
6. Enjoy!

Don't worry about the management of the station because the Raspberry is already set.

## NodeMCU station circuit

![circuito](https://cloud.githubusercontent.com/assets/22622042/19351694/26adbb3c-9133-11e6-9deb-8bcb81a0384c.png)

## Contributing & License

Copyright (c) 2016, Lab804 - All rights reserved.
