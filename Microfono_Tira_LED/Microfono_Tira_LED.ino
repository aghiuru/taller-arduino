#include <Adafruit_NeoPixel.h>

int PIN_LED_STRIP = 1;
int STRIP_SIZE = 30;

int PIN_POT = A0;
int PIN_MIC = A1;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(STRIP_SIZE, PIN_LED_STRIP, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(PIN_MIC, INPUT);
  pinMode(PIN_POT, INPUT);

  strip.begin();
  strip.setBrightness(25);  // Lower brightness and save eyeballs!
  strip.show(); // Initialize all pixels to 'off'
}

long maxVal = 0;

void loop() {
  int volume = analogRead(PIN_MIC);
  int minVal = analogRead(PIN_POT);

  if (maxVal < volume) maxVal = volume;

  int ledsOn = map(volume, minVal, maxVal, 0, STRIP_SIZE);

  if (ledsOn > 0 && ledsOn < STRIP_SIZE) {
    for (int i = 0; i < STRIP_SIZE; i++) {
      if (i < ledsOn) {
        strip.setPixelColor(i, strip.Color(255, 0, 0));
      }
      else {
        strip.setPixelColor(i, strip.Color(0, 0, 0));
      }
    }
  } else {
    for (int i = 0; i < STRIP_SIZE; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0));
    }
  }
  strip.show();
  
  delay(20);
}
