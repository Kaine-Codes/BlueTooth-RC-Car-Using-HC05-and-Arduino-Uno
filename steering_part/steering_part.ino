#include <Servo.h>
int servopin=5;
Servo steerservo;
int pos;
String direc;

void setup() {
  // put your setup code here, to run once:
steerservo.attach(servopin);
Serial.begin(9600); 
}

void loop() {
  delay(1000);
  Serial.println("Position: ");
  while (Serial.available()==0){}
    pos=Serial.parseInt();
    steerservo.write(pos);
  delay(1000);
  }
