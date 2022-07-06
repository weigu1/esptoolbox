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
// if you want to use an NTP server
const char *NTP_SERVER = "lu.pool.ntp.org"; // NTP settings
// your time zone (https://remotemonitoringsystems.ca/time-zone-abbreviations.php)
const char *TZ_INFO    = "CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00";

/****** MQTT settings ******/
const char *MQTT_SERVER = "192.168.178.222";
const long PUBLISH_TIME = 10000; //Publishes every in milliseconds
const int MQTT_MAXIMUM_PACKET_SIZE = 1024; // look in setup()
const char *MQTT_CLIENT_ID = "ntp_time"; // this must be unique!!!
String MQTT_TOPIC_OUT = "mqtt_test/data";
String MQTT_TOPIC_IN = "mqtt_test/command";
const short MY_MQTT_PORT = 1883; // or 8883
// only if you use MQTTPASSWORD (uncomment //#define MQTTPASSWORD in ino file)
const char *MY_MQTT_USER = "me";
const char *MY_MQTT_PASS = "meagain";


