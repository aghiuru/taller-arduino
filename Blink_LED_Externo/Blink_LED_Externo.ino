// Asi declaramos una variable.
// Pensad en ella como en una caja denominada LED_EXTERNO donde guardamos el numero 12.
// El compilador va a reemplazar LED_EXTERNO por 12 donde la encuentre.
// Una variable de tipo int puede guardar valores entre -32768 y 32767.
// Al estar declarada fuera de los bloques setup() y loop(), se llama variable global.
int LED_EXTERNO = 12;

void setup() {
  pinMode(LED_EXTERNO, OUTPUT);
}

void loop() {
  digitalWrite(LED_EXTERNO, HIGH);
  delay(500);
  digitalWrite(LED_EXTERNO, LOW);
  delay(500);
}
