#include "FastLED.h"

#define NUM_LEDS 144
#define DATA_PIN 7
#define CLOCK_PIN 6

CRGB leds[NUM_LEDS];

int index;
int count;
int color;
int space;

void fade(){
    for(int i=0; i<NUM_LEDS; i++){
       leds[i].fadeToBlackBy( 4 );
    }
}

void setup() {
    // put your setup code here, to run once:
    FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
    for (int i=0; i<NUM_LEDS; i++) {
      leds[i] = CRGB::Black;
    }
    index=0;
    count=0;
}

void warm(int which) {
    leds[which] += CHSV(color,255,60);
}

void loop() {
    if(count%10 == 0){
        color = random(255);
        index = random(NUM_LEDS);
        space = random(7)-4;
    }
    warm(index);
    fade();
    //index = (NUM_LEDS+(index+space))%NUM_LEDS;
    FastLED.show();
    count++;
    delay(75);
}

