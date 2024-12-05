#pragma once

#include "esphome/core/component.h"
#include "esphome/components/i2c/i2c.h"

namespace esphome {
namespace goplus2 {

// Constants from GoPlus2.h
static const uint8_t SERVO_ADDR = 0x00;
static const uint8_t PULSE_ADDR = 0x10;

// Servo numbers
static const uint8_t SERVO_NUM0 = 0x00;
static const uint8_t SERVO_NUM1 = 0x01;
static const uint8_t SERVO_NUM2 = 0x02;
static const uint8_t SERVO_NUM3 = 0x03;

class GoPlus2Component : public Component, public i2c::I2CDevice {
 public:
  void setup() override;
  void dump_config() override;
  float get_setup_priority() const override { return setup_priority::IO; }

  // Servo control methods
  void servo_write_angle(uint8_t number, uint8_t angle);
  void servo_write_pulse_width(uint8_t number, uint16_t width);

 protected:
  bool write_bytes(const uint8_t *data, uint8_t len);
};

}  // namespace goplus2
}  // namespace esphome