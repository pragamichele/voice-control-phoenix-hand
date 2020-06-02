// include the servo library
#include <Servo.h>

byte com = 0;

//define the servo name
Servo myServo;


void setup() {
  
Serial.begin(9600);

myServo.attach(9); //define servo pin

myServo.write(20); //servo position 20 degrees

delay(2000);

Serial.write(0xAA);

Serial.write(0x37);

delay(1000);

Serial.write(0xAA);

Serial.write(0x21);
}

void loop() {

  while(Serial.available()) {

  com = Serial.read();

  switch(com) {

      case 0x11:   //verde per salutare

      myServo.write(100); //turn to 100 degrees chiudi

      delay(600); //aspetta
      
      myServo.write(30); //turn to 30 degrees apri

      delay(600); //aspetta

      myServo.write(100); //turn to 100 degrees chiudi

      delay(600); //aspetta

      myServo.write(30); //turn to 30 degrees apri

      delay(600); //aspetta

      myServo.write(100); //turn to 100 degrees chiudi

      delay(600); //aspetta

      myServo.write(30); //turn to 30 degrees apri

      

      break;

      case 0x12:  //command 2 is for Red LED

      

      break;

      case 0x13:  //command 3 is for servo stringi

       myServo.write(125); //turn to 125 degrees 

      break;

      case 0x14:  //command 4 is for Servo motor


      myServo.write(30); //turn to 30 degrees apri
      

      break;

      case 0x15:  //command 5 is for Servo Motor

      myServo.write(110); //turn to 110 degrees chiudi
      
      

      break;

            }
      }
}
