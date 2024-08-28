extern bool errorWifi;





//SSID/password for router connection
const char* ssid = "SSID";
const char* passphrase = "PASSWORD";


void reconnect() {
  int retryMQTT;
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(deviceId, mqttUser, mqttPassword)) {
      client.subscribe(topic);
      Serial.println("Connected to MQTT Server");
    } else {
      Serial.print("[FAILED] [ rc = ");
      Serial.print(client.state() );
      Serial.println(" : retrying in 5 seconds]");
      delay(5000);
      retryMQTT++;
      if (retryMQTT > 10) {
        Serial.println("Rebooting.....");
        ESP.restart();

      }
    }
  }
}




void startWIFI(void) {
  int totalTries = 0;
  byte ESP_IP[4];
  ESP_IP[0] = 192;
  ESP_IP[1] = 168;
  ESP_IP[2] = 1;

  if (ipAddress > 254) ipAddress = 200;
  ESP_IP[3] = ipAddress;


  IPAddress ip(192, 168, 1, 200);
  IPAddress gateway(192, 168, 1, 254);
  IPAddress subnet(255, 255, 255, 0);
  IPAddress dns1(8,8,8,8);   // add DNS 
  IPAddress dns2(8,8,4,4);   // add DNS 

  //Start
  if (errorWifi == true) Serial.print("IP: ");
  if (errorWifi == true) Serial.println(ip);
  if (errorWifi == true) Serial.print("Gateway: ");
  if (errorWifi == true) Serial.println(gateway);
  if (errorWifi == true) Serial.print("Subnet: ");
  if (errorWifi == true) Serial.println(subnet);

  WiFi.mode(WIFI_STA);
  //WiFi.config(ip, gateway, subnet, dns);
  //WiFi.config(ip, gateway, subnet, dns1, dns2 );
  WiFi.begin(ssid, passphrase);
  

  wifi_Connected = false;
  bool leaveLoop = false;

  while ((WiFi.localIP().toString() == "0.0.0.0" || WiFi.status() == 6) && leaveLoop == false) {
    totalTries++;
    if (errorWifi == true) Serial.print(".");
    delay(100);
    if (totalTries > 30) {
      leaveLoop = true;
    }
  }

  if (leaveLoop == true) {
    wifi_Connected = false;
    if (errorWifi == true) Serial.println("WiFi could not connect");
  }



  if (WiFi.status() == 3) {
    if (errorWifi == true) Serial.println("");
    if (errorWifi == true) Serial.println("Connected");
    ip = WiFi.localIP();
    if (errorWifi == true) Serial.println(ip);
    wifi_Connected = true;
    WiFi.setAutoReconnect(true);
    WiFi.persistent(true);
  }
}
