long previousMicros[5] = { 0, 0, 0, 0, 0 };
int ledStates[5] = { LOW, LOW, LOW, LOW, LOW };
const int ledPins[5] = { 3, 5, 6, 9, 10 };
const int intervalsMicros[5] = { 5000, 500, 250, 50, 25 };

#define INTERVAL_PIN_3 (5000)
#define INTERVAL_PIN_5 (500)
#define INTERVAL_PIN_6 (250)
#define INTERVAL_PIN_9 (50)
#define INTERVAL_PIN_10 (25)

#define D10_PB2_ON (0x04)
#define D9_PB1_ON (0x02)
#define D6_PD6_ON (0x40)
#define D5_PD5_ON (0x20)
#define D3_PD3_ON (0x08)

#define D10_PB2_OFF (0xFB)
#define D9_PB1_OFF (0xFD)
#define D6_PD6_OFF (0xBF)
#define D5_PD5_OFF (0xDF)
#define D3_PD3_OFF (0xFB)

long long PREVIOUS_MICROS_3 = 0;
long long PREVIOUS_MICROS_5 = 0;
long long PREVIOUS_MICROS_6 = 0;
long long PREVIOUS_MICROS_9 = 0;
long long PREVIOUS_MICROS_10 = 0;

void setup() {
  for (int i = 0; i < 5; ++i)
  {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  unsigned long currentMicros = micros();

  if (currentMicros - PREVIOUS_MICROS_10 >= INTERVAL_PIN_10) {
    PREVIOUS_MICROS_10 = currentMicros;
    if (PORTB & D10_PB2_ON) {
      PORTB &= D10_PB2_OFF;
    }
    else {
      PORTB |= D10_PB2_ON;
    }
  }
  if (currentMicros - PREVIOUS_MICROS_9 >= INTERVAL_PIN_9) {
    PREVIOUS_MICROS_9 = currentMicros;
    if (PORTB & D9_PB1_ON) {
      PORTB &= D9_PB1_OFF;
    }
    else {
      PORTB |= D9_PB1_ON;
    }
  }
  if (currentMicros - PREVIOUS_MICROS_6 >= INTERVAL_PIN_6) {
    PREVIOUS_MICROS_6 = currentMicros;
    if (PORTD & D6_PD6_ON) {
      PORTD &= D6_PD6_OFF;
    }
    else {
      PORTD |= D6_PD6_ON;
    }
  }
  if (currentMicros - PREVIOUS_MICROS_5 >= INTERVAL_PIN_5) {
    PREVIOUS_MICROS_5 = currentMicros;
    if (PORTD & D5_PD5_ON) {
      PORTD &= D5_PD5_OFF;
    }
    else {
      PORTD |= D5_PD5_ON;
    }
  }
    if (currentMicros - PREVIOUS_MICROS_3 >= INTERVAL_PIN_3) {
    PREVIOUS_MICROS_3 = currentMicros;
    if (PORTD & D3_PD3_ON) {
      PORTD &= D3_PD3_OFF;
    }
    else {
      PORTD |= D3_PD3_ON;
    }
  }
}
