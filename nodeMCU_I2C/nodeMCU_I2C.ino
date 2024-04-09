#include <Wire.h>
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>

#define BLYNK_PRINT Serial
#define ESP8266_BAUD 9600

#define BLYNK_TEMPLATE_ID "TMPL6K6eLRXDW"
#define BLYNK_TEMPLATE_NAME "brightnessLED"

#define SWITCH_V3 V3
#define SWITCH_V4 V4
#define SWITCH_V0 V0

char auth[] =  "KHfQR_QrZxpynJn2n-LbkzO8SCDMpOqg";

char ssid[] = "G";
char pass[] = "123654789";

bool modeRunning = false; // Variable to track if LED mode is running
int currentMode = 0; // Variable to store the current LED mode

void setup() {
  Blynk.begin(auth, ssid, pass);

  Blynk.virtualWrite(V3, 0);
  Blynk.virtualWrite(V4, 0);
  Blynk.virtualWrite(V0, 0);

  pinMode(9, INPUT);
  pinMode(10, OUTPUT);

  Wire.begin();

  Serial.begin(9600); // Hardware Serial ที่แสดงออกหน้าจอ Serial Monitor
}

void loop() {
  Blynk.run();
  // No need to read virtual pin state here, as it's handled by BLYNK_WRITE
  delay(100); // Adjust delay as needed
}

BLYNK_WRITE(SWITCH_V3) {
  int switchState = param.asInt();
  if (switchState == 1) {
    char command = '1';
    Wire.beginTransmission(9); // Address of Arduino Mega 2560
    Wire.write(command); // Command to start LED loop
    Serial.println(command);
    Wire.endTransmission();
  } else {
    char command = '0';
    Wire.beginTransmission(9); // Address of Arduino Mega 2560
    Wire.write(command); // Command to start LED loop
    Serial.println(command);
    Wire.endTransmission();
  }
}

BLYNK_WRITE(SWITCH_V4) {
  int switchState = param.asInt();
  if (switchState == 1) {
    char command = '2';
    Wire.beginTransmission(9); // Address of Arduino Mega 2560
    Wire.write(command); // Command to start LED loop
    Serial.println(command);
    Wire.endTransmission();
  } else {
    char command = '0';
    Wire.beginTransmission(9); // Address of Arduino Mega 2560
    Wire.write(command); // Command to start LED loop
    Serial.println(command);
    Wire.endTransmission();
  }
}

BLYNK_WRITE(SWITCH_V0) {
  int switchState = param.asInt();
  if (switchState == 1) {
    char command = '3';
    Wire.beginTransmission(9); // Address of Arduino Mega 2560
    Wire.write(command); // Command to start LED loop
    Serial.println(command);
    Wire.endTransmission();
  } else {
    char command = '0';
    Wire.beginTransmission(9); // Address of Arduino Mega 2560
    Wire.write(command); // Command to start LED loop
    Serial.println(command);
    Wire.endTransmission();
  }
}