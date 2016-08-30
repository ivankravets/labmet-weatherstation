#ifndef ERRORS_HPP
#define  ERRORS_HPP


#include <Arduino.h>

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
