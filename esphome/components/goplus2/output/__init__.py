import esphome.codegen as cg
from esphome.components import output
import esphome.config_validation as cv
from esphome.const import CONF_CHANNEL, CONF_ID

from .. import CONF_GOPLUS2_ID, GoPlus2Component, goplus2_ns

GoPlus2ServoOutput = goplus2_ns.class_(
    "GoPlus2ServoOutput", output.FloatOutput, cg.Component
)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(GoPlus2ServoOutput),
        cv.GenerateID(CONF_GOPLUS2_ID): cv.use_id(GoPlus2Component),
        cv.Required(CONF_CHANNEL): cv.int_range(min=0, max=3),
    }
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await output.register_output(var, config)
    await cg.register_component(var, config)

    parent = await cg.get_variable(config[CONF_GOPLUS2_ID])
    cg.add(var.set_parent(parent))
    cg.add(var.set_channel(config[CONF_CHANNEL]))
