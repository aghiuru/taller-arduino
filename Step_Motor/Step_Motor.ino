int PIN_BUTTON_L = 3;
int PIN_BUTTON_R = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  pinMode(PIN_BUTTON_L, INPUT_PULLUP);
  pinMode(PIN_BUTTON_R, INPUT_PULLUP);
}

static int rotating = 0;

void stepL() {
    digitalWrite(9,  rotating % 4==0 ? HIGH : LOW);
    digitalWrite(10, rotating % 4==1 ? HIGH : LOW);
    digitalWrite(11, rotating % 4==2 ? HIGH : LOW);
    digitalWrite(12, rotating % 4==3 ? HIGH : LOW);   
}

void stepR() {
    digitalWrite(9,  rotating % 4==-3 ? HIGH : LOW);
    digitalWrite(10, rotating % 4==-2 ? HIGH : LOW);
    digitalWrite(11, rotating % 4==-1 ? HIGH : LOW);
    digitalWrite(12, rotating % 4==0 ? HIGH : LOW);   
}

void loop() {
  int buttonPressedL = !digitalRead(PIN_BUTTON_L);
  int buttonPressedR = !digitalRead(PIN_BUTTON_R);

  if (rotating == 0 && buttonPressedL) {
    rotating = 1;
  }
  if (rotating == 0 && buttonPressedR) {
    rotating = -1;
  }
  
  if (rotating > 0) {
    stepL();
    rotating++;
  }

  if (rotating < 0) {
    stepR();
    rotating--;
  }

  delay(2);
  
  if (rotating == 1024 || rotating == -1024) {
    rotating = 0;
  }
}
