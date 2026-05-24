// Bleink
//
// advertises hello world
#include "nrf.h"
#include "nrf_delay.h"
#include "nrf_gpio.h"
#include "simple_ble.h"
#include <stdbool.h>
#include <stdint.h>

// Pin configurations
#include "microbit_v2.h"

int main(void) {

  // Initialize.
  nrf_gpio_cfg_output(LED_MIC);

  // Configure ble app
  simple_ble_config_t ble_config = {
      .platform_id = 0x01,
      .device_id = DEVICE_ID_DEFAULT,
      .adv_name = "hello_world",
      .adv_interval = MSEC_TO_UNITS(100, UNIT_0_625_MS),
      .min_conn_interval = MSEC_TO_UNITS(500, UNIT_1_25_MS),
      .max_conn_interval = MSEC_TO_UNITS(1000, UNIT_1_25_MS),
  };

  // Initialize BLE.
  simple_ble_init(&ble_config);
  simple_ble_adv_only_name();

  // Enter main loop.
  while (1) {
    printf("adv..\n");
    nrf_gpio_pin_toggle(LED_MIC);
    nrf_delay_ms(500);
  }
}
