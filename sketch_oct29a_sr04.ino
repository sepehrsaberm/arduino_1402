#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);  //trig
  pinMode(10, INPUT);  //echo
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(9, LOW);
  delayMicroseconds(2);
  digitalWrite(9, HIGH);
  delayMicroseconds(10);
  digitalWrite(9, LOW);
  int t = pulseIn(10, HIGH);
  float distance = t * 0.034 / 2;
  lcd.setCursor(0, 0);
  lcd.print("distance:");
  lcd.print(distance);
  Serial.println(distance);
  delay(10);
  lcd.clear();
  float x = map(distance, 4, 30, 255,0);
  if (distance <= 4) {
    digitalWrite(6, HIGH);
  } else if (distance >= 32) {
    digitalWrite(6, LOW);
  } else {
    analogWrite(6, x);
  }
}
