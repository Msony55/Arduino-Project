const int PirSensor = 2;
int motionState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PirSensor, INPUT);
}

void loop() {
  motionState = digitalRead(PirSensor);
  if (motionState == HIGH) {
    Serial.println("1"); 
    motionState = LOW;
    delay(20000);
//    while(0);
  }

}
