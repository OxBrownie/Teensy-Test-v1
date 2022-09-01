#include <Arduino.h>
#include <SD.h> // SD card
#include <SPI.h> // SPI

// Initalise
volatile byte state = LOW;

// Interrupts
void blink() {
  state = !state;
}


void setup() {
  // Internal LED
  pinMode(LED_BUILTIN, OUTPUT);

  // Buzzer
  // analogWriteFrequency(4, 2000);
  pinMode(4, OUTPUT); // Set buzzer - pin 9 as an output

  // Serial
  Serial.begin(9600);
  SD.begin(BUILTIN_SDCARD);

  // Button
  pinMode(24, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(24), blink, CHANGE);
}

void loop() {
  // LED flash
  // digitalWrite(LED_BUILTIN, HIGH);
  // delay(250m);
  // digitalWrite(LED_BUILTIN, LOW);
  // delay(250);

  // Serial write
  Serial.println("URT sucks");

  // buzzer
  // digitalWrite(4, HIGH);
  // delay(500);
  // digitalWrite(4, LOW);

  // button
  digitalWrite(LED_BUILTIN, state);

  // IMU SPI

}


