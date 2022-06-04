/****** esp_log_serial.ino *******************************************
*  www.weigu.lu
*  Serial1 on Wemos D1 Mini: pin D4 (only Tx)
*  Serial1 on MH ET Live ESP32 MiniKit: SD3 Serial2: IO17
***************************************************************************/

#include <ESPToolbox.h>

ESPToolbox Tb;                        // create an ESPToolbox object

/****** SETUP *************************************************************/

void setup() {
  Tb.set_led_log(true);               // enable LED and Serial logging
  Tb.set_serial_log(true);
  // overloaded method to choose Serial1 (1) or Serial2 (2, only ESP32)
  //Tb.set_serial_log(true,1);
}
/****** LOOP **************************************************************/

void loop() {
  Tb.blink_led_x_times(3);            // default blink with 100 ms
  Tb.log("Hello\n");
  delay(2000);
}
