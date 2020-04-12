#include "BleConnectionStatus.h"

BleConnectionStatus::BleConnectionStatus(void) {
}

void BleConnectionStatus::onConnect(BLEServer* pServer)
{
  Serial.println("connected");

  this->connected = true;
  BLE2902* desc = (BLE2902*)this->inputGamepad->getDescriptorByUUID(BLEUUID((uint16_t)0x2902));
      uint8_t val[] = {0x01, 0x00};
      desc->setValue(val, 2);

  desc->setNotifications(true);
}

void BleConnectionStatus::onDisconnect(BLEServer* pServer)
{
  Serial.println("disconnected");

  this->connected = false;
  BLE2902* desc = (BLE2902*)this->inputGamepad->getDescriptorByUUID(BLEUUID((uint16_t)0x2902));
  desc->setNotifications(false);
}
