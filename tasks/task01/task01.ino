const int ledPins[] = {3, 5, 6, 9, 10};

int pinsCount = 5;

int ledStates[] = {HIGH, HIGH, HIGH, HIGH, HIGH};

unsigned long previousMillisOrMicros[] = {0, 0, 0, 0, 0};  

const long interval_10ml = 10; // 10 milli
const long interval_1ml = 1; // 1 milli
const long interval_500mc = 500; // 500 micro
const long interval_100mc = 100;  // 100 micro
const long interval_50mc = 50;  // 50 micro

void setup() {
  for (int thisPin = 0; thisPin < pinsCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }
}

void loop() {

  unsigned long currentMillis = millis();
  unsigned long currentMicros = micros();

  //1
  if (currentMillis - previousMillisOrMicros[0] >= 10) {

    previousMillisOrMicros[0] = currentMillis;

    if (ledStates[0] == LOW) {
      ledStates[0] = HIGH;
    } else {
      ledStates[0] = LOW;
    }
    digitalWrite(3, ledStates[0]);

  }

  //2
  if (currentMillis - previousMillisOrMicros[1] >= 1) {

    previousMillisOrMicros[1] = currentMillis;

    if (ledStates[1] == LOW) {
      ledStates[1] = HIGH;
    } else {
      ledStates[1] = LOW;
    }
    digitalWrite(5, ledStates[1]);
  }

  //3
  if (currentMicros - previousMillisOrMicros[2] >= 500) {

    previousMillisOrMicros[2] = currentMicros;

    if (ledStates[2] == LOW) {
      ledStates[2] = HIGH;
    } else {
      ledStates[2] = LOW;
    }
    digitalWrite(6, ledStates[2]);
  }

  //4
  if (currentMicros - previousMillisOrMicros[3] >= 100) {
    
    previousMillisOrMicros[3] = currentMicros;

    if (ledStates[3] == LOW) {
      ledStates[3] = HIGH;
    } else {
      ledStates[3] = LOW;
    }
    digitalWrite(9, ledStates[3]);
  }

  //5
  if (currentMicros - previousMillisOrMicros[4] >= 50) {

    previousMillisOrMicros[4] = currentMicros;

    if (ledStates[4] == LOW) {
      ledStates[4] = HIGH;
    } else {
      ledStates[4] = LOW;
    }
    digitalWrite(10, ledStates[4]);
  }

}
