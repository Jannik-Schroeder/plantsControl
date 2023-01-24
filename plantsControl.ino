// Define Pins
const int moistureSensorPin = A0;   // Pin für Feuchtigkeitssensor
const int lightSensorPin = A1;      // Pin für Lichtsensor
const int pumpPin = 2;              // Pin für Pumpe
const int lightPin = 3;             // Pin für Licht
// moistureSensor
const int AirValue = 520;           // Value für Trockensten Punkt
const int WaterValue = 260;         // Value für Feuchtesten Punkt
int soilMoistureValue = 0;          // Aktuell gemessene Feuchtigkeit in Volt(raw output vom Sensor)
int soilmoisturepercent=0;          // Aktuell gemessene Feuchtigkeit in Prozent, wird später berechnet

void setup() {
    Serial.begin(9600);             // Serielle Schnittstelle öffnen, Baudrate auf 9600 bps einstellen
    pinMode(moistureSensorPin, INPUT);  // Setzt Pin auf INPUT
    pinMode(lightSensorPin, INPUT);     // Setzt Pin auf INPUT
    pinMode(pumpPin, OUTPUT);           // Setzt Pin auf OUTPUT
    pinMode(lightPin, OUTPUT);          // Setzt Pin auf OUTPUT
}

void loop() {
    int soilMoistureValue = analogRead(moistureSensorPin);
    int light = analogRead(lightSensorPin);
    Serial.println(soilMoistureValue);
    soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);     // Mapping Volt input zu Prozent

    // Ausgabe in Prozent
    if(soilmoisturepercent >= 100)
    {
        Serial.println("100 %");
    }
    else if(soilmoisturepercent <=0)
    {
        Serial.println("0 %");
    }
    else if(soilmoisturepercent >0 && soilmoisturepercent < 100) {
        Serial.print(soilmoisturepercent);
        Serial.println("%");
    }


    // Pumpe an/aus schalten
    if (soilmoisturepercent < 50) {     // Wenn die Feuchtigkeit bei unter 50% liegt pumpe an sonst aus / Wert muss noch verändert werden
        digitalWrite(pumpPin, HIGH);
    } else {
        digitalWrite(pumpPin, LOW);
    }


    // Basis Beispiel für Licht, warte auf weitere Sensoren Details
    if (light < 800) {
        digitalWrite(lightPin, HIGH);
    } else {
        digitalWrite(lightPin, LOW);
    }
}