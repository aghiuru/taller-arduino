// Para poder leer el valor de un potenciometro, tenemos que enchufarlo a una de las entradas analogicas.
int PIN_POT = A0;

// Hemos cambiado el pin del LED!
// Solo los PIN marcados con ~ (PWM) soportan escribir valores analogicos.
int LED_EXTERNO = 11;

void setup() {
  pinMode(LED_EXTERNO, OUTPUT);
  // El modo del potenciometro es INPUT en vez de INPUT_PULLUP (que se usa solo para botones).
  pinMode(PIN_POT, INPUT);
}

void loop() {
  // Para leer el valor del potenciometro "analogicamente", usamos la funcion analogRead().
  int pot = analogRead(PIN_POT);

  // digitalWrite solo escribe los valores 0 (LOW) y 1 (HIGH).
  // Para escribir un valor analogico (de 0 a 255) usamos analogWrite().
  // Asi podemos controlar el brillo del LED.
  analogWrite(LED_EXTERNO, pot);
  
  // analogRead() lee valores entre 0 y 1023.
  // analogWrite() escribe valores entre 0 y 255.
  // Para que el valor escrito sea entre 0 y 255, dividimos el valor leido entre 4.
//  analogWrite(LED_EXTERNO, pot / 4);

  // Podemos usar tambien la funcion map().
  // map() mapea un valor de un interval a otro.
  //int ledBright = map(pot, 0, 1023, 0, 255);
//  analogWrite(LED_EXTERNO, ledBright);

  // Podemos usar condiciones para que el LED cambie de comportamiento segun el valor leido.
  // Para eso usamos la funcion if().
  // En el caso de que la condicion es verdadera, se ejecuta el primer bloque.
  // En caso contrario, se ejecuta el bloque else().
//  if (pot > 512) {
//    digitalWrite(LED_EXTERNO, HIGH);
//  } else {
//    digitalWrite(LED_EXTERNO, HIGH);
//    delay(50);
//    digitalWrite(LED_EXTERNO, LOW);
//    delay(50);
//  }
}
