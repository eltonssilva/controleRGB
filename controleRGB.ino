#include <ESP8266WiFi.h>
#include <AsyncMqttClient.h>
#include <Ticker.h>


#define WIFI_SSID           "UEMA - CESSIN"
#define WIFI_PASSWORD       "uema2017cessin"

#define MQTT_HOST           "mqtt.autodomo.io"
#define MQTT_PORT           1883

const char* USER_MQTT       = "User000001075";
const char* PASSWORD_MQTT   = "upfkk9ym";
#define ID_MQTT             "05AA89C65FD7"

#define MQTT_PUB_STATE_LUZ_R  "/autodomo/User000001075/05AA89C65FD7/rgb/state"
#define MQTT_SUB_VALUE_LUZ_R  "/autodomo/User000001075/05AA89C65FD7/rgb/value"




AsyncMqttClient mqttClient;
Ticker wifiReconnectTimer;
Ticker mqttReconnectTimer;


WiFiEventHandler wifiConnectHandler;
WiFiEventHandler wifiDisconnectHandler;

unsigned long tempoAnterior = 0;
const long    intervalo     = 250;

int Rele_R = 16; 
int Rele_G = 5; 
int Rele_B = 4; 

int S1 = 0;
//int S2 = ?;
//int S3 = ?;

void setup() {
  // put your setup code here, to run once:
  initParametros();
  wifiInit();
  connectToWifi();
  mqttInit();

}

void loop() {
  // put your main code here, to run repeatedly:
  interruptor1();

}
