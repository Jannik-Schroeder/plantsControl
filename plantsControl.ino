#if defined(ESP32)
  #include <WiFiMulti.h>
  WiFiMulti wifiMulti;
  #define DEVICE "ESP32"
  #elif defined(ESP8266)
  #include <ESP8266WiFiMulti.h>
  ESP8266WiFiMulti wifiMulti;
  #define DEVICE "ESP8266"
  #endif
  
  #include <InfluxDbClient.h>
  #include <InfluxDbCloud.h>
  
  // WiFi AP SSID
  #define WIFI_SSID "AndrewTape"
  // WiFi password
  #define WIFI_PASSWORD "peppapig"
  
  #define INFLUXDB_URL "https://export.arlinx.de"
  #define INFLUXDB_TOKEN "OZhtkScM45ohNnULyLViLOlcI01hsTmgSmQjH2TI79giDUS6jrUBJ3joK13B6HrcwQjGb7hSThUEhIzbnkMZHQ=="
  #define INFLUXDB_ORG "feef97a760d01181"
  #define INFLUXDB_BUCKET "plants"
  
  // Time zone info
  #define TZ_INFO "UTC2"
  
  // Declare InfluxDB client instance with preconfigured InfluxCloud certificate
  InfluxDBClient client(INFLUXDB_URL, INFLUXDB_ORG, INFLUXDB_BUCKET, INFLUXDB_TOKEN, InfluxDbCloud2CACert);
  
  // Declare Data point
  Point sensor("wifi_status");


  // Define Pins
const int moistureSensorPin = A0;   // Pin für Feuchtigkeitssensor
const int relayPin = D1;              // Pin für Pumpe

// moistureSensor
const int AirValue = 520;           // Value für Trockensten Punkt
const int WaterValue = 260;         // Value für Feuchtesten Punkt
int soilMoistureValue = 0;          // Aktuell gemessene Feuchtigkeit in Volt(raw output vom Sensor)
int soilmoisturepercent=0;          // Aktuell gemessene Feuchtigkeit in Prozent, wird später berechnet
  
  void setup() {
    Serial.begin(115200);            // Open serial interface, set baud rate to 9600 bps
    pinMode(moistureSensorPin, INPUT);  // Set pin to INPUT
    pinMode(relayPin, OUTPUT);           // Set pin to OUTPUT
  
    // Setup wifi
    WiFi.mode(WIFI_STA);
    wifiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);
  
    Serial.print("Connecting to wifi");
    while (wifiMulti.run() != WL_CONNECTED) {
      Serial.print(".");
      delay(100);
    }
    Serial.println();
  
    // Accurate time is necessary for certificate validation and writing in batches
    // We use the NTP servers in your area as provided by: https://www.pool.ntp.org/zone/
    // Syncing progress and the time will be printed to Serial.
    timeSync(TZ_INFO, "pool.ntp.org", "time.nis.gov");
  
  
    // Check server connection
    if (client.validateConnection()) {
      Serial.print("Connected to InfluxDB: ");
      Serial.println(client.getServerUrl());
    } else {
      Serial.print("InfluxDB connection failed: ");
      Serial.println(client.getLastErrorMessage());
    }
    sensor.addTag("device", DEVICE);
    sensor.addTag("SSID", WiFi.SSID());
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

    // Clear fields for reusing the point. Tags will remain the same as set above.
    sensor.clearFields();
  
    // Store measured value into point
    // Report RSSI of currently connected network
    sensor.addField("rssi", WiFi.RSSI());
  
    // Print what are we exactly writing
    Serial.print("Writing: ");
    Serial.println(sensor.toLineProtocol());
  
    // Check WiFi connection and reconnect if needed
    if (wifiMulti.run() != WL_CONNECTED) {
      Serial.println("Wifi connection lost");
    }
  
    // Write point
    if (!client.writePoint(sensor)) {
      Serial.print("InfluxDB write failed: ");
      Serial.println(client.getLastErrorMessage());
    }
  
    Serial.println("Waiting 1 second");
    delay(1000);
    }

}
