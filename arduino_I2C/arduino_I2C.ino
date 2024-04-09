#include <Wire.h>

int ledI = 10;
int ledII = 11;
int ledIII = 12;
int ledIV = 13;
int currentMode = 0;
bool modeRunning = false;

void setup() {
  pinMode(0, INPUT);
  pinMode(1, OUTPUT);

  pinMode(ledI, OUTPUT);
  pinMode(ledII, OUTPUT);
  pinMode(ledII, OUTPUT);
  pinMode(ledIV, OUTPUT);

  Wire.begin(9);                // Start I2C communication as a slave with address 9
  Wire.onReceive(receiveEvent); // Register receiveEvent function
  Serial.begin(9600);   // เริ่มต้นการเชื่อมต่อ Serial กับคอมพิวเตอร์
}

void loop() {
  if (Serial.available() > 0) {
    char receivedChar = Serial.read();
    if (receivedChar != ' ' && receivedChar != '\t' && receivedChar != '\n' && receivedChar != '\r') {
      int mode = receivedChar - '0'; // Convert char to integer
      
      switch (mode) {
        case 1:
          currentMode = 1;
          modeRunning = true;
          break;
        case 2:
          currentMode = 2;
          modeRunning = true;
          break;
        case 3:
          currentMode = 3;
          modeRunning = true;
          break;
        default:
          currentMode = 0; // Stop all modes if an unknown mode is selected
          modeRunning = false;
          break;
      }
    }
  }

  if (modeRunning) {
    switch (currentMode) {
      case 1:
        modeI();
        break;
      case 2:
        modeII();
        break;
      case 3:
        modeIII();
        break;
      default:
        stopModes();
        break;
    }
  }
}

void receiveEvent(int bytes) {
  while (Wire.available() > 0) {
    char receivedChar = Wire.read();
    switch (receivedChar) {
      case '1':
        currentMode = 1; // Set current mode to 1
        modeRunning = true; // Start LED loop
        break;
      case '2':
        currentMode = 2; // Set current mode to 2
        modeRunning = true; // Start LED loop
        break;
      case '3':
        currentMode = 3; // Set current mode to 3
        modeRunning = true; // Start LED loop
        break;
      case '0':
        currentMode = 0; // Stop all modes
        modeRunning = false; // Stop LED loop
        break;
    }
  Serial.println(receivedChar);
  }
}

void modeI() {
  digitalWrite(ledI, HIGH);
  delay(100);
  digitalWrite(ledI, LOW);
  delay(100);
  digitalWrite(ledII, HIGH);
  delay(100);
  digitalWrite(ledII, LOW);
  delay(100);
  digitalWrite(ledIII, HIGH);
  delay(100);
  digitalWrite(ledIII, LOW);
  delay(100);
  digitalWrite(ledIV, HIGH);
  delay(100);
  digitalWrite(ledIV, LOW);
  delay(100);
}

void modeII() {
  digitalWrite(ledIV, HIGH);
  delay(100);
  digitalWrite(ledIV, LOW);
  delay(100);
  digitalWrite(ledIII, HIGH);
  delay(100);
  digitalWrite(ledIII, LOW);
  delay(100);
  digitalWrite(ledII, HIGH);
  delay(100);
  digitalWrite(ledII, LOW);
  delay(100);
  digitalWrite(ledI, HIGH);
  delay(100);
  digitalWrite(ledI, LOW);
  delay(100);
}

void modeIII() {
  digitalWrite(ledI, HIGH);
  delay(100);
  digitalWrite(ledII, HIGH);
  delay(100);
  digitalWrite(ledIII, HIGH);
  delay(100);
  digitalWrite(ledIV, HIGH);
  delay(100);
  digitalWrite(ledIV, LOW);
  delay(100);
  digitalWrite(ledIII, LOW);
  delay(100);
  digitalWrite(ledII, LOW);
  delay(100);
  digitalWrite(ledI, LOW);
  delay(100);
}

void stopModes() {
  digitalWrite(ledI, LOW);
  digitalWrite(ledII, LOW);
  digitalWrite(ledIII, LOW);
  digitalWrite(ledIV, LOW);
}