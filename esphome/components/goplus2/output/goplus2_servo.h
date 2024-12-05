#pragma once

#include "esphome/core/component.h"
#include "esphome/components/output/float_output.h"
#include "../goplus2.h"

namespace esphome {
namespace goplus2 {

class GoPlus2ServoOutput : public output::FloatOutput, public Component {
 public:
  void set_parent(GoPlus2Component *parent) { parent_ = parent; }
  void set_channel(uint8_t channel) { channel_ = channel; }

  void write_state(float state) override {
    uint8_t angle = static_cast<uint8_t>(state * 180.0f);
    this->parent_->servo_write_angle(this->channel_, angle);
  }

 protected:
  GoPlus2Component *parent_;
  uint8_t channel_;
};

}  // namespace goplus2
}  // namespace esphome