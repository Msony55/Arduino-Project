const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT);
pinMode(7,OUTPUT);// Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
digitalWrite(7,LOW);
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= ((duration/29.1)/2);
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
delay(500);
if(distance>50 && distance<150)
{
 digitalWrite(7,HIGH);
  delay(500);
  digitalWrite(7,LOW);
  delay(500);
}
if(distance>30 && distance<50)
{
 digitalWrite(7,HIGH);
  delay(300);
  digitalWrite(7,LOW);
  delay(300);
}
if( distance>10 && distance<30)
{
 digitalWrite(7,HIGH);
  delay(100);
  digitalWrite(7,LOW);
  delay(100);
}
if( distance<10)
{
 digitalWrite(7,HIGH);
  delay(50);
  digitalWrite(7,LOW);
  delay(50);
}
digitalWrite(7,LOW);
}




