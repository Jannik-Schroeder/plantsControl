# Plants Control

## Project Description
This is a plant monitoring system that uses ESP8266/ESP32 to measure and control soil moisture. If the plant is too dry, it will be watered automatically. For monitoring, the data will be stored in influxdb.

## License
This project is licensed under the MIT License.

## Documentation
You can find the project documentation [here](https://github.com/schroeder-is/plantsControl/blob/master/README.md).

## Source Code / Binaries
The source code can be found in this GitHub repository. The instructions how to build and host it yourself follow.

## Dependencies
This project depends on the following libraries:
- ESP8266WiFiMulti (for ESP8266)
- WiFiMulti (for ESP32)
- InfluxDbClient
- InfluxDbCloud
- Grafana (optional, for visualization)


## Installation
You have to install the following libraries:
- ESP8266WiFiMulti (for ESP8266)
- WiFiMulti (for ESP32)
- InfluxDbClient
- InfluxDbCloud

### Wire Up
Connect the sensor to the ESP8266/ESP32 as follows:
![wiring diagram](https://github.com/schroeder-is/plantsControl/blob/master/Schaltung.PNG)

### Setup the 

1. Clone the repository
2. Host you InfluxDB instance or use the InfluxDB Cloud
3. Create a database in InfluxDB and follow the instructions to create a token
4. Open the project in the Arduino IDE or PlatformIO
5. Install the required libraries
6. Update the WiFi and InfluxDB credentials in the sketch.
7. Compile and upload the sketch to your ESP8266/ESP32


## Known Bugs/Compatibility Issues
Currently, there are no known bugs or compatibility issues. Please check the Issues section for updates.

## Contact Authors
For any questions, you can create a ticket in the Issues section or contact the authors at plants@arlinx.de.

## Bugreports
You can check and search for existing bugs in the Issues section of the repository.

## Featurerequests
Please create a new issue for any feature requests.

## Project Structure
The project is structured as an Arduino sketch, with the main logic in the setup() and loop() functions. The setup() function initializes the WiFi and InfluxDB connections, and the loop() function reads the soil moisture and writes the data to InfluxDB.

## Public Methods
- setup(): Initializes the system.
- loop(): Main logic loop, reads sensor data and sends it to InfluxDB.

## Note
Please update the WiFi and InfluxDB credentials in the sketch before using it. Ensure that your board type (ESP8266 or ESP32) is correctly defined in the sketch.