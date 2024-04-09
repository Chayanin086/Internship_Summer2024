#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>

#define BLYNK_PRINT Serial 
#define ESP8266_BAUD 115200

#define BLYNK_TEMPLATE_ID "TMPL6K6eLRXDW"
#define BLYNK_TEMPLATE_NAME "brightnessLED"

char auth[] =  "KHfQR_QrZxpynJn2n-LbkzO8SCDMpOqg";

char ssid[] = "G";
char pass[] = "123654789";

const int ledPin = D1;
const int switchPinUp = D2;
const int switchPinDown = D3;

const int ledIPin = D5;
const int ledIIPin = D6;
const int ledIIIPin = D7;
const int ledIVPin = D8;

int brightness = 0;
int brightnessIncrement = 10;

bool modeRunning = false;
int currentMode = 0;

void setup() {
  pinMode(switchPinUp, INPUT);
  pinMode(switchPinDown, INPUT);
  pinMode(ledPin, OUTPUT);

  Blynk.begin(auth, ssid, pass);

  pinMode(ledIPin, OUTPUT);
  pinMode(ledIIPin, OUTPUT);
  pinMode(ledIIIPin, OUTPUT);
  pinMode(ledIVPin, OUTPUT);

  Blynk.virtualWrite(V3, 0);
  Blynk.virtualWrite(V4, 0);
  Blynk.virtualWrite(V0, 0);
}

void loop() {
  Blynk.run();
  if (digitalRead(switchPinUp) == LOW && brightness < 255) {
    brightness = brightness + brightnessIncrement;
    // Blynk.virtualWrite(V0, brightness);
    delay(100);
    if(brightness > 255) {
      brightness = 255;
    }
  }

  if (digitalRead(switchPinDown) == LOW && brightness > 0) {
    brightness = brightness - brightnessIncrement;
    // Blynk.virtualWrite(V0, brightness);
    delay(100);
    if (brightness < 0) {
      brightness = 0;
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
        // If an unknown mode is selected, stop the mode
        modeRunning = false;
        break;
    }
  }

  analogWrite(ledPin, brightness);
}

BLYNK_WRITE(V1){
  brightness = brightness + brightnessIncrement;
  // Blynk.virtualWrite(V0, brightness);
  delay(100);
    if(brightness > 255) {
      brightness = 255;
    }
  analogWrite (ledPin, brightness);
}

BLYNK_WRITE(V2){
  brightness = brightness - brightnessIncrement;
  // Blynk.virtualWrite(V0, brightness);
  delay(100);
    if(brightness < 0) {
      brightness = 0;
    }
  analogWrite (ledPin, brightness);
}

//modeI
void modeI() {
  digitalWrite(ledIPin, HIGH);
  delay(100);
  digitalWrite(ledIPin, LOW);
  delay(100);
  digitalWrite(ledIIPin, HIGH);
  delay(100);
  digitalWrite(ledIIPin, LOW);
  delay(100);
  digitalWrite(ledIIIPin, HIGH);
  delay(100);
  digitalWrite(ledIIIPin, LOW);
  delay(100);
  digitalWrite(ledIVPin, HIGH);
  delay(100);
  digitalWrite(ledIVPin, LOW);
  delay(100);
}

//modeII
void modeII() {
  digitalWrite(ledIVPin, HIGH);
  delay(100);
  digitalWrite(ledIVPin, LOW);
  delay(100);
  digitalWrite(ledIIIPin, HIGH);
  delay(100);
  digitalWrite(ledIIIPin, LOW);
  delay(100);
  digitalWrite(ledIIPin, HIGH);
  delay(100);
  digitalWrite(ledIIPin, LOW);
  delay(100);
  digitalWrite(ledIPin, HIGH);
  delay(100);
  digitalWrite(ledIPin, LOW);
  delay(100);
}

//modeIII
void modeIII() {
  digitalWrite(ledIPin, HIGH);
  delay(100);
  digitalWrite(ledIIPin, HIGH);
  delay(100);
  digitalWrite(ledIIIPin, HIGH);
  delay(100);
  digitalWrite(ledIVPin, HIGH);
  delay(100);
  digitalWrite(ledIVPin, LOW);
  delay(100);
  digitalWrite(ledIIIPin, LOW);
  delay(100);
  digitalWrite(ledIIPin, LOW);
  delay(100);
  digitalWrite(ledIPin, LOW);
  delay(100);
}

BLYNK_WRITE(V3) {
  if (param.asInt() == 1) {
    currentMode = 1;
    modeRunning = true;
  } else {
    modeRunning = false;
  }
}

BLYNK_WRITE(V4) {
  if (param.asInt() == 1) {
    currentMode = 2;
    modeRunning = true;
  } else {
    modeRunning = false;
  }
}

BLYNK_WRITE(V0) {
  if (param.asInt() == 1) {
    currentMode = 3;
    modeRunning = true;
  } else {
    modeRunning = false;
  }
}