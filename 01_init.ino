void initParametros(){
  Serial.begin(115200);

  pinMode(Rele_R, OUTPUT);
  pinMode(Rele_G, OUTPUT);
  pinMode(Rele_B, OUTPUT);

  pinMode(S1, INPUT);
//  pinMode(S2, INPUT);
//  pinMode(S3, INPUT);
  
  digitalWrite(Rele_R, 0);
  digitalWrite(Rele_G, 0);
  digitalWrite(Rele_B, 0);
  
}
