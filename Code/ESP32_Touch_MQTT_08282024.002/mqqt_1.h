//***********************************************************************
void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  // Feel free to add more if statements to control more GPIOs with MQTT

  // If a message is received on the topic esp32/output, you check if the message is either "on" or "off". 
  // Changes the output state according to the message
  if (String(topic) == "esp32/output") {
    Serial.print("Changing output to ");
    if(messageTemp == "on"){
      Serial.println("on");
    }
    else if(messageTemp == "off"){
      Serial.println("off");

    }
  }
}




//***********************************************************************
void publishSignal() {
  String temp_str;
  rssi = WiFi.RSSI();  // eg. -63   String(WiFi.RSSI());
  temp_str = String(rssi); //converting ftemp (the float variable above) to a string
  temp_str.toCharArray(temp, temp_str.length() + 1); //packaging up the data to publish to mqtt whoa...


  client.publish(MQTT_SIGNAL_TOPIC, temp, true);
  if ( fDebug ) {
    Serial.print("SIGNAL: ");
    Serial.println(temp);
  }
  client.loop();
  readypublishSignal = false;
}
