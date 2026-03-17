# esp-matter-xiao-esp32c5-cob-led

A Matter over WiFi **dimmable light** example for the Seeed Studio XIAO ESP32-C5 module and Seeed Studio COB LED Driver, based on the esp-matter SDK.

## Description

This example creates a Matter dimmable light device using the ESP Matter data model. Brightness is fully adjustable from the Home Assistant interface.

It is derived from the `light` example of esp-matter, adapted for a single-channel PWM COB LED.

## Hardware

- [Seeed Studio XIAO ESP32-C5](https://wiki.seeedstudio.com/xiao_esp32c5_getting_started/)
- [Seeed Studio COB LED Driver](https://www.seeedstudio.com/COB-LED-Driver-Board-for-Seeed-Studio-XIAO-p-6602.html)

## Requirements

- [ESP-IDF v5.5](https://github.com/espressif/esp-idf)
- [esp-matter](https://github.com/espressif/esp-matter)

## Installation

Clone this repository and run the install script to copy the example and device profile into your esp-matter directory:
```bash
git clone https://github.com/tutoduino/esp-matter-xiao-esp32c5-cob-led.git
cd esp-matter-xiao-esp32c5-cob-led
bash install.sh
```

By default, the script assumes esp-matter is installed in `~/esp/esp-matter`. You can specify a custom path:
```bash
bash install.sh /custom/path/to/esp-matter
```

The install script copies the following files:
```
esp-matter/
├── examples/
│   └── cob_led_matter_example_xiao_esp32c5/   ← example
└── device_hal/
    └── device/
        └── xiao_esp32c5/                       ← device profile
```

## Build and flash
```bash
cd ~/esp/esp-matter/examples/cob_led_matter_example_xiao_esp32c5
idf.py fullclean
idf.py set-target esp32c5
idf.py build
idf.py flash monitor
```

## Matter integration

This example supports Matter over WiFi. After flashing, commission the device using a Matter-compatible app (e.g. Home Assistant, Apple Home, Google Home).

The COB LED brightness reflects the LevelControl attribute of the Matter dimmable light endpoint.
