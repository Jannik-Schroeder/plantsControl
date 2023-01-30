# README

This code is for controlling a pump based on soil moisture readings from a sensor.

## Pin Definitions
- `moistureSensorPin` is set to A0 and is used for the soil moisture sensor input.
- `pumpPin` is set to 2 and is used for the pump control output.

## Variables
- `AirValue` is set to 520 and is used as the maximum possible raw reading from the sensor (corresponding to the driest soil).
- `WaterValue` is set to 260 and is used as the minimum possible raw reading from the sensor (corresponding to the wettest soil).
- `soilMoistureValue` is the current raw reading from the sensor in volts.
- `soilmoisturepercent` is the current soil moisture level in percent, calculated from `soilMoistureValue`.

## Functionality
In the `setup` function, serial communication is initiated at a baud rate of 9600 bps and the pins for the moisture sensor, pump, and light are set to their respective INPUT/OUTPUT modes.

In the `loop` function, the raw soil moisture value is read from the sensor and printed to the serial interface. The raw reading is then mapped to a percentage value, which is also printed to the serial interface.

If the soil moisture level is below 50%, the pump is turned on (output set to HIGH). If the soil moisture level is above 50%, the pump is turned off (output set to LOW).
