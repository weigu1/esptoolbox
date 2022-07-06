/*
  esp_non_blocking_delay.ino
  www.weigu.lu
  more infos: www.weigu.lu/microcontroller/esptoolbox/index.html
  ---------------------------------------------------------------------------
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

/****** Arduino libraries needed ******/
#include "ESPToolbox.h"            // ESP helper lib (more on weigu.lu)

ESPToolbox Tb;                     // Create an ESPToolbox Object

const byte PIN_LED2 = D1;          // Wemos D1 mini pro
const byte PIN_LED3 = D2;          // Wemos D1 mini pro

void setup() {
  Tb.init_led(false);              // Wemos D1 mini pro has neg. logic!
  Tb.init_led(PIN_LED2,true);
  Tb.init_led(PIN_LED3,true);
}

void loop() {
  switch (Tb.non_blocking_delay_x3(100, 200, 400)) {
    case 1:
      Tb.led_toggle();
      break;
    case 2:
      Tb.led_toggle(PIN_LED2);
      break;
    case 3:
      Tb.led_toggle(PIN_LED3);
      break;
    case 0:
      break;
  }
  yield();                         // feed the (watch) dog
  // do whatever you want here
}

