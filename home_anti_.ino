#include <Servo.h>
#include <SoftwareSerial.h> 

SoftwareSerial bt(9,10);
char a,b;
const int ledpin=13;
// const int motionpin=2;  
const int flamePin = 11;
//int buzzer = 8;
int servoPin = 13;
Servo Servo1; 
void setup() {
  bt.begin(9600);
  Servo1.attach(servoPin);
//  pinMode(buzzer, OUTPUT);
  pinMode(flamePin, INPUT);
//   pinMode(motionpin,INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(8,HIGH);
  pinMode(3,HIGH);
}
void loop() {
 /* if (digitalRead(2) == HIGH && digitalRead(8) == LOW){             //2 = motion pin
      digitalWrite(ledpin,HIGH);          // tone(buzzer,100); //turns on led(13) and buzzer
     digitalWrite(buzzer,HIGH);               // 12 = buzzer
   // Serial.println('HIGH');
  }
   else if (digitalRead(2) == HIGH && digitalRead(8) == HIGH){             //2 = motion pin
       digitalWrite(ledpin,LOW);          // tone(buzzer,100); //turns on led(13) and buzzer
       digitalWrite(buzzer,LOW);               // 12 = buzzer
      // Serial.println('LOW');
  }
  if (digitalRead(11) == LOW )                          //flame = 11
  {
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
     delay(500);
  }
  else if (digitalRead(11) == HIGH )                          //flame = 11
  {
    digitalWrite(buzzer, LOW);
  }*/
  if(bt.available())
  {
    a = bt.read();      //Read the incoming data and store it into variable Incoming_value
    Serial.println(a);        //Print Value of Incoming_value in Serial monitor
    if(a == 'A')            //Checks whether value of Incoming_value is equal to a
       Servo1.write(120);                 //If value is 1 then 90 degree rotate
    else if(a == 'B')       //Checks whether value of Incoming_value is equal to b
        Servo1.write(0);                 //If value is 0 then 0 degree rotate
        if(a == 'C')            //Checks whether value of Incoming_value is equal to a
        digitalWrite(8,HIGH);              //If value is 1 then 90 degree rotate
    else if(a == 'D')       //Checks whether value of Incoming_value is equal to b
        digitalWrite(8,LOW);
         if(a == 'E')            //Checks whether value of Incoming_value is equal to a
        digitalWrite(3,HIGH);              //If value is 1 then 90 degree rotate
    else if(a == 'F')       //Checks whether value of Incoming_value is equal to b
        digitalWrite(3,LOW); 
  }
}
