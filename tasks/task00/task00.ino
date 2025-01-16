const int N_PINS = 5; // 1, видимо, перегорел, не вычислил его номер))
int DIOD_PINS[N_PINS] = { 11, 10, 9, 6, 3 };
const int N_DELAYS = 3;
int DELAYS[N_DELAYS] = { 1, 10, 100 };

void setup() {
  int i = 0;
  while (i < 5) {
    pinMode(DIOD_PINS[i++], OUTPUT);
  }
}

void loop() {
  int i = 0;
  while (i < N_PINS) {
    int led_pin = DIOD_PINS[i++];
    int j = 0;
    while (j < N_DELAYS) {
      int delay_ = DELAYS[j++];
      digitalWrite(led_pin, HIGH);
      delay(delay_);
      digitalWrite(led_pin, LOW);
      delay(delay_);
    }
  }
}
