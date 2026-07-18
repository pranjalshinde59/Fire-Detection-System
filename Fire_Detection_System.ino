// Fire Detection System using Arduino Uno
// Author: Pranjal Machindra Shinde

const int flameSensor = 2;     // Digital pin for Flame Sensor
const int smokeSensor = A0;    // Analog pin for MQ-2 Sensor
const int buzzer = 8;          // Buzzer pin
const int led = 9;             // LED pin

int smokeThreshold = 300;

void setup() {
  pinMode(flameSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600);

  digitalWrite(buzzer, LOW);
  digitalWrite(led, LOW);
}

void loop() {

  int flameValue = digitalRead(flameSensor);
  int smokeValue = analogRead(smokeSensor);

  Serial.print("Flame: ");
  Serial.print(flameValue);
  Serial.print("  Smoke: ");
  Serial.println(smokeValue);

  if (flameValue == LOW || smokeValue > smokeThreshold) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(led, HIGH);

    Serial.println("WARNING: Fire or Smoke Detected!");
  }
  else {
    digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);

    Serial.println("Environment Safe");
  }

  delay(500);
}
