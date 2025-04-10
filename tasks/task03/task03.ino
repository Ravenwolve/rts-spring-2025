const int ledPins[5] = { 3, 5, 6, 9, 10 };

#define INTERVAL_PIN_3 (5000)
#define INTERVAL_PIN_5 (500)
#define INTERVAL_PIN_6 (250)
#define INTERVAL_PIN_9 (50)
#define INTERVAL_PIN_10 (25)

long long PREVIOUS_MICROS_3 = 0;
long long PREVIOUS_MICROS_5 = 0;
long long PREVIOUS_MICROS_6 = 0;
long long PREVIOUS_MICROS_9 = 0;
long long PREVIOUS_MICROS_10 = 0;

bool STATE_PIN_3 = false;
bool STATE_PIN_5 = false;
bool STATE_PIN_6 = false;
bool STATE_PIN_9 = false;
bool STATE_PIN_10 = false;

void setup() {
  for (int i = 0; i < 5; ++i) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  unsigned long currentMicros = micros();

  if (currentMicros - PREVIOUS_MICROS_10 >= INTERVAL_PIN_10) {
    PREVIOUS_MICROS_10 = currentMicros;
    STATE_PIN_10 = !STATE_PIN_10;
    digitalWrite(10, STATE_PIN_10);
  }
  if (currentMicros - PREVIOUS_MICROS_9 >= INTERVAL_PIN_9) {
    PREVIOUS_MICROS_9 = currentMicros;
    STATE_PIN_9 = !STATE_PIN_9;
    digitalWrite(9, STATE_PIN_9);
  }
  if (currentMicros - PREVIOUS_MICROS_6 >= INTERVAL_PIN_6) {
    PREVIOUS_MICROS_6 = currentMicros;
    STATE_PIN_6 = !STATE_PIN_6;
    digitalWrite(6, STATE_PIN_6);
  }
  if (currentMicros - PREVIOUS_MICROS_5 >= INTERVAL_PIN_5) {
    PREVIOUS_MICROS_5 = currentMicros;
    STATE_PIN_5 = !STATE_PIN_5;
    digitalWrite(5, STATE_PIN_5);
  }
    if (currentMicros - PREVIOUS_MICROS_3 >= INTERVAL_PIN_3) {
    PREVIOUS_MICROS_3 = currentMicros;
    STATE_PIN_3 = !STATE_PIN_3;
    digitalWrite(3, STATE_PIN_3);
  }
}
