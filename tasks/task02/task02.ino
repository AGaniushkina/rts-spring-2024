#include <Arduino.h>
#include <TaskManagerIO.h>

const int pinsCount = 5;
int pins[pinsCount] = {3, 5, 6, 9, 10};
int* ledStates[] = {LOW, LOW, LOW, LOW, LOW};
//unsigned long previousMillisOrMicros[] = {0, 0, 0, 0, 0};

void setup() {
   for (int i = 0; i < pinsCount; ++i) {
    ledStates[i] = LOW;
    pinMode(pins[i], OUTPUT);
  }

  taskid_t taskId0 = taskManager.scheduleFixedRate(10000, [] {
    if (ledStates[0] == LOW) {
      ledStates[0] = HIGH;
    }
    else {
      ledStates[0] = LOW;
    }

    digitalWrite(3, ledStates[0]);
  }, TIME_MICROS);

  taskid_t taskId1 = taskManager.scheduleFixedRate(1000, [] {
    if (ledStates[1] == LOW) {
      ledStates[1] = HIGH;
    }
    else {
      ledStates[1] = LOW;
    }

    digitalWrite(5, ledStates[1]);
  }, TIME_MICROS);

  taskid_t taskId2 = taskManager.scheduleFixedRate(500, [] {
    if (ledStates[2] == LOW) {
      ledStates[2] = HIGH;
    }
    else {
      ledStates[2] = LOW;
    }

    digitalWrite(6, ledStates[2]);
  }, TIME_MICROS);

  taskid_t taskId3 = taskManager.scheduleFixedRate(100, [] {
    if (ledStates[3] == LOW) {
      ledStates[3] = HIGH;
    }
    else {
      ledStates[3] = LOW;
    }

    digitalWrite(9, ledStates[3]);
  }, TIME_MICROS);

  taskid_t taskId4 = taskManager.scheduleFixedRate(50, [] {
    if (ledStates[4] == LOW) {
      ledStates[4] = HIGH;
    }
    else {
      ledStates[4] = LOW;
    }

    digitalWrite(10, ledStates[4]);
  }, TIME_MICROS); 
}

void loop() {
  taskManager.runLoop();
}
