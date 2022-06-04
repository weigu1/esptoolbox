/****** esp_use_ntp.ino ****************************************************
*  www.weigu.lu
***************************************************************************/

//#define STATIC    // if static IP needed (no DHCP)

#include <ESPToolbox.h>

// WiFi and network settings
const char *WIFI_SSID = "myssid";          // SSID
const char *WIFI_PASSWORD = "mypass";      // password

ESPToolbox Tb;                             // create an ESPToolbox object

/****** SETUP *************************************************************/

void setup() {
  Tb.set_led_log(true);
  Tb.set_serial_log(true);
  Tb.init_wifi_sta(WIFI_SSID, WIFI_PASSWORD);
  Tb.init_ntp_time();
}

/****** LOOP **************************************************************/

void loop() {
  Tb.get_time();
  Tb.log("\nHere is the time structure: ");
  Tb.log_time_struct();
  Tb.log("\nTo get e.g. the time use Tb.log_ln(Tb.t.time); and you get: ");
  Tb.log_ln(Tb.t.time);
  delay(2000);
  Tb.blink_led_x_times(3);
}
