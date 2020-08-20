#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
Servo myservo;
#define SS_PIN 10   //RST,SDA(SS),MOSI,MISO,SCK (9,10,11,12,13)
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 
void setup() 
{
   Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
   delay(100);
   myservo.attach(8); 
  // pinMode(1, OUTPUT); 
  //digitalWrite(1,HIGH); 
   lcd.begin(16, 2);
   lcd.setCursor(0, 0);
   lcd.print("Welcome!!");
   lcd.setCursor(0, 1);
   lcd.print("Circuit is Ready");
   delay(3000);
   lcd.clear();  
   SPI.begin();      // Initiate  SPI bus
   Serial.println("Put your card to the reader...");
   Serial.println();
}
void loop() 
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Put your card to");
  lcd.setCursor(0, 1);
  lcd.print("the reader......");
  delay(500);
  
//   Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
   return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "C7 AB B2 4D") //change here the UID of the card/cards that you want to give access
  { 
   lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ID : ");
    lcd.print(content.substring(1));
    lcd.setCursor(0, 1);
    lcd.print("Authorized access");
    Serial.println("Authorized access");
    Serial.println("gate is open");
    delay(1000);
    myservo.write(0);
    delay(5000);
    myservo.write(90);
  }
 else if(content.substring(1) == "C7 AB B2 4D")
 {   
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ID : ");
    lcd.print(content.substring(1));
    lcd.setCursor(0, 1);
    lcd.print("Access denied");
    delay(2000);
    Serial.println(" Access denied");
    delay(1000);
     }
} 

