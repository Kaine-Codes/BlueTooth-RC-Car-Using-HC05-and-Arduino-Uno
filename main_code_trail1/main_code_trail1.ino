#include <Wire.h>
#include <Servo.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

// set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
// create the software bluetooth thing
SoftwareSerial bluetoothSerial(2, 3);  // 2=Rx , 3=Tx of arduino
// variable for the custon eye
byte eye1[] = {B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111};
byte eye2[] = {B11111, B11111, B11111, B11111, B11111, B00000, B00000, B00000};
byte eye3[] = {B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111};
byte eye4[] = {B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111};
byte eye5[] = {B00000, B00000, B00000, B11111, B11111, B11111, B11111, B11111};
byte eye6[] = {B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111};

// motor control pins
int in1 = 11;
int in2 = 10;
int in3 = 9;
int in4 = 8;
String dir = "";
String predir = "";
char incomingChar;

//headlight pin
int headlightpin = 4;

//coollights pin
int coollightpin = 6;

// steering contorller servo
int servopin = 5;
Servo steerservo;

void showeye(int dt, int i = 1) {
  lcd.clear();
  lcd.createChar(1, eye1);
  lcd.setCursor(i + 2, 0);
  lcd.write(1);
  lcd.createChar(2, eye2);
  lcd.setCursor(i + 3, 0);
  lcd.write(2);
  lcd.createChar(3, eye3);
  lcd.setCursor(i + 4, 0);
  lcd.write(3);
  lcd.createChar(4, eye4);
  lcd.setCursor(i + 2, 1);
  lcd.write(4);
  lcd.createChar(5, eye5);
  lcd.setCursor(i + 3, 1);
  lcd.write(5);
  lcd.createChar(6, eye6);
  lcd.setCursor(i + 4, 1);
  lcd.write(6);

  lcd.createChar(1, eye1);
  lcd.setCursor(i + 10, 0);
  lcd.write(1);
  lcd.createChar(2, eye2);
  lcd.setCursor(i + 11, 0);
  lcd.write(2);
  lcd.createChar(3, eye3);
  lcd.setCursor(i + 12, 0);
  lcd.write(3);
  lcd.createChar(4, eye4);
  lcd.setCursor(i + 10, 1);
  lcd.write(4);
  lcd.createChar(5, eye5);
  lcd.setCursor(i + 11, 1);
  lcd.write(5);
  lcd.createChar(6, eye6);
  lcd.setCursor(i + 12, 1);
  lcd.write(6);

  delay(dt);
}
void eyeblink(int dt = 400) {
  lcd.clear();

  lcd.createChar(4, eye5);
  lcd.setCursor(3, 1);
  lcd.write(4);
  lcd.createChar(5, eye5);
  lcd.setCursor(4, 1);
  lcd.write(5);
  lcd.createChar(6, eye5);
  lcd.setCursor(5, 1);
  lcd.write(6);

  lcd.createChar(4, eye5);
  lcd.setCursor(11, 1);
  lcd.write(4);
  lcd.createChar(5, eye5);
  lcd.setCursor(12, 1);
  lcd.write(5);
  lcd.createChar(6, eye5);
  lcd.setCursor(13, 1);
  lcd.write(6);

  delay(dt);
}
void setup() {
  //initiallize the LCD and show the welcome thing
  lcd.init();
  lcd.backlight();

  //initialize the serial monitors
  bluetoothSerial.begin(9600);
  Serial.begin(9600);

  //initialize headlight pins
  pinMode(headlightpin, OUTPUT);

  //initialize cooollight pins
  pinMode(coollightpin, OUTPUT);

  //initiallize motor driver pins
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  //initiallize the servo
  steerservo.attach(servopin);
  steerservo.write(50);
}
int start = 1;

void loop() {
  if (start == 1) {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("LETSSS GOOO!");
    delay(1000);
    showeye(500);
    eyeblink();
    showeye(500);
    showeye(500, 3);
    showeye(500, -2);
    showeye(500);
    eyeblink();
    showeye(100);
  }
  start = 0;
  while (bluetoothSerial.available()) {
    incomingChar = bluetoothSerial.read();
    if (incomingChar == '\n') {
      dir.trim();
      if (predir == dir) {
        continue;
      } else if (dir == "F") { //go forward
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW );
        digitalWrite(in4, HIGH);
        steerservo.write(55);
      } else if (dir == "B") { //go backward
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        steerservo.write(55);
      } else if (dir == "S") { //stop Car
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        steerservo.write(55);
        showeye(0);
      } else if (dir == "R") { //turn right
        steerservo.write(30);
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        showeye(0, -2);
      } else if (dir == "L") { //turn left
        steerservo.write(80);
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        showeye(0, 3);
      }

      else if (dir == "G") { //forward right
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW );
        digitalWrite(in4, HIGH);
        steerservo.write(80);
        showeye(0, -2);
      } else if (dir == "H") { //forward left
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW );
        digitalWrite(in4, HIGH);
        steerservo.write(30);
        showeye(0, 3);
      } else if (dir == "I") { //backward right
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        steerservo.write(80);
        showeye(0, 3);
      } else if (dir == "J") { //backward left
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        steerservo.write(30);
        showeye(0, -2);
      }
      
      else if (dir == "U") { //on headlight
        digitalWrite(headlightpin, HIGH);
      } else if (dir == "u") { //off headligh
        digitalWrite(headlightpin, LOW);
      }else if (dir == "Z") { //on cool lights
        digitalWrite(coollightpin, HIGH);
      } else if (dir == "z") { //off cool lights
        digitalWrite(coollightpin, LOW);
      }
      predir = dir;
      dir = "";  // Clear after processing
    } else {
      dir += incomingChar;
    }
  }
}
