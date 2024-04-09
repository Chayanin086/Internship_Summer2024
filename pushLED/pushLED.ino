const int switchPinUp = 2;
const int switchPinDown = 3;
const int ledPin = 9;

int brightness = 0;
int brightnessIncrement = 32;

void setup() {
  pinMode(switchPinUp, INPUT);
  pinMode(switchPinDown, INPUT); 
  pinMode(ledPin, OUTPUT);              
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(switchPinUp) == LOW && brightness < 255) {
    brightness = brightness + brightnessIncrement;
    delay(100);
    if (brightness > 255) {
      brightness = 255;
    }
  }

  if (digitalRead(switchPinDown) == LOW && brightness > 0) {
    brightness = brightness - brightnessIncrement;
    delay(100);
    if (brightness < 0) {
      brightness = 0;
    }
  }

  analogWrite(ledPin, brightness);
  Serial.println(brightness);
}