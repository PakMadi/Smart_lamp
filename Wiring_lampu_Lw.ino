const int ldrPin = A0;     // AO dari sensor LDR
const int touchPin = 2;    // OUT dari sensor touch
const int ledPin = 8;      // LED

bool manualMode = false;   // status mode manual

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(touchPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  int touchValue = digitalRead(touchPin);

  // Deteksi sentuhan (toggle manual mode)
  if (touchValue == HIGH) {
    manualMode = !manualMode;  // ubah status manual
    delay(300);                // debounce biar nggak dobel
  }

  // Jika mode manual aktif, LED nyala
  if (manualMode) {
    digitalWrite(ledPin, HIGH);
  } 
  // Jika tidak, nyala otomatis berdasarkan cahaya
  else {
    if (ldrValue < 500) {      // ambang gelap
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
  }

  // Debug di Serial Monitor
  Serial.print("LDR: ");
  Serial.print(ldrValue);
  Serial.print(" | Touch: ");
  Serial.print(touchValue);
  Serial.print(" | Manual mode: ");
  Serial.println(manualMode);

  delay(100);
}
