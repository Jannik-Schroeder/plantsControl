const int moistureSensorPin = A0;   // Pin für Feuchtigkeitssensor
const int lightSensorPin = A1;      // Pin für Lichtsensor
const int pumpPin = 2;              // Pin für Pumpe
const int lightPin = 3;             // Pin für Licht
const int AirValue = 620;           // Value für Trockensten Punkt
const int WaterValue = 310;         // Value für Feuchtesten Punkt
int soilMoistureValue = 0;          // Aktuell gemessene Feuchtigkeit in Volt(raw output vom Sensor)
int soilmoisturepercent=0;          // Aktuell gemessene Feuchtigkeit in Prozent, wird später berechnet

void setup() {
    Serial.begin(9600);             //
    pinMode(moistureSensorPin, INPUT);
    pinMode(lightSensorPin, INPUT);
    pinMode(pumpPin, OUTPUT);
    pinMode(lightPin, OUTPUT);
}

void loop() {
  int moisture = analogRead(moistureSensorPin);
  int light = analogRead(lightSensorPin);

  if (moisture < 600) {
    digitalWrite(pumpPin, HIGH);
  } else {
    digitalWrite(pumpPin, LOW);
  }

  if (light < 800) {
    digitalWrite(lightPin, HIGH);
  } else {
    digitalWrite(lightPin, LOW);
  }
}