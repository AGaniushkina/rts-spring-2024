// constants won't change. Used here to set a pin number:
// const int ledPin0 = LED_BUILTIN;  // the number of the LED pin
const int ledPins[] = {3, 5, 6, 9, 10};

int pinsCount = 5;

// Variables will change:
// int ledState0 = LOW;  // ledState used to set the LED
int ledStates[] = {HIGH, HIGH, HIGH, HIGH, HIGH};

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillisOrMicros[] = {0, 0, 0, 0, 0};  // will store last time LED was updated

// constants won't change:
// const long interval0 = 1000;  // interval at which to blink (milliseconds)
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

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();
  unsigned long currentMicros = micros();

  //1
  if (currentMillis - previousMillisOrMicros[0] >= 10) {
    // save the last time you blinked the LED
    previousMillisOrMicros[0] = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledStates[0] == LOW) {
      ledStates[0] = HIGH;
    } else {
      ledStates[0] = LOW;
    }

    // set the LED with the ledState of the variable:
    //digitalWrite(ledPins[0], ledStates[0]);
  }

  //2
  if (currentMillis - previousMillisOrMicros[1] >= 1) {
    // save the last time you blinked the LED
    previousMillisOrMicros[1] = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledStates[1] == LOW) {
      ledStates[1] = HIGH;
    } else {
      ledStates[1] = LOW;
    }

    // set the LED with the ledState of the variable:
    //digitalWrite(ledPins[1], ledStates[1]);
  }

  //3
  if (currentMicros - previousMillisOrMicros[2] >= 500) {
    // save the last time you blinked the LED
    previousMillisOrMicros[2] = currentMicros;

    // if the LED is off turn it on and vice-versa:
    if (ledStates[2] == LOW) {
      ledStates[2] = HIGH;
    } else {
      ledStates[2] = LOW;
    }

    // set the LED with the ledState of the variable:
    //digitalWrite(ledPins[0], ledStates[0]);
  }

  //4
  if (currentMicros - previousMillisOrMicros[3] >= 100) {
    // save the last time you blinked the LED
    previousMillisOrMicros[3] = currentMicros;

    // if the LED is off turn it on and vice-versa:
    if (ledStates[3] == LOW) {
      ledStates[3] = HIGH;
    } else {
      ledStates[3] = LOW;
    }

    // set the LED with the ledState of the variable:
    //digitalWrite(ledPins[0], ledStates[0]);
  }

  //5
  if (currentMicros - previousMillisOrMicros[4] >= 50) {
    // save the last time you blinked the LED
    previousMillisOrMicros[4] = currentMicros;

    // if the LED is off turn it on and vice-versa:
    if (ledStates[4] == LOW) {
      ledStates[4] = HIGH;
    } else {
      ledStates[4] = LOW;
    }

    // set the LED with the ledState of the variable:
    //digitalWrite(ledPins[0], ledStates[0]);
  }

  for (int thisPin = 0; thisPin < pinsCount; thisPin++) {
    digitalWrite(ledPins[thisPin], ledStates[thisPin]);
  }
}
