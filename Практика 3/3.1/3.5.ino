int greenLed = 12;
int redLed = 11;
int yellowLed = 10;
String correctCode = "1234";
String inputCode = "";
int errorCount = 0;

void setup() {
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char key = readKeypad(); 
  if (key == '#') {
    if (inputCode == correctCode) {
      digitalWrite(greenLed, HIGH);
      delay(3000);
      digitalWrite(greenLed, LOW);
      errorCount = 0; 
    } else {
      digitalWrite(redLed, HIGH);
      delay(3000);
      digitalWrite(redLed, LOW);
      errorCount++;
      if (errorCount >= 3) {
        delay(10000); 
        errorCount = 0;
      }
    }
    inputCode = "";
  } 
  else if (key == '*') {
    inputCode = "";
  } 
  else if (key >= '0' && key <= '9') {
    inputCode += key;
    digitalWrite(yellowLed, HIGH);
    delay(100);
    digitalWrite(yellowLed, LOW);
  }
}
char readKeypad() {
  return '\0'; 
}
