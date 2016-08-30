#include "ConnectServer.hpp"
#include "Errors.hpp"

ConnectServer Local;

Errors::Errors(){}


bool Errors::errors(String status, String clasS, String function, String message)
{
  String send_msg;

  send_msg = "error=";
  send_msg += status;
  send_msg += "&class=";
  send_msg += clasS;
  send_msg += "&function=";
  send_msg += function;
  send_msg += "&message=";
  send_msg += message;

  Local.postPage(send_msg, "/errors");
}


void Errors::checkStatusCodePost(int StatusCode, String strpost)
{
  if(StatusCode != 200)
      save(strpost);
  else
  return;

}

void Errors::save(String post)
{
   //salva cartao e/ou eeprom
}

void del()
{
  // deleta da eeprom
}
