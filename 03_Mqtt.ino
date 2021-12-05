void connectToMqtt(){
  Serial.println("Conectando para o MQTT");
  mqttClient.connect();
}

void onMqttConnect(bool sessionPresent){
  Serial.println("Conectado no MQTT...");
  mqttClient.subscribe(MQTT_SUB_VALUE_LUZ_R, 2);

}

void onMqttDisconnect(AsyncMqttClientDisconnectReason reason){
  Serial.println("Disconectado no MQTT...");

  if(WiFi.isConnected()){
    mqttReconnectTimer.once(2, connectToMqtt);
  }
  
}


void onMqttMessage(char* topic, char* payload, AsyncMqttClientMessageProperties properties, size_t len, size_t index, size_t total){


    String carga_util = "";

    //obtem a string do payload recebido
    for(int i = 0; i < len; i++) 
    {
       char c = (char)payload[i];
       carga_util += c;
    }


  Serial.println(carga_util);

  if(payload[0] == 'p'){
    if(payload[1] == '1'){
      digitalWrite(Rele_R, HIGH);
      digitalWrite(Rele_G, HIGH);
      digitalWrite(Rele_B, HIGH);
      mqttClient.publish(MQTT_PUB_STATE_LUZ_R, 1, true, "#FFFFFF");
      }else{
      digitalWrite(Rele_R, LOW);
      digitalWrite(Rele_G, LOW);
      digitalWrite(Rele_B, LOW);
      mqttClient.publish(MQTT_PUB_STATE_LUZ_R, 1, true, "#000000");
      }

  }else if(payload[0] == 'r'){
    int red = 0;
    int gree = 0;
    int blue = 0;
    

     String vermelho = carga_util.substring(1, 4);
     String verde = carga_util.substring(5, 8);
     String azul  = carga_util.substring(9, 12);

    Serial.println(vermelho);
    Serial.println(verde);
    Serial.println(azul);

    
  }else{
    
  }

  
}

void mqttInit(){
  mqttClient.setServer(MQTT_HOST, MQTT_PORT);
  mqttClient.setCredentials(USER_MQTT, PASSWORD_MQTT);
  mqttClient.setClientId(ID_MQTT);
  mqttClient.onConnect(onMqttConnect);
  mqttClient.onDisconnect(onMqttDisconnect);
  mqttClient.onMessage(onMqttMessage);
}
