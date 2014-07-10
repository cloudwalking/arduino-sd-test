#include <SD.h>

File file;

void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  if (!SD.begin(8)) {
    Serial.println(F("cound't start SD"));
  }
}

void loop() {
  file = SD.open("hello.txt");
  if (file) {
    while (file.available()) {
      Serial.write(file.read());
    }
    Serial.println();
    file.close();
  } else {
    Serial.println(F("error opening file"));
  }
  delay(1000);
}