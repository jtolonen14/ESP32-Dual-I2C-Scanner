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

## 📦 Usage
To run the scanner:
1. Connect your I2C devices to Bus 0 and/or Bus 1.
2. Set the correct GPIO pins in the code:
   ```cpp
   #define I2C_SDA_0 21
   #define I2C_SCL_0 22
   #define I2C_SDA_1 25
   #define I2C_SCL_1 26
   ```
3. Upload the sketch to your ESP32 using the Arduino IDE or PlatformIO.
4. Open the Serial Monitor at 115200 baud to view scan results.

---

## 📊 Example Output
```
Scanning I2C Bus 0...
Found device at address 0x3C (60)
Found device at address 0x76 (118)

Scanning I2C Bus 1...
Found device at address 0x3C (60)

Summary:
Bus 0: 2 device(s)
Bus 1: 1 device(s)
Duplicate address detected: 0x3C on both buses
```

---

## 🙌 Credits  
Based on the original I2C scanner from [Random Nerd Tutorials](https://randomnerdtutorials.com/).  
Modified and extended by [Jim Tolonen](https://github.com/jtolonen14) to support dual I2C buses on the ESP32.  
Assisted by Claude Sonnet 4.5 for code generation and refinement.

---

## 📄 License
This project is licensed under the MIT License.  
You are free to use, modify, and distribute this code with proper attribution.
