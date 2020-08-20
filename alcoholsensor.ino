#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
 lcd.print("ALCOHOL DETECTOR");
 lcd.setCursor(0,1);
 lcd.print("Level: ");
  pinMode(A0,INPUT);
  pinMode(7,OUTPUT);
  digitalWrite(7,LOW);
  

}

void loop() {
  // put your main code here, to run repeatedly:
int  alcohol=analogRead(A0);
Serial.println(alcohol);
delay(500);
lcd.setCursor(0,1);
 lcd.print("Level: ");
 lcd.print(alcohol);
  if(alcohol>300)
  {
    digitalWrite(7,HIGH);
    delay(500);
    digitalWrite(7,LOW);
    delay(500);
    
  }

  

}
