int ledPin = 13;
int buttonPin = 2;

bool ledState = false;
bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
int pressCount = 0; 

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  bool reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading == LOW && lastButtonState == HIGH) { 
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
      pressCount++;
      Serial.print("Нажатий: ");
      Serial.println(pressCount);
    }
  }
  lastButtonState = reading;
}
