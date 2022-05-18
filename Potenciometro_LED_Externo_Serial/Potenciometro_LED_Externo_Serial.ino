int PIN_POT = A0;
int LED_EXTERNO = 11;

void setup() {
  pinMode(LED_EXTERNO, OUTPUT);
  pinMode(PIN_POT, INPUT);

  // Inicializamos la conexion serial.
  // 9600 es la tasa de velocidad de la conexion.
  Serial.begin(9600);
}

void loop() {
  int pot = analogRead(PIN_POT);
  
  int ledBright = map(pot, 0, 1023, 0, 255);
  analogWrite(LED_EXTERNO, ledBright);

  // Escribimos lo que queremos mandar al ordenador.
  Serial.print("Valor leido: ");
  // No podemos escribir datos de tipos diferentes en la misma funcion.
  // Por eso usamos intrucciones diferentes para texto y numeros.
  Serial.print(pot);
  Serial.print(" Valor por escribir: ");
  Serial.print(ledBright);
  // Serial.print() anade caracteres a un tampon.
  // Serial.println() (de print"Line") manda el tampon al ordenador.
  Serial.println();

  delay(50);
}
