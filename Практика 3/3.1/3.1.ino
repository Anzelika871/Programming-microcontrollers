int vRed = 11;
int vYellow = 12;
int vGreen = 13;
int pRed = 10;
int pGreen = 9;
int buttonPin = 2;

void setup() {
  pinMode(vRed, OUTPUT);
  pinMode(vYellow, OUTPUT);
  pinMode(vGreen, OUTPUT);
  pinMode(pRed, OUTPUT);
  pinMode(pGreen, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(vGreen, HIGH);
  digitalWrite(pRed, HIGH);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    delay(50);
    digitalWrite(vGreen, LOW);
    for (int i = 0; i < 3; i++) {
      digitalWrite(vGreen, HIGH);
      delay(500);
      digitalWrite(vGreen, LOW);
      delay(500);
    }
    digitalWrite(vYellow, HIGH);
    delay(1500);
    digitalWrite(vYellow, LOW);
    digitalWrite(vRed, HIGH);
    digitalWrite(pRed, LOW);
    digitalWrite(pGreen, HIGH);
    delay(5000);
    for (int i = 0; i < 3; i++) {
      digitalWrite(pGreen, HIGH);
      delay(500);
      digitalWrite(pGreen, LOW);
      delay(500);
    }
    digitalWrite(vRed, LOW);
    digitalWrite(pGreen, LOW);
    digitalWrite(pRed, HIGH);
    digitalWrite(vGreen, HIGH);
  }
}
