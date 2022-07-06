/*
  esp_debug_with_builtin_LED.ino
  www.weigu.lu
  Led is on after enabling log!
  more infos: www.weigu.lu/microcontroller/esptoolbox/index.html   ---------------------------------------------------------------------------
  Copyright (C) 2022 Guy WEILER www.weigu.lu

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.
  ---------------------------------------------------------------------------

  ESP8266: LOLIN/WEMOS D1 mini pro
  ESP32:   MH ET LIVE ESP32-MINI-KIT

  MHET    | MHET    - LOLIN        |---| LOLIN      - MHET    | MHET

  GND     | RST     - RST          |---| TxD        - RxD(3)  | GND
   NC     | SVP(36) -  A0          |---| RxD        - TxD(1)  | 27
  SVN(39) | 26      -  D0(16)      |---|  D1(5,SCL) -  22     | 25
   35     | 18      -  D5(14,SCK)  |---|  D2(4,SDA) -  21     | 32
   33     | 19      -  D6(12,MISO) |---|  D3(0)     -  17     | TDI(12)
   34     | 23      -  D7(13,MOSI) |---|  D4(2,LED) -  16     | 4
  TMS(14) | 5       -  D8(15,SS)   |---| GND        - GND     | 0
   NC     | 3V3     - 3V3          |---|  5V        -  5V     | 2
  SD2(9)  | TCK(13)                |---|              TD0(15) | SD1(8)
  CMD(11) | SD3(10)                |---|              SD0(7)  | CLK(6)
*/

#include <ESPToolbox.h>

ESPToolbox Tb;                        // create an ESPToolbox object

/****** SETUP *************************************************************/

void setup() {
  Tb.set_led_log(true);               // LED logging. (pos logic, LED on)
  //Tb.set_led_log(true,false);       // use neg. logic: 2 par = false)
  //Tb.set_led_log(true,5);           // other pin if LED_BUILTIN not def.
  //Tb.set_led_log(true,5,false);     // alt. pin + neg. logic
  delay(2000);
}
/****** LOOP **************************************************************/

void loop() {
  Tb.blink_led_x_times(3);            // default blink with 100ms (f=5Hz)
  delay(2000);                        // (LED was on and is on after blink)
  Tb.blink_led_x_times(3,500);        // blink with 500ms delay (f=1s)
  delay(2000);
  Tb.led_off();
  delay(2000);
  Tb.led_on();
}
