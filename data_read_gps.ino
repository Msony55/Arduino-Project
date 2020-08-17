#include <TinyGPS++.h>

#include <SoftwareSerial.h>
SoftwareSerial ss(4, 3);
static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps;
void setup(){
  Serial.begin(9600);
  ss.begin(9600);
  ss.begin(GPSBaud);
}

void loop(){
  while (ss.available() > 0){
    byte gpsData = ss.read();
    //Serial.write(gpsData);
     gps.encode(ss.read());
     if (gps.location.isUpdated()){
      Serial.print("Latitude= "); 
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Longitude= "); 
      Serial.println(gps.location.lng(), 6);
     }
     else
      Serial.print("not updated\n");
  }
}
