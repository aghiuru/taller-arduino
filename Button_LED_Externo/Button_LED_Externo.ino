int LED_EXTERNO = 12;
int PIN_BUTTON = 5;

void setup() {
  pinMode(LED_EXTERNO, OUTPUT);
  // Solo para botones, usamos el modo INPUT_PULLUP.
  pinMode(PIN_BUTTON, INPUT_PULLUP);
}

void loop() {
  // Usamos una variable para guardar el estado del boton.
  // Al estar dentro de un bloque, se llama variable local.
  // Se puede leer solo dentro del bloque en el que esta declarada.
  int button = digitalRead(PIN_BUTTON);
  
  digitalWrite(LED_EXTERNO, button);
  // digitalWrite(LED_EXTERNO, HIGH - button);
}
