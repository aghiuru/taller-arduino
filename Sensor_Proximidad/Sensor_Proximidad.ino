int PIN_ECHO = 2;
int PIN_TRIG = 3;

int PIN_LED = 11;

void setup() {
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  pinMode(PIN_LED, OUTPUT);

  Serial.begin(9600);
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
    int ledBright = map(distance, 0, maxDistance, 255, 0);
    analogWrite(PIN_LED, ledBright);
  } else {
    digitalWrite(PIN_LED, LOW);
  }
}
