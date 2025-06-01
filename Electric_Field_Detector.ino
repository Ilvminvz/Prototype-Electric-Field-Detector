/*
  LED Bar Graph with Buzzer
  Reads analog input from a potentiometer and lights up LEDs
  in a bar graph style. If a threshold is crossed, the buzzer sounds.
*/

const int analogPin = A0;           // Analog input pin (potentiometer)
const int ledCount = 7;             // Number of LEDs
int ledPins[] = {2, 3, 4, 5, 6, 7, 8}; // LED pins
int buzzer = 13;                    // Buzzer pin
int buzzerThreshold = 6;            // LED level at which buzzer activates

void setup() {
  // Initialize LED pins as outputs
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Buzzer pin as output
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int sensorReading = analogRead(analogPin);             // Read potentiometer
  int ledLevel = map(sensorReading, 0, 1023, 0, ledCount); // Map to LED count

  // Turn on LEDs according to the level
  for (int i = 0; i < ledCount; i++) {
    if (i < ledLevel) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }

  // Buzzer sounds only if LED level is high enough
  if (ledLevel >= buzzerThreshold) {
    tone(buzzer, 1400); // Play tone
  } else {
    noTone(buzzer);     // Silence buzzer
  }

  delay(200); // Small delay to reduce flickering
}
