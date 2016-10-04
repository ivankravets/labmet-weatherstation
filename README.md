# LabMet - Estação meteorológica com NodeMCU e Raspberry ###

A estação meteorológica é composta por um NodeMCU e um Raspberry. O NodeMCU captura dados climáticos a partir de sensores e as envia para o Raspberry, o qual  gerencia o recebimento e envio destes dados para o servidor. O servidor, por sua vez, trata os dados coletados e alimenta o site, aplicativo e banco de dados com as informações pertinentes. Desta forma, pode-se estipular a produtividade da cultura em questão.

## Lista de componentes: ##


* NodeMCU 1.0
* Raspberry Pi3
* BH1750  - Luminosidade
* DS18B20 - Temperatura do Solo
* BMP180 - Temperatura, Pressão, Altitude
* RTC - Relógio
* DHT22 - Temperatura e UR%
* Soil Moisture Sensor
* Display LCD 16x2p
* Alimentação 5V


## Tecnologias:##


* C/C++
* Python
* Framework de desenvolvimento Arduino
* MongoDB
* Flask
* Socket IO
* Mosquitto
* Tecnologias Web (HTML 5, JavaScript, CSS3 ...)


## Instalação:##

* Instale PlatformIO do http://platformio.org/
* Abra o projeto LabMet Estação (Open Project -> Selecione o diretório-> Ok )
* Instale dependências do projeto
* Compile o código e execute-o no NodeMCU com seus respectivos sensores
* Abra seu navegador em “http://estacao” ou baixe o app LabMet  
* Enjoy!

Não se preocupe com o gerenciamento da estação, pois o Raspberry já está configurado.


## Descrição do projeto##
O NodeMCU é a estação meteorológica, o qual realiza a captura dos dados climáticos a partir de sensores adicionados a ele e, em seguida, os envia para o Raspberry por meio de conexão WiFi, utilizando autenticação de usuário e senha.
O Raspberry recebe os dados através do MQTT, um protocolo de troca de mensagens entre Publisher e Subscriber, o intermediário no processo de comunicação é o broker, que também exige autenticação do cliente por meio de usuário e senha. A identificação das mensagens (dados recebidos) é realizado pelo broker por meio de tópicos.
 	O Servidor é alimentado pelo broker. Os dados recebidos são tratados e enviados para o site, app e banco de dados. As produtividades potenciais são calculadas a partir dos dados recebidos pelo servidor, o modelo de cultura utilizado foi o AquaCrop descrito por Doorenbos & Kassam (1994). O banco de dados utilizado é o MongoDB.
O funcionamento, pode ser exemplificado na Ilustração 1.


#### Ilustração 1####
![demonstrativo_1_labmet](https://cloud.githubusercontent.com/assets/22622042/19085103/771c335a-8a3f-11e6-8490-23a1b3c566d1.png)


Neste exemplo, utilizamos apenas um NodeMCU e um Raspberry. Porém, pode-se adicionar vários NodeMCU em apenas um Raspberry, de forma que se tem várias estações em diferentes lugares, utilizando apenas um gerenciador, como podemos observar na Ilustração 2.


#### Ilustração 2####
![demonstrativo_2_labmet](https://cloud.githubusercontent.com/assets/22622042/19085120/902669d8-8a3f-11e6-85ad-532257b41262.png)

 Esta condição só é possível se as estações estiverem no perímetro de alcance da rede WIFi do gerenciador, sendo imprescindível a conexão para seu funcionamento correto.




## Copyright e Licença##

Copyright 2016 - Lab804
