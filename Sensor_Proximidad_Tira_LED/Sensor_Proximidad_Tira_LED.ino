#include <Adafruit_NeoPixel.h>

int PIN_LED_STRIP = 1;
int STRIP_SIZE = 30;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(STRIP_SIZE, PIN_LED_STRIP, NEO_GRB + NEO_KHZ800);

int PIN_ECHO = 2;
int PIN_TRIG = 3;


void setup() {
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  strip.begin();
  strip.setBrightness(25);  // Lower brightness and save eyeballs!
  strip.show(); // Initialize all pixels to 'off'

}

// El codigo para leer distancia es mas complicado.
// Lo que hace es emitir un ultrasonido y captar el reflejo.
// Sacamos el codigo en una funcion para que el loop() sea mas facil de entender.
int readDistance() {
  // Clears the trigPin condition
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  int duration = pulseIn(PIN_ECHO, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}

void loop() {  
  int distance = readDistance();

  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Si hay algo mas cerca de 50 cm, empezar encender el LED.
  int maxDistance = 50;
  
  if (distance < maxDistance) {
    int ledsOn = map(distance, 0, maxDistance, STRIP_SIZE, 0);
  
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
  }
  
  strip.show();
  delay(20);
}
