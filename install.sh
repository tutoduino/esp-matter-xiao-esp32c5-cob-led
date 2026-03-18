#!/bin/bash
echo "Installing tutoduino COB LED Matter example for XIAO ESP32-C5"
ESP_MATTER_PATH=${1:-~/esp/esp-matter}
cp -r examples/cob_led_matter_example_xiao_esp32c5 $ESP_MATTER_PATH/examples/
cp -r device_hal/device/xiao_esp32c5 $ESP_MATTER_PATH/device_hal/device/
echo "Done. You can now build the example."
