#include <Servo.h>
Servo myservo1; 
Servo myservo2;

  int led1 = 8; 
  int led2 = 9;
  int led3 = 10;
  int led4 = 11;
  int led5 = 12;  //for street light led1 to led5

  int green = 7;
  int yellow = 6;
  int red = 5;    // for traffc light

   int a,b,c,d,e;   
  int pos1 = 0;
  int pos2 = 0;
void setup() 
{
   myservo1.attach(4); // servo at 4
   myservo2.attach(3); // servo at 3
   myservo1.write(0);
   myservo2.write(45);   
     pinMode(A0,INPUT);
     pinMode(A1,INPUT);
     pinMode(A2,INPUT);
     pinMode(A3,INPUT);
     pinMode(A4,INPUT);   //for IR sensors A0 to A4
   
     pinMode(led1,OUTPUT);
     pinMode(led2,OUTPUT);
     pinMode(led3,OUTPUT);
     pinMode(led4,OUTPUT);
     pinMode(led5,OUTPUT);

     pinMode(green,OUTPUT);
     pinMode(yellow,OUTPUT);
     pinMode(red,OUTPUT);
Serial.begin(9600);
Serial.println("welcome to high tech road");
} 
void loop()
 {
    
    digitalWrite(green,HIGH); Serial.println("green led is on");
    delay(5000);          // 5 seconds green signal
    digitalWrite(green,LOW); Serial.println("green led is off");
    digitalWrite(yellow,HIGH);Serial.println("yellow led is on");
    delay(2000);
    Serial.println("wait for a while");
     for (pos1 = 0; pos1 <= 60; pos1 += 1){
    myservo1.write(pos1);
    myservo2.write(0);
     }
     delay(4000);          // 4 seconds yellow signal
     digitalWrite(yellow,LOW); Serial.println("yellow led is off");
     digitalWrite(red,HIGH); Serial.println("red led is on");
     delay(1500);           // 15 seconds red signal
     digitalWrite(red,LOW); Serial.println("red led is off");
     delay(1000);
     for (pos1 = -60; pos1 <=0 ; pos1 -= 1)
   { 
     myservo1.write(pos1);
     myservo2.write(60);
     digitalWrite(green,HIGH);
   //  Serial.println("ready to go");
 }
     a=digitalRead(A0);
     b=digitalRead(A1);
     c=digitalRead(A2);
     d=digitalRead(A3);
     e=digitalRead(A4);

   if(a==HIGH)
   {
     digitalWrite(led1,HIGH);
   }
  else if(b==HIGH)
   {
     digitalWrite(led1,LOW);
     digitalWrite(led2,HIGH);
   }
   else if(c==HIGH)
   {
     digitalWrite(led3,HIGH);
   }
   else if(d==HIGH)
   {
     digitalWrite(led4,HIGH);
   }
   else if(e==HIGH)
   {
     digitalWrite(led5,HIGH);
   }
   else
   {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
   }
 }
 
