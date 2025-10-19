/*********
  Modified I2C Scanner for ESP32 - Multiple Bus Support
  Scans both I2C buses and reports devices by bus and address
*********/

#include <Wire.h>

// Define pins for I2C Bus 0
#define I2C_SDA_0 21  // Default SDA for ESP32
#define I2C_SCL_0 22  // Default SCL for ESP32

// Define pins for I2C Bus 1 (change these to your actual pins)
#define I2C_SDA_1 25  // Example: GPIO 25
#define I2C_SCL_1 26  // Example: GPIO 26

// Create two Wire instances
TwoWire I2C_0 = TwoWire(0);
TwoWire I2C_1 = TwoWire(1);

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  // Initialize both I2C buses
  I2C_0.begin(I2C_SDA_0, I2C_SCL_0, 100000);
  I2C_1.begin(I2C_SDA_1, I2C_SCL_1, 100000);
  
  Serial.println("\n\n=================================");
  Serial.println("ESP32 Dual I2C Bus Scanner");
  Serial.println("=================================");
  Serial.print("Bus 0: SDA=GPIO");
  Serial.print(I2C_SDA_0);
  Serial.print(", SCL=GPIO");
  Serial.println(I2C_SCL_0);
  Serial.print("Bus 1: SDA=GPIO");
  Serial.print(I2C_SDA_1);
  Serial.print(", SCL=GPIO");
  Serial.println(I2C_SCL_1);
  Serial.println("=================================\n");
}

void loop() {
  int totalDevices = 0;
  
  Serial.println("\n==================== Scanning ====================");
  
  // Scan Bus 0
  Serial.println("\n[BUS 0] Scanning...");
  int devicesOnBus0 = scanBus(I2C_0, 0);
  totalDevices += devicesOnBus0;
  
  // Scan Bus 1
  Serial.println("\n[BUS 1] Scanning...");
  int devicesOnBus1 = scanBus(I2C_1, 1);
  totalDevices += devicesOnBus1;
  
  // Summary
  Serial.println("\n==================== Summary ====================");
  Serial.print("Bus 0: ");
  Serial.print(devicesOnBus0);
  Serial.println(" device(s) found");
  Serial.print("Bus 1: ");
  Serial.print(devicesOnBus1);
  Serial.println(" device(s) found");
  Serial.print("Total: ");
  Serial.print(totalDevices);
  Serial.println(" device(s) found");
  
  if (totalDevices == 0) {
    Serial.println("\nNo I2C devices found on any bus!");
  }
  
  Serial.println("==================================================\n");
  
  delay(5000);
}

int scanBus(TwoWire &wire, int busNumber) {
  byte error, address;
  int nDevices = 0;
  
  for(address = 1; address < 127; address++ ) {
    wire.beginTransmission(address);
    error = wire.endTransmission();
    
    if (error == 0) {
      Serial.print("  ✓ Device found on Bus ");
      Serial.print(busNumber);
      Serial.print(" at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.print(" (");
      Serial.print(address);
      Serial.println(")");
      nDevices++;
    }
    else if (error == 4) {
      Serial.print("  ! Unknown error on Bus ");
      Serial.print(busNumber);
      Serial.print(" at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }    
  }
  
  if (nDevices == 0) {
    Serial.println("  No devices found on this bus");
  }
  
  return nDevices;
}
