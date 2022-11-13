#include <FirebaseCloudMessaging.h>
#include <Firebase.h>
#include <FirebaseHttpClient.h>
#include <FirebaseArduino.h>
#include <FirebaseError.h>
#include <FirebaseObject.h>

#include <ESP8266Firebase.h>

#include <SoftwareSerial.h>

#include <ESP8266WiFi.h>

#define FIREBASE_HOST "https://masters-thesis-c1928-default-rtdb.europe-west1.firebasedatabase.app/"
#define FIREBASE_AUTH "qPOQcnIRcJEOdLDnygOYFs2REQi7s12mRwWtUcKj"
#define WIFI_SSID "NETGEAR52"
#define WIFI_PASSWORD "cleverchair260"

 
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_CAP1188.h>

// Reset Pin is used for I2C or SPI
#define CAP1188_RESET  9

// CS pin is used for software or hardware SPI
#define CAP1188_CS  10

// These are defined for software SPI, for hardware SPI, check your 
// board's SPI pins in the Arduino documentation
#define CAP1188_MOSI  11
#define CAP1188_MISO  12
#define CAP1188_CLK  13

// For I2C, connect SDA to your Arduino's SDA pin, SCL to SCL pin
// On UNO/Duemilanove/etc, SDA == Analog 4, SCL == Analog 5
// On Leonardo/Micro, SDA == Digital 2, SCL == Digital 3
// On Mega/ADK/Due, SDA == Digital 20, SCL == Digital 21

// Use I2C, no reset pin!
Adafruit_CAP1188 cap = Adafruit_CAP1188();


String myString;
//int cap = A0; // variable resistor connected 
//int sdata = 0; // The variable resistor value will be stored in sdata.

void setup()
{
  // Debug console
  Serial.begin(9600);

    Serial.println("CAP1188 test!");

  // Initialize the sensor, if using i2c you can pass in the i2c address
  // if (!cap.begin(0x28)) {
  if (!cap.begin()) {
    Serial.println("CAP1188 not found");
    while (1);
  }
  Serial.println("CAP1188 found!");


  // connect to wifi.
  //pinMode(D0,OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED)
      {
    Serial.print(".");
    delay(500);
      }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

   Firebase.setString("Variable/Value","start");
}

void loop()
{


myString = String(touched); 
Serial.println(myString); 
Firebase.setString("Variable/Value",myString);
delay(1000);            
}
