void connectToWifi(){
  Serial.println("Conectando Wifi");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}


void onWifiConnect(const WiFiEventStationModeGotIP& event){
  Serial.println("Wifi Conectado");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  connectToMqtt();
}

void onWifiDisconnect(const WiFiEventStationModeDisconnected& event){
  Serial.println("Wifi Disconectado");
  wifiReconnectTimer.once(2, connectToWifi);
}


void wifiInit(){
  wifiConnectHandler = WiFi.onStationModeGotIP(onWifiConnect);
  wifiDisconnectHandler = WiFi.onStationModeDisconnected(onWifiDisconnect);
}
