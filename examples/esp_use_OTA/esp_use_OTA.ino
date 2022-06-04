/****** esp_use_OTA.ino ****************************************************
*  www.weigu.lu
*  for UDP, listen on Linux PC (UDP_LOG_PC_IP) with netcat command:
*  nc -kulw 0 6666
***************************************************************************/

#define STATIC    // if static IP needed (no DHCP)
#define OTA       // if Over The Air update needed (security risk!)

#include <ESPToolbox.h>



// WiFi and network settings
const char *WIFI_SSID = "";        // SSID
const char *WIFI_PASSWORD = "";    // password
const char *NET_MDNSNAME = "myOESP";     // optional (access w myOESP.local)
const char *NET_HOSTNAME = "myOESP";     // optional
#ifdef STATIC
  IPAddress NET_LOCAL_IP (192,168,1,178);// 3x optional for static IP
  IPAddress NET_GATEWAY (192,168,1,20);
  IPAddress NET_MASK (255,255,255,0);
#endif // ifdef STATIC*/

// UDP settings
const word UDP_LOG_PORT = 6666;
IPAddress UDP_LOG_PC_IP(192,168,1,50);

// Over The Air update settings
#ifdef OTA
  const char *OTA_NAME = "myOESP";
  const char *OTA_PASS_HASH = "c3be31f8c0878e2a4f007200220ce2ba"; //LetMeOTA!
#endif // #ifdef OTA

ESPToolbox Tb;                        // create an ESPToolbox object

/****** SETUP *************************************************************/
void setup() {
  Tb.set_led_log(true);
  Tb.set_udp_log(true, UDP_LOG_PC_IP, UDP_LOG_PORT);
  //Tb.init_wifi_sta(WIFI_SSID, WIFI_PASSWORD);
  //Tb.init_wifi_sta(WIFI_SSID, WIFI_PASSWORD, NET_MDNSNAME);
  #ifdef STATIC
    Tb.init_wifi_sta(WIFI_SSID, WIFI_PASSWORD, NET_HOSTNAME, NET_LOCAL_IP,
                  NET_GATEWAY, NET_MASK);
  #else
    Tb.init_wifi_sta(WIFI_SSID, WIFI_PASSWORD, NET_MDNSNAME, NET_HOSTNAME);
  #endif // ifdef STATIC
  #ifdef OTA
    Tb.init_ota(OTA_NAME, OTA_PASS_HASH);
  #endif // ifdef OTA

}
/****** LOOP **************************************************************/

void loop() {
  #ifdef OTA
    ArduinoOTA.handle();
  #endif // ifdef OTA
  Tb.log("My message to you: ");
  Tb.log_ln("Hello");
  Tb.log_ln();
  delay(2000);
  Tb.blink_led_x_times(3);
}
