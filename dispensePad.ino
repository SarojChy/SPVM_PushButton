void checkForStack() {
  if (NPadNo > NpadLim) {
    dispensePad1();
//    Serial.println("Dispensed from 1");
    delay(500);
  }
  if (NPadNo <= NpadLim) {
    dispensePad2();
//    Serial.println("Dispensed from 2");
    delay(500);
  }
}

void dispensePad1() {
  //  Buzzer();
  displayMsg("Please Wait");
  delay(2000);
  lcd.setCursor(0, 1);
  lcd.print(data);
  delay(1000);
  rotateMotor1();
  displayMsg("Collect Your PAD");
  delay(2000);
  displayMsg("   Thank You!");
  delay(2000);
  displayMsg("Press the Button");
}
void dispensePad2() {
  //  Buzzer();
  displayMsg("Please Wait");
  delay(2000);
  lcd.setCursor(0, 1);
  lcd.print(data);
  delay(1000);
  rotateMotor2();
  displayMsg("Collect Your PAD");
  delay(2000);
  displayMsg("   Thank You!");
  delay(2000);
  displayMsg("Press the Button");
}
