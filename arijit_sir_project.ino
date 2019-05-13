
#include <ESP8266WiFi.h>

#include <FirebaseArduino.h>





#define FIREBASE_HOST "project-id"
#define FIREBASE_AUTH "db code"
#define WIFI_SSID "wifi-ssid"
#define WIFI_PASSWORD "wifi-password"


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
  Firebase.set("value", voltage);
  
  delay(3000);

}
