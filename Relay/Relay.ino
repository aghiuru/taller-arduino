int PIN_RELAY = 12;

void setup() {
  pinMode(PIN_RELAY, OUTPUT);  
}

void loop() {
  digitalWrite(PIN_RELAY, HIGH);
  delay(5000);
  digitalWrite(PIN_RELAY, LOW);
  delay(5000);
}
