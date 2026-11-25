int sensorPin = 2;
int greenLed = 12;
int redLed = 13;
unsigned long changeTime = 0; 
int lastState = HIGH;
int switchCount = 0;

void setup() {
  pinMode(sensorPin, INPUT_PULLUP);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int currentState = digitalRead(sensorPin);
  if (currentState != lastState) {
    changeTime = millis();
    switchCount++;
    lastState = currentState;
  }
  unsigned long duration = millis() - changeTime;
  if (switchCount > 5) {
    Serial.println("Вибрация!");
    for(int i=0; i<4; i++) {
      digitalWrite(redLed, HIGH);
      delay(250);
      digitalWrite(redLed, LOW);
      delay(250);
    }
    switchCount = 0;
  } 
  else if (currentState == LOW && duration > 300) {
    digitalWrite(greenLed, HIGH);
    Serial.println("Наклон!");
  } 
  else {
    if (duration > 500) digitalWrite(greenLed, LOW);
  }
  if (duration > 1000) {
    switchCount = 0; 
  }
}
