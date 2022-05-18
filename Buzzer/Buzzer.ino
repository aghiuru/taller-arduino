int buzzerPin = 3;

void setup() {
  pinMode(buzzerPin, OUTPUT); //Set buzzerPin as output
}

void loop() {
  analogWrite(buzzerPin, LOW); //Beep every 500 milliseconds
  delay(500); 
  digitalWrite(buzzerPin, HIGH); //Beep every 500 milliseconds
  delay(500);
}
