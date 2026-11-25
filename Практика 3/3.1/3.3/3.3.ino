int led1 = 12;
int led2 = 13;
int buttonPin = 2;
unsigned long pressStartTime = 0;
bool isPressed = false;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  bool btnState = digitalRead(buttonPin);
  if (btnState == LOW && !isPressed) {
    isPressed = true;
    pressStartTime = millis();
    delay(20);
  }
  if (btnState == HIGH && isPressed) {
    isPressed = false;
    unsigned long pressDuration = millis() - pressStartTime;

    if (pressDuration < 500) {
      digitalWrite(led1, !digitalRead(led1));
    } 
    else if (pressDuration > 1000) {
      digitalWrite(led2, HIGH);
      delay(3000);
      digitalWrite(led2, LOW);
    }
  }
}
