/* Errors
    __ _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Implementation of the climate datalogger object

Created by: Barbara Panosso
*/


#ifndef ERRORS_HPP
#define  ERRORS_HPP


#include <Arduino.h>
#include <EEPROM.h>

// -----------------------------------------------//

class Errors
{
public:
  Errors();
  bool errors(String status, String clasS, String function, String message);
  void save(String post);  // save to eeprom and sd
  void del(); // delete to eeprom
  void checkStatusCodePost(int code, String post);

private:


};

#endif
