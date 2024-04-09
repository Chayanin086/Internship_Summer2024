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

int brightness = 0;
int brightnessIncrement = 10;

void setup() {
  pinMode(switchPinUp, INPUT);
  pinMode(switchPinDown, INPUT);
  pinMode(ledPin, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  if (digitalRead(switchPinUp) == LOW && brightness < 255) {
    brightness = brightness + brightnessIncrement;
    Blynk.virtualWrite(V0, brightness);
    delay(100);
    if(brightness > 255) {
      brightness = 255;
    }
  }

  if (digitalRead(switchPinDown) == LOW && brightness > 0) {
    brightness = brightness - brightnessIncrement;
    Blynk.virtualWrite(V0, brightness);
    delay(100);
    if (brightness < 0) {
      brightness = 0;
    }
  }

  analogWrite(ledPin, brightness);
}

BLYNK_WRITE(V1){
  brightness = brightness + brightnessIncrement;
  Blynk.virtualWrite(V0, brightness);
  delay(100);
    if(brightness > 255) {
      brightness = 255;
    }
  analogWrite (ledPin, brightness);
}

BLYNK_WRITE(V2){
  brightness = brightness - brightnessIncrement;
  Blynk.virtualWrite(V0, brightness);
  delay(100);
    if(brightness < 0) {
      brightness = 0;
    }
  analogWrite (ledPin, brightness);
}