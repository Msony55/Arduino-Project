#include<Servo.h>                //Adding the Servo library
#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
Servo myservo; //Define an object named MyServo
const int eko=7;        
const int trig=6; 
const int eko2=9;        
const int trig2=8;       
int mesafe;
int sure;
int mesafe2;
int sure2;
int pos= 0; 
void setup() {
  myservo.attach(10);     //We introduced the ninth pin arduino to the servo motor
  lcd.begin(16,2);
  Serial.begin(9600);
  lcd.setCursor(1,0);
  lcd.print("SMART DUSTBIN");
  pinMode(trig,OUTPUT);        
  pinMode(eko,INPUT);  

   pinMode(trig2,OUTPUT);        
  pinMode(eko2,INPUT);
    
       Serial.println("AT");                      // for GSM Module
       delay(3000);
       Serial.println("AT+CSCS=\"GSM\"");
       delay(3000);
   myservo.write(pos);      
}

void loop() {
  myservo.write(0);           
  
  digitalWrite(trig, LOW);         
  delayMicroseconds(10);
  digitalWrite(trig, HIGH);       
  delayMicroseconds(20);
  digitalWrite(trig, LOW);         
  sure = pulseIn(eko, HIGH);      
  mesafe= (sure/29.1)/2;  
  Serial.println(mesafe);

  digitalWrite(trig2, LOW);         // For checking condition of dustbin
  delayMicroseconds(10);
  digitalWrite(trig2, HIGH);       
  delayMicroseconds(20);
  digitalWrite(trig2, LOW);         
  sure2 = pulseIn(eko2, HIGH);      
  mesafe2= (sure2/29.1)/2; 
  Serial.println(mesafe2);
  //.............................. for check status............................................... 
  if (mesafe2<=8)           
  {
    Serial.println("FULL FILLED");
    lcd.setCursor(2,1);
    lcd.print("FULL FILLED");
  
  }
  if (mesafe2>15 && mesafe2<=25)
  {
    Serial.println("HALF FILLED");
    lcd.setCursor(2,1);
    lcd.print("HALF FILLED");
  //  digitalWrite(A0,HIGH);
   // digitalWrite(A1,HIGH);
   // digitalWrite(A2,LOW);
  }
  if (mesafe2>=40)
  {
    Serial.println("COMPLETELY UNFILLED");
    lcd.setCursor(2,1);
    lcd.print("EMPTY");
  
  }   
//................................. for gate of dustbin................................................
 if(mesafe<=8){
     myservo.write(pos+160);
     Serial.println("mesafe");
      Serial.println(mesafe);
    delay(1000);   
  }
  else 
  {
      myservo.write(pos);
      Serial.println("mesafe");
      Serial.println(mesafe);
  }
// for GSM.............................................................
  if (mesafe2<=5) 
  {
    Serial.println("AT+CMGF=1");
  delay(2000);
  Serial.println("AT+CMGS=\"8619636679\""); // pnkj contact no. as office
  delay(2000);
  Serial.println("The dustbin at location A has been Full Filled,...");   
  Serial.print(char(26));
  delay(4000);
  }
  
delay(100);
}

