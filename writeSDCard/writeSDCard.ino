#include <SD.h>
#include <SPI.h>

File file;

void setup() {
  Serial.begin(115200);
  
  // Initialize SD card
  if (!SD.begin()) {
    Serial.println("SD card initialization failed");
    return;
  }
  
  Serial.println("Type your name, surname, age, birthdate, phone and press Enter:");
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n'); // Read a line from Serial Monitor
    
    // Open file in append mode
    file = SD.open("/testData.csv", FILE_APPEND);
    if (!file) {
      Serial.println("Failed to open file for writing");
      return;
    }
    
    // If file is not empty, add a newline before writing new data
    if (file.size() > 0) {
      file.println();
    }
    
    // Write data to the file
    file.print(data);
    file.close(); // Close the file
    
    Serial.println("Data written to file successfully!");
  }
}
