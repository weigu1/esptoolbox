/****** WiFi SSID and PASSWORD ******/
const char *MY_WIFI_SSID = "your_ssid";
const char *MY_WIFI_PASSWORD = "your_password";

/****** WiFi and network settings ******/
// UDP logging settings if enabled in setup(); Port used for UDP logging
const word UDP_LOG_PORT = 6464;
// IP address of the computer receiving UDP log messages
const byte UDP_LOG_PC_IP_BYTES[4] = {192, 168, 178, 100};
// optional (access with UDP_logger.local)
const char *NET_MDNSNAME = "UDP_logger";
// optional hostname
const char *NET_HOSTNAME = "UDP_logger";
// only if you use OTA (uncomment //#define OTA in ino file)
const char *MY_OTA_NAME = "esp_with_ota"; // optional (access with esp_with_ota.local)
// Linux Create Hasgh with: echo -n 'P@ssword1' | md5sum
const char *MY_OTA_PASS_HASH = "myHash";     // Hash for password

