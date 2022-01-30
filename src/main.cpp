#include <Arduino.h>

#define TRIG_PIN 9
#define ECHO_PIN 10

void setup() {
  // put your setup code here, to run once:

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Pulse TRIG_PIN
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, LOW);

  // Check ECHO_PIN
  unsigned long duration;
  duration = pulseIn(ECHO_PIN, HIGH);
  unsigned long distanceInCm;
  unsigned long distanceInCmNew;
  distanceInCmNew = duration / 29 / 2;
  if (distanceInCmNew > 400) {
    // out of range, invalid data, don't use data
  }
  else {
    distanceInCm = distanceInCmNew;
  }

  Serial.println(distanceInCm);

  delay(100);
}