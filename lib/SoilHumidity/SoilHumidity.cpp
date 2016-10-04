/*SoilHumidity
    __  _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Implementation of the Soil Humidity Sensor

Created by: Barbara Panosso
*/

#include "SoilHumidity.hpp"

// -------------------------Init method-------------------------------------- //

SoilHumidity::SoilHumidity()
{
  sensorValue = 0;
}
// -------------------------Public methods----------------------------------- //

bool SoilHumidity::getSoilHumidity()
{
  // Make measurement
sensorValue = analogRead(analogPin);
delay(100);
#if SOIL_DEBUG == 1
Serial.println(sensorValue);
#endif
sensorValue = map(sensorValue, 943, 506, 0, 10000);
float moisture = static_cast<float>(sensorValue)/100.0;
#if SOIL_DEBUG == 1
Serial.println(moisture);
#endif
return moisture;
}
// ----------------------------------------------------------------------------//
