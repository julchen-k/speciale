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

bool currentTouch = false; //pushed to Firebase, indicating whether the person is touching right NOW
bool sentTouch = false; //pushed to Firebase, indicating whether the person sent a touch

Adafruit_CAP1188 cap = Adafruit_CAP1188();


//Here comes all the LED stuff
#include <FastLED.h>

#define LED_PIN 14
#define COLOR_ORDER GRB
#define LED_TYPE    WS2811
#define NUM_LEDS    4

#define BRIGHTNESS          96
#define FRAMES_PER_SECOND  120

CRGB leds[NUM_LEDS];

//Here comes the buzzer
#define buzzer 13

void setup() {

  //BUZZER SETUP
  pinMode(buzzer, OUTPUT);

  //LED SETUP
  delay(3000); // 3 second delay for recovery
  FastLED.addLeds<LED_TYPE,LED_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();

  //CAP SETUP
  Serial.begin(9600);
  Serial.println("CAP1188 test!");

  // Initialize the sensor, if using i2c you can pass in the i2c address
  // if (!cap.begin(0x28)) {
  if (!cap.begin()) {
    Serial.println("CAP1188 not found");
    while (1);
  }
  Serial.println("CAP1188 found!");

 
}

void loop() {
  uint8_t touched = cap.touched();

  if (touched == 0) 
  {
    // No touch detected
    currentTouch = false;
    Serial.println(currentTouch);
    //return;
  }

    //When touch is detected
    for (uint8_t i=0; i<8; i++) 
    {
        if (touched & (1 << i)) 
        {
          Serial.print("C"); Serial.print(i+1); Serial.print("\t");
          currentTouch = true;
          sentTouch = true;
        }
    }
    Serial.println();
    delay(50);
}



void animCall(){

  for (int i=0; i<=NUM_LEDS; i++){
    leds[i] = CRGB::Purple;
  }
  
  for (int i=0; i<=BRIGHTNESS; i++){
    FastLED.setBrightness(i);
    FastLED.show();
    delay(10);
  }
  delay(500);

    for (int i=BRIGHTNESS; i>=0; i--){
    FastLED.setBrightness(i);
    FastLED.show();
    delay(10);
  }
}


void anim(){
  
  leds[1].fadeToBlackBy(200);
}

