const int ledPins[] = { 3, 5, 6, 9, 10 };
int pinsCount = 5;
int ledStates[] = { HIGH, HIGH, HIGH, HIGH, HIGH };

unsigned long previousMicros[] = { 0, 0, 0, 0, 0 };

unsigned long interval[] = { 10000, 1000, 500, 100, 50 };

void setup() {
  for (int thisPin = 0; thisPin < pinsCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }
}

void loop() {

  unsigned long currentMicros = micros();

  for (int thisPin = 0; thisPin < pinsCount; thisPin++) {
    if (currentMicros - previousMicros[thisPin] >= interval[thisPin]) {

      previousMicros[thisPin] = currentMicros;

      if (ledStates[thisPin] == LOW) {
        ledStates[thisPin] = HIGH;
      } else {
        ledStates[thisPin] = LOW;
      }

      digitalWrite(ledPins[thisPin], ledStates[thisPin]);
    }
  }
}