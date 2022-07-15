/****** WiFi SSID and PASSWORD ******/
const char *MY_WIFI_SSID = "your_ssid";
const char *MY_WIFI_PASSWORD = "your_password";

/****** WiFi and network settings ******/
// UDP logging settings if enabled in setup(); Port used for UDP logging
const word UDP_LOG_PORT = 6464;
// IP address of the computer receiving UDP log messages
const byte UDP_LOG_PC_IP_BYTES[4] = {192, 168, 178, 100};
// optional (access with UDP_logger.local)
const char *NET_MDNSNAME = "ESP_Ethernet";
// optional hostname
const char *NET_HOSTNAME = "ESP_Ethernet";
// only if you use a static address (uncomment //#define STATIC in ino file)
const byte NET_LOCAL_IP_BYTES[4] = {192, 168, 178, 155};
const byte NET_GATEWAY_BYTES[4] = {192, 168, 178, 1};
const byte NET_MASK_BYTES[4] = {255,255,255,0};
const byte NET_DNS[4] = {8, 8, 8, 8}; // optional (your gateway or 8.8.8.8 (google))
byte NET_MAC[6] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x00};  // for ethernet (e.g. Funduino board with W5100)

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


