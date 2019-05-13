
#include <ESP8266WiFi.h>

#include <FirebaseArduino.h>





#define FIREBASE_HOST "first-arduino-ef1f4.firebaseio.com"
#define FIREBASE_AUTH "gBhXw6xbjC1wxetf5dffcrQTsDgBUcr5oI6m47Up"
#define WIFI_SSID "NEW OXYGEN"
#define WIFI_PASSWORD "roadprime@8934"


void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  if(Firebase.failed())
  {
    Serial.println("Firebase not connected");
  }
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  float voltage = sensorValue*(5.0/1023.0);
  Serial.println(voltage);
  Firebase.set("value", 1);
  
  delay(3000);

}
