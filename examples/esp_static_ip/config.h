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
// only if you use a static address (uncomment //#define STATIC in ino file)
const byte NET_LOCAL_IP_BYTES[4] = {192, 168, 178, 155};
const byte NET_GATEWAY_BYTES[4] = {192, 168, 178, 1};
const byte NET_MASK_BYTES[4] = {255,255,255,0};
