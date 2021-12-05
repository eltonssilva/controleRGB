
   
void interruptor1(){

   unsigned long tempoAtualMillis = millis();
   bool s1State =     digitalRead(S1);
   bool releRState =  digitalRead(Rele_R);

  if(tempoAtualMillis - tempoAnterior >= intervalo){
    tempoAnterior = tempoAtualMillis;
    bool novoEstadoRele = !releRState;

    if(!s1State){
      digitalWrite(Rele_R, novoEstadoRele);
    }

    if(novoEstadoRele){
      mqttClient.publish(MQTT_PUB_STATE_LUZ_R, 1, true, "0");
    }else{
      mqttClient.publish(MQTT_PUB_STATE_LUZ_R, 1, true, "1");
    }
    
  }
    
}
