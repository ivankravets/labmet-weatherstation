/* Errors
    __ _       _      ___   ___  _  _    __
  / / | | __ _| |__  ( _ ) / _ \| || |   \ \
/ /   | |/ _` | '_ \ / _ \| | | | || |_   \ \
\ \   | | (_| | |_) | (_) | |_| |__   _|  / /
 \_\  |_|\__,_|_.__/ \___/ \___/   |_|   /_/

Implementation of the climate datalogger object

Created by: Barbara Panosso
*/

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
  // receber status code servidor ou procurar na resposta servidor

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
