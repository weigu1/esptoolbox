/*
  esp_static_ip.ino
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
#define STATIC       // if static IP needed (no DHCP)

/****** Arduino libraries needed ******/
#include "ESPToolbox.h"            // ESP helper lib (more on weigu.lu)
#ifdef USE_SECRETS
  // The file "secrets_xxx.h" has to be placed in a sketchbook libraries
  // folder. Create a folder named "Secrets" in sketchbook/libraries and copy
  // the config.h file there. Rename it to secrets_xxx.h
  #include <secrets_static_ip.h> // things you need to change are here or
#else
  #include "config.h"              // things you need to change are here
#endif // USE_SECRETS

/****** WiFi and network settings ******/
const char *WIFI_SSID = MY_WIFI_SSID;         // in secrets_xxx.h or config.h
const char *WIFI_PASSWORD = MY_WIFI_PASSWORD; // in secrets_xxx.h or config.h
IPAddress UDP_LOG_PC_IP(UDP_LOG_PC_IP_BYTES); // in secrets_xxx.h or config.h
#ifdef STATIC
  IPAddress NET_LOCAL_IP (NET_LOCAL_IP_BYTES);// 3x optional for static IP
  IPAddress NET_GATEWAY (NET_GATEWAY_BYTES);  // look in config.h
  IPAddress NET_MASK (NET_MASK_BYTES);
#endif // ifdef STATIC

ESPToolbox Tb;                                // Create an ESPToolbox Object

/****** SETUP *************************************************************/

void setup() {
  Tb.set_udp_log(true, UDP_LOG_PC_IP, UDP_LOG_PORT);
  Tb.set_led_log(true); // enable LED logging (pos logic)
  init_wifi_sta();
}
/****** LOOP **************************************************************/

void loop() {
  Tb.log_ln("Hi there again with static IP :)");
  delay(5000);
  Tb.blink_led_x_times(3);
  if (WiFi.status() != WL_CONNECTED) {   // if WiFi disconnected, reconnect
    init_wifi_sta();
  }
}

/********** Function for use of STATIC IP ***********************************/

// init WiFi (overloaded function if STATIC)
void init_wifi_sta() {
  #ifdef STATIC
    Tb.init_wifi_sta(WIFI_SSID, WIFI_PASSWORD, NET_HOSTNAME, NET_LOCAL_IP,
                     NET_GATEWAY, NET_MASK);
  #else
    Tb.init_wifi_sta(WIFI_SSID, WIFI_PASSWORD, NET_MDNSNAME, NET_HOSTNAME);
  #endif // ifdef STATIC
}

