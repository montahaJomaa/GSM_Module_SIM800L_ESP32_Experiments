//#include <SoftwareSerial.h>

String Arsp, Grsp;
//SoftwareSerial gsm(10, 11); // RX, TX

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.println("Testing GSM SIM800L");
  Serial2.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial2.available())
  {
    Grsp = Serial2.readString();
    Serial.println(Grsp);
  }

  if(Serial.available())
  {
    Arsp = Serial.readString();
    Serial2.println(Arsp);
  }

}
