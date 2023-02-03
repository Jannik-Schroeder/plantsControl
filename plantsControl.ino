// Define Pins
const int moistureSensorPin = A0;   // Pin für Feuchtigkeitssensor
const int relayPin = 2;              // Pin für Pumpe

// moistureSensor
const int AirValue = 520;           // Value für Trockensten Punkt
const int WaterValue = 260;         // Value für Feuchtesten Punkt
int soilMoistureValue = 0;          // Aktuell gemessene Feuchtigkeit in Volt(raw output vom Sensor)
int soilmoisturepercent=0;          // Aktuell gemessene Feuchtigkeit in Prozent, wird später berechnet

void setup() {
    Serial.begin(9600);             // Open serial interface, set baud rate to 9600 bps
    pinMode(moistureSensorPin, INPUT);  // Set pin to INPUT
    pinMode(relayPin, OUTPUT);           // Set pin to OUTPUT
}

void loop() {
    int soilMoistureValue = analogRead(moistureSensorPin);
    soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);     // Mapping Volt input zu Prozent

    // Ausgabe in Prozent
    if (soilmoisturepercent >= 100) {
        Serial.println("100 %");
    } else if (soilmoisturepercent <= 0) {
        Serial.println("0 %");
    } else if (soilmoisturepercent > 0 && soilmoisturepercent < 100) {
        Serial.print(soilmoisturepercent);
        Serial.println("%");
    }

    // Pumpe an/aus schalten
    if (soilmoisturepercent <
        50) {     // Wenn die Feuchtigkeit bei unter 50% liegt pumpe an sonst aus / Wert muss noch verändert werden
        digitalWrite(relayPin, HIGH);
    } else {
        digitalWrite(relayPin, LOW);
    }
}