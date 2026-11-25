int red = 11;
int yellow = 12;
int green = 13;

int tGreen = 5000;
int tBlink = 500;
int tYellow = 2000;
int tRed = 5000;
int tRedYellow = 2000;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  digitalWrite(green, HIGH);
  Serial.print("t=");
  Serial.print(millis());
  Serial.println(" ms phase=GREEN");
  delay(tGreen);
  digitalWrite(green, LOW);
  for (int i = 0; i < 3; i++) {
    digitalWrite(green, HIGH);
    Serial.print("t=");
    Serial.print(millis());
    Serial.println(" ms phase=GREEN_BLINK");
    delay(tBlink);
    digitalWrite(green, LOW);
    delay(tBlink);
  }
  digitalWrite(yellow, HIGH);
  Serial.print("t=");
  Serial.print(millis());
  Serial.println(" ms phase=YELLOW");
  delay(tYellow);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  Serial.print("t=");
  Serial.print(millis());
  Serial.println(" ms phase=RED");
  delay(tRed);
  digitalWrite(yellow, HIGH);
  Serial.print("t=");
  Serial.print(millis());
  Serial.println(" ms phase=RED_YELLOW");
  delay(tRedYellow);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
}
