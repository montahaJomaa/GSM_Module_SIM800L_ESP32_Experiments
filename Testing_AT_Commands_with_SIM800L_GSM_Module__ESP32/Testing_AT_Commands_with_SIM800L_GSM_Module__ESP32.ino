//#include <SoftwareSerial.h>

//Create software serial object to communicate with SIM800L
//SoftwareSerial mySerial(3, 2); //SIM800L Tx & Rx is connected to Arduino #3 & #2

//#define TxPin 17
//#define RxPin 16
void setup()
{
  //pinMode(TxPin,INPUT);
  //pinMode(RxPin,OUTPUT);

  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);

  //Begin serial communication with Arduino and SIM800L
  Serial2.begin(9600);

//  Serial.println("Initializing...");
  //delay(1000);

 Serial2.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
 Serial2.println("AT+CSQ"); //Signal quality test, value range is 0-31 , 31 is the best
  updateSerial();
 Serial2.println("AT+CCID"); //Read SIM information to confirm whether the SIM is plugged
  updateSerial();
 Serial2.println("AT+CREG?"); //Check whether it has registered in the network
  updateSerial();
}
void loop()
{
  updateSerial();
}

void updateSerial()
{
 // delay(500);
  while (Serial.available()) 
  {
    Serial2.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(Serial2.available()) 
  {
    Serial.write(Serial2.read());//Forward what Software Serial received to Serial Port
  }
}
