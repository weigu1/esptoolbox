/*
  esp_use_ota.ino
  www.weigu.lu
  for UDP, listen on Linux PC (UDP_LOG_PC_IP) with netcat command:
  nc -kulw 0 6464
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

/*!!!!!!       Make your changes in config.h (or secrets_xxx.h)      !!!!!!*/

/*------ Comment or uncomment the following line suiting your needs -------*/
#define USE_SECRETS  // if we use secrets file instead of config.h
#define OTA          // if Over The Air update needed (security risk!)

/****** Arduino libraries needed ******/
#include "ESPToolbox.h"            // ESP helper lib (more on weigu.lu)
#ifdef USE_SECRETS
  // The file "secrets_xxx.h" has to be placed in a sketchbook libraries
  // folder. Create a folder named "Secrets" in sketchbook/libraries and copy
  // the config.h file there. Rename it to secrets_xxx.h
  #include <secrets_use_ota.h> // things you need to change are here or
#else
  #include "config.h"              // things you need to change are here
#endif // USE_SECRETS

/****** WiFi and network settings ******/
const char *WIFI_SSID = MY_WIFI_SSID;         // in secrets_xxx.h or config.h
const char *WIFI_PASSWORD = MY_WIFI_PASSWORD; // in secrets_xxx.h or config.h
IPAddress UDP_LOG_PC_IP(UDP_LOG_PC_IP_BYTES); // in secrets_xxx.h or config.h
#ifdef OTA                                    // optional OTA settings
  const char *OTA_NAME = MY_OTA_NAME;         // look in config.h
  const char *OTA_PASS_HASH = MY_OTA_PASS_HASH;
#endif // ifdef OTA

ESPToolbox Tb;                                // Create an ESPToolbox Object

/****** SETUP *************************************************************/

void setup() {
  Tb.set_udp_log(true, UDP_LOG_PC_IP, UDP_LOG_PORT);
  Tb.set_led_log(true); // enable LED logging (pos logic)
  Tb.init_wifi_sta(WIFI_SSID, WIFI_PASSWORD);
  #ifdef OTA
    Tb.init_ota(OTA_NAME, OTA_PASS_HASH);
  #endif // ifdef OTA
}
/****** LOOP **************************************************************/

void loop() {
  #ifdef OTA
    ArduinoOTA.handle();
  #endif // ifdef OTA
  Tb.log_ln("Hi there; program me over the air :)");
  delay(5000);
  Tb.blink_led_x_times(3);
  if (WiFi.status() != WL_CONNECTED) {   // if WiFi disconnected, reconnect
    Tb.init_wifi_sta(WIFI_SSID, WIFI_PASSWORD);
  }
}
