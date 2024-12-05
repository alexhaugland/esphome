import esphome.codegen as cg
from esphome.components import i2c
import esphome.config_validation as cv
from esphome.const import CONF_ID

DEPENDENCIES = ["i2c"]
AUTO_LOAD = ["output"]

goplus2_ns = cg.esphome_ns.namespace("goplus2")
GoPlus2Component = goplus2_ns.class_("GoPlus2Component", cg.Component, i2c.I2CDevice)

# Constants from GoPlus2.h
CONF_GOPLUS2_ID = "goplus2_id"

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(GoPlus2Component),
    }
).extend(i2c.i2c_device_schema(0x38))


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await i2c.register_i2c_device(var, config)
