# ESP32 Dual I2C Bus Scanner

An I2C scanner for ESP32 that scans **both I2C buses separately** and reports which bus each device is on.

## Why This Exists

Many I2C sensors come with the same default address (like 0x3C for OLEDs or 0x76 for BME280). The ESP32 has two I2C buses, allowing you to use multiple sensors with identical addresses. However, most I2C scanners only scan one bus.

This scanner solves that problem by scanning both buses and clearly reporting which devices are on which bus.

## Features

- ✅ Scans both I2C buses (Bus 0 and Bus 1)
- ✅ Reports devices by bus number and address
- ✅ Shows addresses in both HEX and decimal
- ✅ Summary statistics
- ✅ Handles duplicate addresses on different buses

## Hardware Setup

Configure the GPIO pins for your setup:

```cpp
// Bus 0 (default pins)
#define I2C_SDA_0 21
#define I2C_SCL_0 22

// Bus 1 (change to your pins)
#define I2C_SDA_1 25
#define I2C_SCL_1 26
