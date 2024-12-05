#include "goplus2.h"
#include "esphome/core/log.h"

namespace esphome {
namespace goplus2 {

static const char *const TAG = "goplus2";

void GoPlus2Component::setup() {
  ESP_LOGCONFIG(TAG, "Setting up GoPlus2...");
  set_i2c_address(GOPLUS2_ADDR);
}

void GoPlus2Component::dump_config() {
  ESP_LOGCONFIG(TAG, "GoPlus2:");
  LOG_I2C_DEVICE(this);
}

bool GoPlus2Component::write_bytes(const uint8_t *data, uint8_t len) { return write(data, len) == i2c::ERROR_OK; }

void GoPlus2Component::servo_write_angle(uint8_t number, uint8_t angle) {
  uint8_t data[2] = {SERVO_ADDR | number, angle};
  if (!write_bytes(data, 2)) {
    ESP_LOGE(TAG, "Error writing servo angle");
  }
}

void GoPlus2Component::servo_write_pulse_width(uint8_t number, uint16_t width) {
  uint8_t data[3] = {PULSE_ADDR | number, static_cast<uint8_t>(width >> 8), static_cast<uint8_t>(width & 0xFF)};
  if (!write_bytes(data, 3)) {
    ESP_LOGE(TAG, "Error writing servo pulse width");
  }
}

}  // namespace goplus2
}  // namespace esphome