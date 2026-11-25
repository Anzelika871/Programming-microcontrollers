void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long startTime;
  unsigned long endTime;
  startTime = micros();
  for (int i = 0; i < 100000; i++) {
    digitalWrite(13, HIGH);
    digitalWrite(13, LOW);
  }
  endTime = micros();
  unsigned long timeDigital = endTime - startTime;
  startTime = micros();
  for (int i = 0; i < 100000; i++) {
    PORTB = PORTB | 0b00100000; 
    PORTB = PORTB & 0b11011111; 
  }
  endTime = micros();
  unsigned long timeRegister = endTime - startTime;
  Serial.print("DigitalWrite: ");
  Serial.print(timeDigital);
  Serial.println(" us");
  Serial.print("Register:     ");
  Serial.print(timeRegister);
  Serial.println(" us");
  Serial.print("Разница (раз): ");
  Serial.println((float)timeDigital / timeRegister);
  delay(5000);
}
