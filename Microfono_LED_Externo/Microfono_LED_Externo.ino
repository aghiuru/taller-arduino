int LED_OUT = 11;

int PIN_POT = A0;
int PIN_MIC = A1;

long maxVal = 0;

void setup() {
  pinMode(LED_OUT, OUTPUT);
  pinMode(PIN_MIC, INPUT);
  pinMode(PIN_POT, INPUT);
  
  Serial.begin(9600);
}
void loop() {
  int volume = analogRead(PIN_MIC);
  // Leemos el baseline del potenciometro.
  int minVal = analogRead(PIN_POT);

  // Guardamos el valor maximo del sonido.
  if (maxVal < volume) maxVal = volume;

  // Mapeamos el brillo del LED entre el valor del potenciometro y el volumen maximo detectado.
  int ledBright = map(volume, minVal, maxVal, 0, 255);
  
  Serial.print("Min: ");
  Serial.print(minVal);
  Serial.print(" Max: ");
  Serial.print(maxVal);
  Serial.print(" Reading: ");
  Serial.print(volume);
  Serial.print(" Map: ");  
  Serial.println(ledBright);

  // Escribimos el valor del LED solo si esta entre 0 y 255.
  if (ledBright >= 0 && ledBright < 256) {
    analogWrite(LED_OUT, ledBright);
  } else {
    digitalWrite(LED_OUT, LOW);
  }
  
  delay(10);
}
