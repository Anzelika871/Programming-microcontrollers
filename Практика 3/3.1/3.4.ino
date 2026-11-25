int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int buttonPin = 8;
int mode = 0;
int lastBtnState = HIGH;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int btnState = digitalRead(buttonPin);
  if (btnState == LOW && lastBtnState == HIGH) {
    mode++;
    if (mode > 2) mode = 0;

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    delay(200);
  }
  lastBtnState = btnState;

  if (mode == 0)      effectRunner();
  else if (mode == 1) effectBlinkAll();
  else if (mode == 2) effectFill();
}

void effectRunner() {
  digitalWrite(led1, HIGH); delay(100); digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH); delay(100); digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH); delay(100); digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH); delay(100); digitalWrite(led4, LOW);
  digitalWrite(led5, HIGH); delay(100); digitalWrite(led5, LOW);
  digitalWrite(led6, HIGH); delay(100); digitalWrite(led6, LOW);
}

void effectBlinkAll() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  delay(300);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  delay(300);
}

void effectFill() {
  digitalWrite(led1, HIGH); delay(100);
  digitalWrite(led2, HIGH); delay(100);
  digitalWrite(led3, HIGH); delay(100);
  digitalWrite(led4, HIGH); delay(100);
  digitalWrite(led5, HIGH); delay(100);
  digitalWrite(led6, HIGH); delay(100);
  delay(300);

  digitalWrite(led6, LOW); delay(100);
  digitalWrite(led5, LOW); delay(100);
  digitalWrite(led4, LOW); delay(100);
  digitalWrite(led3, LOW); delay(100);
  digitalWrite(led2, LOW); delay(100);
  digitalWrite(led1, LOW); delay(100);
}
