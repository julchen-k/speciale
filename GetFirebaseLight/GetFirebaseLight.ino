

#include <ESP8266WiFi.h>
//#include <CapacitiveSensor>

#include <FirebaseArduino.h>
 
#define FIREBASE_HOST "masters-thesis-c1928-default-rtdb.europe-west1.firebasedatabase.app" // Firebase host
#define FIREBASE_AUTH "qPOQcnIRcJEOdLDnygOYFs2REQi7s12mRwWtUcKj" //Firebase Auth code
#define WIFI_SSID "Julias iPhone" //Enter your wifi Name
#define WIFI_PASSWORD "magi1212" // Enter your password
int fireStatus = 0;

void setup() {
  Serial.begin(9600);
  pinMode(D1, OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println("Connected.");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.set("LED_STATUS", 0);
}
 
void loop() {
  fireStatus = Firebase.getInt("LED_STATUS");
  if (fireStatus == 1) {
    Serial.println("Led Turned ON");
    digitalWrite(D1, HIGH);
  }
  else if (fireStatus == 0) {
    Serial.println("Led Turned OFF");
    digitalWrite(D1, LOW);
  }
  else {
    Serial.println("Command Error! Please send 0/1");
  }
} 
