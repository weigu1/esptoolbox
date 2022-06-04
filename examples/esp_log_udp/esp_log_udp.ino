/****** esp_log_udp.ino ****************************************************
*  www.weigu.lu
*  for UDP, listen on Linux PC (UDP_LOG_PC_IP) with netcat command:
*  nc -kulw 0 6666
***************************************************************************/

//#define STATIC    // if static IP needed (no DHCP)

#include <ESPToolbox.h>



// WiFi and network settings
const char *WIFI_SSID = "myssid";          // SSID
const char *WIFI_PASSWORD = "mypass";      // password
const char *NET_MDNSNAME = "myESP";        // opt. (access with myESP.local)
const char *NET_HOSTNAME = "myESP";        // optional
#ifdef STATIC
  IPAddress NET_LOCAL_IP (192,168,1,100);  // 3x optional for static IP
  IPAddress NET_GATEWAY (192,168,1,1);
  IPAddress NET_MASK (255,255,255,0);
#endif // ifdef STATIC*/

// UDP settings
const word UDP_LOG_PORT = 6666;
IPAddress UDP_LOG_PC_IP(192,168,1,5);

ESPToolbox Tb;                             // create an ESPToolbox object

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
}
/****** LOOP **************************************************************/

void loop() {
  Tb.log("My message to you: ");
  Tb.log_ln("Hello");
  Tb.log_ln();
  delay(2000);
  Tb.blink_led_x_times(3);
}
