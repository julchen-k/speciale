#include <FastLED.h>

#define LED_PIN 14
#define COLOR_ORDER GRB
#define LED_TYPE    WS2811
#define NUM_LEDS    4

#define BRIGHTNESS          96
#define FRAMES_PER_SECOND  120

CRGB leds[NUM_LEDS];
bool pulsating = false;

uint8_t gHue = 0; // rotating "base color" used by many of the patterns
uint8_t red = 0;
uint8_t orange = 32;
uint8_t yellow = 64;
uint8_t green = 96;
uint8_t aqua = 128;
uint8_t blue = 160;
uint8_t purple = 192;
uint8_t pink = 224;

CHSV white (100,0,255);

void setup() {
  delay(3000); // 3 second delay for recovery
  FastLED.addLeds<LED_TYPE,LED_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();

}


void loop() 
{
lightOn();
delay(3000);
lightOff();
delay(2000);
setBlue();
pulsating = true;
delay(3000);
pulsate();
delay(10000);
pulsating = false;
lightOn();
delay(1000);
setPurple();
delay(1000);
lightOff();
delay(1000);
}



void animation() //makes a dot circle around in the color chosen
{
  fadeToBlackBy( leds, NUM_LEDS, 20);
  //for (int i = 0; i < NUM_LEDS; i++){
  int pos = beatsin16( 60, 0, NUM_LEDS-1 );
  leds[pos] += CHSV( aqua, 255, 192);
  //}

}

void pulsate(){
  bool pulsateCheck = pulsating;
  while(pulsateCheck == true)
  {
    for (int i=0; i<=BRIGHTNESS; i++)
    {
      FastLED.setBrightness(i);
      FastLED.show();
      delay(10);
    }
    delay(500);

    for (int i=BRIGHTNESS; i>=0; i--)
    {
      FastLED.setBrightness(i);
      FastLED.show();
      delay(10);
    }
    //exit the while when the pulsating is supposed to stop
    if(pulsating == false)
    {
        break;
    }
    pulsateCheck = pulsating;
  }

  
}


void anim(){
  
  leds[1].fadeToBlackBy(200);
}

void lightOn()
{
  for (int i=0; i<=NUM_LEDS; i++)
  {
    leds[i] = CRGB::White;
  }
  FastLED.show();
}

void lightOff()
{
  FastLED.clear();  
  FastLED.show();
}

void setBlue()
{
  for (int i=0; i<=NUM_LEDS; i++)
  {
  leds[i] = CRGB::Blue;  
  }
  FastLED.show();
}

void setPurple()
{
  for (int i=0; i<=NUM_LEDS; i++)
  {
  leds[i] = CRGB::Purple;  
  }
  FastLED.show();
}