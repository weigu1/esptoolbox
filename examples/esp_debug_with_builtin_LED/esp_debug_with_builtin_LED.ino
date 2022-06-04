/****** esp_debug_with_builtin_LED.ino ****** www.weigu.lu ****************/

#include <ESPToolbox.h>

ESPToolbox Tb;                        // create an ESPToolbox object

/****** SETUP *************************************************************/

void setup() {
  Tb.set_led_log(true);               // init LED and switch it on
  //Tb.set_led_log(true,false);       // change to neg. logic (2 par = false)
  //Tb.set_led_log(true,5);           // give alt. pin if LED_BUILTIN not def
  //Tb.set_led_log(true,5.false);     // alt. pin + neg logic
}
/****** LOOP **************************************************************/

void loop() {
  Tb.blink_led_x_times(3);            // default blink with 100 ms (F=5Hz)
  delay(2000);
  Tb.blink_led_x_times(3,500);        // blink with 500ms delay (f=1s)
  delay(2000);
  Tb.led_off();
  delay(2000);
}
