#include <SPI.h>
#include <Wire.h>
#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>

#define BUZZ 8 //define pin buzzer pin
#define MOTDEBUG
#define motorEN1 4  //enbalbe pin for driver 
#define motorEN2 4 //enbalbe pin for driver 

int Nema17Motor_Steps = 200;
//int Nema14Motor_Steps = 100;

#define stepPin  3
#define dirPin  2
#define stepPin2  6
#define dirPin2 5
const int PadNo = 60;   //Total number of PAD
String data;
int NpadLim = PadNo / 2;
int address = 0;
int address2 = 1;
int pinState;
#define Inputpin A1
#define Resetpin A0
LiquidCrystal_I2C lcd(0x27, 16, 2);
int NPadNo;

const int checkInHour = 15;
const int checkInMinute = 40;

int userCheckInHour;
int userCheckInMinute;

void setup()
{
    digitalWrite(motorEN1, HIGH);
  digitalWrite(motorEN2, HIGH);
  Buzzer();
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  SPI.begin();

  pinMode(BUZZ, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(motorEN1, OUTPUT);

  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(motorEN2, OUTPUT);



  pinMode(Resetpin, INPUT_PULLUP);
  pinMode(Inputpin, INPUT_PULLUP);
  EEPROM.update(address, PadNo);
  NPadNo = EEPROM.read(address2);

  lcd.clear();
  displayMsg("    Namaste");
  delay(2000);
  displayMsg("** Nepatronix **");
  for (int a = 0; a <= 15; a++) {
    lcd.setCursor(a, 1);
    lcd.print(".");
    delay(150);
  }
  delay(1000);
  displayMsg("Press the Button");
  lcd.setCursor(1, 1);
  lcd.print("Available: ");
  lcd.setCursor(12, 1);
  lcd.print(NPadNo);
}

void loop()
{
  Reset();
  NPadNo = EEPROM.read(address2);
  Serial.println(NPadNo);
  delay(1000);
  if (NPadNo  > 0) {
    verify();
  }
  else {
    nopad();
  }
}

void verify() {
  if (digitalRead(Inputpin) == LOW) {
    Buzzer();
    checkForStack();
    count();
  }
}
