#include<ArduinoJson.h>

const int LM35 = 0;
float temperatura = 0;
int ADClido = 0;

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);
}

void loop() {
  ADClido = analogRead(LM35);
  temperatura = ADClido * 0.1075268817;
  //Serial.print("Temperatura = ");
  //Serial.print(temperatura);
  //Serial.println("*C");
  //delay(1000);

  StaticJsonBuffer<200> jsonBuffer;

  JsonObject& root = jsonBuffer.createObject();
  root["sensorid"] = "8566ee8cc961a20f2f00208063764cfc75082eff5b90f989b36e4da08f935e2a";
  root["sensor"] = "temperatura";
  root["temperatura"] = temperatura;
  root.printTo(Serial);
  Serial.println();

  delay(2000);
}
