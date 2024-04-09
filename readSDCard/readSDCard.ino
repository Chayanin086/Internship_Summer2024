#include <SPIFFS.h>

void setup() {
  Serial.begin(115200);
  if (!SPIFFS.begin(true)) {
    Serial.println("Failed to mount SPIFFS");
    return;
  }
  
  File file = SPIFFS.open("/testData.csv", "r");
  if (!file) {
    Serial.println("Failed to open file for reading");
    return;
  }
  
  while (file.available()) {
    String line = file.readStringUntil('\n');
    // Process the line here, e.g., split it into values and print them
    Serial.println(line);
  }

  file.close();
}

void loop() {
  // Your code here
}
