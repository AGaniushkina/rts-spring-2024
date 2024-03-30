#include <Arduino.h>
#include <TaskManagerIO.h>

const int pinsCount = 5;
const int ledPins[pinsCount] = {3, 5, 6, 9, 10};
const TimePeriod interval[pinsCount] = {repeatMillis(10), repeatMillis(1), repeatMicros(500), repeatMicros(100), repeatMicros(50)};

taskid_t tasks[pinsCount];

class Exec : public Executable {
private:
  int _state = LOW;

public:
  int pin;
  void exec() override {
      digitalWrite(pin, _state);
      _state = (_state == LOW) ? HIGH : LOW;
  }
} execs[pinsCount];

void setup() {
  for (int i = 0; i < pinsCount; ++i) {
    execs[i] = Exec();
    execs[i].pin = ledPins[i];
    pinMode(ledPins[i], OUTPUT);
    tasks[i] = taskManager.schedule(interval[i], &execs[i]);
  }
}

void loop() {
  taskManager.runLoop();
}