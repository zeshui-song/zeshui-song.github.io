#include <Arduino.h>
#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

#define BUTTON1_PIN 4
#define BUTTON2_PIN 5

bool prevButton1State = HIGH;
bool prevButton2State = HIGH;

HX711 scale;

unsigned long lastScaleReadTime = 0;
const unsigned long scaleInterval = 2000; // 0.5 Hz = one reading every 2000 ms

bool displayInGrams = true;  // toggle state

void setup() {
  Serial.begin(57600);
  Serial.println("Initializing the scale");

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  scale.set_scale(171.983);  // Calibration factor for grams
  scale.tare();             // Set tare to 0

  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
}

void loop() {
  unsigned long currentTime = millis();

  // --- Button Handling ---
  bool button1State = digitalRead(BUTTON1_PIN);
  bool button2State = digitalRead(BUTTON2_PIN);

  // Button 1: Tare
  if (button1State == LOW && prevButton1State == HIGH) {
    Serial.println("Button 1 pressed — Taring scale...");
    scale.tare();
    Serial.println("Scale tared.");
  }

  // Button 2: Toggle units
  if (button2State == LOW && prevButton2State == HIGH) {
    displayInGrams = !displayInGrams;
    Serial.print("Now displaying in ");
    Serial.println(displayInGrams ? "grams (g)" : "ounces (oz)");
  }

  prevButton1State = button1State;
  prevButton2State = button2State;

  // --- Scale Reading ---
  if (currentTime - lastScaleReadTime >= scaleInterval) {
    lastScaleReadTime = currentTime;

    float grams = scale.get_units(10);

    if (displayInGrams) {
      Serial.print("Weight: ");
      Serial.print(grams, 2);
      Serial.println(" g");
    } else {
      float ounces = grams / 28.3495;
      Serial.print("Weight: ");
      Serial.print(ounces, 2);
      Serial.println(" oz");
    }
  }
}
