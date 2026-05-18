
//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

byte eye1[] = {B11111,B11111,B11111,B11111,B11111,B11110,B11110,B11110};

byte eye2[] = {B11111,B11111,B11111,B11111,B11111,B00000,B00000,B00000};

byte eye3[] = {B11111,B11111,B11111,B11111,B11111,B01111,B01111,B01111};
byte eye4[] = {B11110,B11110,B11110,B11111,B11111,B11111,B11111,B11111};

byte eye5[] = {B00000,B00000,B00000,B11111,B11111,B11111,B11111,B11111};

byte eye6[] = {B01111,B01111,B01111,B11111,B11111,B11111,B11111,B11111};

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.createChar(1, eye1);
  lcd.setCursor(3,0);
  lcd.write(1);
  lcd.createChar(2, eye2);
  lcd.setCursor(4,0);
  lcd.write(2);
  lcd.createChar(3, eye3);
  lcd.setCursor(5,0);
  lcd.write(3);
  lcd.createChar(4, eye4);
  lcd.setCursor(3,1);
  lcd.write(4);
  lcd.createChar(5, eye5);
  lcd.setCursor(4,1);
  lcd.write(5);
  lcd.createChar(6, eye6);
  lcd.setCursor(5,1);
  lcd.write(6); 

  lcd.createChar(1, eye1);
  lcd.setCursor(11,0);
  lcd.write(1);
  lcd.createChar(2, eye2);
  lcd.setCursor(12,0);
  lcd.write(2);
  lcd.createChar(3, eye3);
  lcd.setCursor(13,0);
  lcd.write(3);
  lcd.createChar(4, eye4);
  lcd.setCursor(11,1);
  lcd.write(4);
  lcd.createChar(5, eye5);
  lcd.setCursor(12,1);
  lcd.write(5);
  lcd.createChar(6, eye6);
  lcd.setCursor(13,1);
  lcd.write(6);
  }
