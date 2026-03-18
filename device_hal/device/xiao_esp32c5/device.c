// Copyright 2025 Espressif Systems (Shanghai) CO LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License

#include <esp_log.h>
#include <iot_button.h>
#include <button_gpio.h>
#include <driver/gpio.h>
#include <led_driver.h>

#define LED_GPIO_PIN GPIO_NUM_25
#define LED_CHANNEL 0 /* LEDC_CHANNEL_0 */
#define BUTTON_GPIO_PIN GPIO_NUM_28

static const char *TAG = "device";

led_driver_config_t led_driver_get_config()
{
    led_driver_config_t config = {
        .gpio = LED_GPIO_PIN,
        .channel = LED_CHANNEL,
        /* The COB LED Driver uses an active-low PWM signal:
           the LED turns on when the GPIO is low (duty cycle = 0)
           and turns off when the GPIO is high (duty cycle = 255).
           output_invert = true corrects this so that a higher
           brightness value in Home Assistant produces a brighter LED. */    
        .output_invert = true,    
    };
    return config;
}

button_gpio_config_t button_driver_get_config()
{
    button_gpio_config_t config = {
        .gpio_num = BUTTON_GPIO_PIN,
        .active_level = 0,
    };
    return config;
}
