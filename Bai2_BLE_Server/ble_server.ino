#include <BLEDevice.h>
#include <BLEServer.h>

void setup() {
  Serial.begin(115200);

  BLEDevice::init("ESP32_BLE_Server");

  BLEServer *pServer = BLEDevice::createServer();

  Serial.println("BLE Server Started");
}

void loop() {
}
