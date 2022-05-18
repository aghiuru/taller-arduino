int PIN_MOTION_SENSOR = 11;
int PIN_LEN = 13;

void setup() {
  pinMode(PIN_MOTION_SENSOR, INPUT);
  pinMode(PIN_LEN, OUTPUT);
  
  Serial.begin(9600);
  
  delay(20000);
}

void loop() {
  int reading = digitalRead(PIN_MOTION_SENSOR);

  digitalWrite(PIN_LEN, reading);
  
  Serial.println(reading);
  
  delay(20);
}
