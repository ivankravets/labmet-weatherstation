 # Weather station with NodeMCU and Raspberry

The weather station is composed by one NodeMCU and one Raspberry. The NodeMCU captures weather data from sensors and sends them to Raspberry, which manages the receiving and sending of this data to the server. The server, for its part, treats the collected data, feed the website, application and database with the pertinent informations. In this way, the crop yield in question can be stipulated.

![download](https://cloud.githubusercontent.com/assets/22622042/19200013/2f33d736-8c9d-11e6-9320-64f6caaec629.png)

The NodeMCU is the weather station, which captures the weather data from the added sensors and send them to the Raspberry using an username and password authentication WiFi connection. The Raspberry receives the data through MQTT, a message exchange protocol between Publisher and Subscriber. The intermediary in the communication process is the broker, which also requires clients username and password authentication. The messages identification (received data) is performed by the broker by means of threads. The server is fed with the broker. The received data are treated and sent to the website, application and database. The crop yield is calculated using the received data from the server. The culture model used is AquaCrop,described by Doorenbos & Kassam (1994). The database utilized is MongoDB. It's operation can be exemplified in Figure 1.

#### Figure 1
![demonstrativo_1_labmet](https://cloud.githubusercontent.com/assets/22622042/19085103/771c335a-8a3f-11e6-8490-23a1b3c566d1.png)


In this example we use only one NodeMCU and one Raspberry. However, multiple NodeMCU can be added to one single Raspberry, so that you have several stations in different locations using a single manager, as observed in figure 2.


#### Figure 2
![demonstrativo_2_labmet](https://cloud.githubusercontent.com/assets/22622042/19085120/902669d8-8a3f-11e6-85ad-532257b41262.png)

This condition is only possible if the stations are in the range of the manager's WiFi network, Which is indispensable for the components to work properly.

## Getting Started
#### Requirements
* NodeMCU V1.0
* Raspberry Pi3
* BH1750 - Luminosity
* DS18B20 - Soil temperature
* BMP180 - Temperature, Pressure, Altitude
* RTC - Clock
* DHT22 - Temperature and Relative Humidity%
* Soil Moisture Sensor
* Display LCD 16x2
* 5V Power supply

#### Languages
* C/C++
* Python

#### Technologies
* Arduino development framework
* MongoDB
* Flask
* Socket IO
* Mosquitto
* Web (HTML 5, JavaScript, CSS3 ...)

#### Installation
1. Install PlatformIO from http://platformio.org/
2. Open project LabMet Estação (Open Project -> Select the directory-> Ok )
3. Install project dependencies.
4. Compile the code and execute in NodeMCU using the respective sensors.
5. Open in your browser “http://estacao” or download the app LabMet
6. Enjoy!

Don't worry about the management of the station because the Raspberry is already set.

## NodeMCU station circuit

![circuito](https://cloud.githubusercontent.com/assets/22622042/19351694/26adbb3c-9133-11e6-9deb-8bcb81a0384c.png)



## Contributing

Copyright (c) 2016, Lab804 - All rights reserved.
