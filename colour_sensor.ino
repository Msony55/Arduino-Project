
#include <Servo.h>

#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sOut 6

Servo Servo1;  //top servo
Servo Servo2;   // bottom servo

int frequency = 0;
int color=0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sOut, INPUT);

  
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

 Servo1.attach(11);
  Servo2.attach(12);

  Serial.begin(9600);
  Servo2.write(0);   //servo2 at position 0
  Servo1.write(0);
  delay(5000);
}

void loop() {

  Servo1.write(115);
  delay(500);
  
  for(int i = 115; i > 65; i--) {
    Servo1.write(i);
    delay(2);
  }
  delay(500);
  
  color = Sensecolor();
  delay(10);  

  switch (color) {
    case 1: //RED Color
    Servo2.write(50);
    break;

    case 2:  //Green Color
    Servo2.write(75);
    break;

    case 3:   //Blue Color
    Servo2.write(100);
    break;

    case 4:   //Orange Color
    Servo2.write(125);
    break;

    case 5: //White Color
    Servo2.write(150);
    break;

    
    case 0:
    break;
  }
  delay(300);
  
  for(int i = 65; i > 29; i--) {
    Servo1.write(i);
    delay(2);
  } 
  delay(200);
  
  for(int i = 29; i < 115; i++) {
    Servo1.write(i);
    delay(2);
  }
  color=0;
}

// Custom Function - Sensecolor()
int Sensecolor() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequency = pulseIn(sOut, LOW);
  int R = frequency;
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);

  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sOut, LOW);
  int G = frequency;
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);

  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sOut, LOW);
  int B = frequency;
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.println("  ");
  delay(50);

   if(R<48 & R>20 & B<105 & B>75)
   {
    Serial.println("RED");// Red
    color = 1;  
  }
  if(R<165 & R>110 & G<103 & G>57)
  {
    Serial.println("Green");
    color = 2; // Green
  }
  if (G<180 & G>125 & B<90 &B>46)
  {
    Serial.println("Blue");
    color = 3; // Blue
  }
  if(R<70 & R>47 & B<195 &B>140)
  {
    Serial.println("Orange");
    color = 4; // Orange
  }
  
  if(R<35 & R>16 & G<33 & G>17)
  {
    Serial.println("White");
    color = 5; // White
  } 
  return color;  
}
