# Plants Control

## Project Description
This is a plant monitoring system using ESP8266/ESP32 to measure and control the soil moisture level.

## License
This project is licensed under the MIT License.

## Documentation
You can find the project documentation [here](https://github.com/schroeder-is/plantsControl/blob/master/README.md).

## Source Code / Binaries
The source code can be found in this GitLab repository. The binaries for the project can be found in the Releases section.

## Installation
Clone the repository and upload the code to your ESP8266/ESP32 using the Arduino IDE or PlatformIO.

## Dependencies
This project depends on the following libraries:
- ESP8266WiFiMulti (for ESP8266)
- WiFiMulti (for ESP32)
- InfluxDbClient
- InfluxDbCloud

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