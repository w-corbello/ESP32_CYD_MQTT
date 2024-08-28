//ESP32 CYD w/Touch screen MQTT
#include <EEPROM.h>
#include <PubSubClient.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include "defintions.h"
#include <XPT2046_Touchscreen.h>

#include <WiFi.h>


WiFiClient espClient;
PubSubClient client(espClient);

TFT_eSPI tft = TFT_eSPI();
SPIClass touchscreenSPI = SPIClass(VSPI);
XPT2046_Touchscreen touchscreen(XPT2046_CS, XPT2046_IRQ);

#include "buttonDraw.h"
#include "checkButtons.h"
#include "lightOutOpt.h"
#include "wifi_1.h"
#include "mqqt_1.h"

#include "time.h"


//Time
void printLocalTime() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    timeFailed = true;
    newFailedTime = 0;
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");



  strftime(timeWeekDay, 10, "%A", &timeinfo);
  strftime(timeMonth, 4, "%B", &timeinfo);
  strftime(timedate, 3, "%d", &timeinfo);
  strftime(timeHour, 3, "%I", &timeinfo);
  strftime(timeMin, 3, "%M", &timeinfo);


  drawInfo();

}







void setup() {
  Serial.begin(115200);
  EEPROM.begin(20);
  delay(150);



  touchscreenSPI.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
  touchscreen.begin(touchscreenSPI);
  // Set the Touchscreen rotation in landscape mode
  // Note: in some displays, the touchscreen might be upside down, so you might need to set the rotation to 3: touchscreen.setRotation(3);
  touchscreen.setRotation(1);

  // Start the tft display
  tft.init();
  // Set the TFT display rotation in landscape mode
  tft.setRotation(1);

  // Clear the screen before writing to it
  tft.fillScreen(TFT_BLACK);



  // Draw button
  drawButtonsScreenOne();       //screen 1


  pinMode(CYD_LED_GREEN, OUTPUT);
  pinMode(CYD_LED_RED, OUTPUT);
  pinMode(CYD_LED_BLUE, OUTPUT);

  digitalWrite(CYD_LED_RED, HIGH);
  digitalWrite(CYD_LED_GREEN, HIGH);
  digitalWrite(CYD_LED_BLUE, HIGH);


  startWIFI();                          //wifi_1.h: line 29
  if (errorWifi == true) Serial.print("WiFi Status: ");
  if (errorWifi == true) Serial.println(WiFi.status());


  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  // Variables to save date and time
  const char* ntpServer = "pool.ntp.org";
  const long  gmtOffset_sec = -21600;
  const int   daylightOffset_sec = 3600;

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  

  Serial.print("Version: ");
  Serial.println("ESP32_Touch_MQTT_08282024.002");


}

void checkTouchPoints() {
  // Get Touchscreen points
  TS_Point p = touchscreen.getPoint();
  // Calibrate Touchscreen points with map function to the correct width and height
  x = map(p.x, 200, 3700, 1, SCREEN_WIDTH);
  y = map(p.y, 240, 3800, 1, SCREEN_HEIGHT);
  z = p.z;

  checkBUTTON_1();
  checkBUTTON_2();
  checkBUTTON_3();
  checkBUTTON_4();
  checkBUTTON_5();
  checkBUTTON_6();
  checkBUTTON_7();
  checkBUTTON_8();
  checkBUTTON_9();
  checkBUTTON_10();


}






// Clock***********************************************************************************************************
void doClock() {
  timeNow = millis() ;                // the number of milliseconds that have passed since boot

  if (timeNow - timeLast >= 1000) {
    timeLast = timeNow;              //save current time
    waitTime++;
    newTime++;
    newFailedTime++;

    if (newFailedTime > 10) {
      newFailedTime = 0;
      timeFailed = false;
      printLocalTime();
    }

    if (waitTime > 60) {
      waitTime = 0;
      publishSignal();
      timeFailed = false;
      printLocalTime();
    }

    if (newTime > 300) {
      newTime = 0;
      getTimeNow = true;
    }






  }


}//End of doClock routine******************************************************************************


void runCommand() {
  if (buttonValue == 1) {
    client.publish(MQTT_STATE_TOPIC_1, Button_ON, true);
    buttonValue = 0;
    publish_now = false;
    client.loop();
  }
  if (buttonValue == 6) {
    client.publish(MQTT_STATE_TOPIC_1, Button_OFF, true);
    buttonValue = 0;
    publish_now = false;
    client.loop();
  }

  if (buttonValue == 2) {
    client.publish(MQTT_STATE_TOPIC_2, Button_ON, true);
    buttonValue = 0;
    publish_now = false;
    client.loop();
  }
  if (buttonValue == 7) {
    client.publish(MQTT_STATE_TOPIC_2, Button_OFF, true);
    buttonValue = 0;
    publish_now = false;
    client.loop();
  }

  if (buttonValue == 3) {
    client.publish(MQTT_STATE_TOPIC_3, Button_ON, true);
    buttonValue = 0;
    publish_now = false;
    client.loop();
  }
  if (buttonValue == 8) {
    client.publish(MQTT_STATE_TOPIC_3, Button_OFF, true);
    buttonValue = 0;
    publish_now = false;
    client.loop();
  }

  if (buttonValue == 4) {
    client.publish(MQTT_STATE_TOPIC_4, Button_ON, true);
    buttonValue = 0;
    publish_now = false;
    client.loop();
  }
  if (buttonValue == 9) {
    client.publish(MQTT_STATE_TOPIC_4, Button_OFF, true);
    buttonValue = 0;
    publish_now = false;
    client.loop();
  }

  if (buttonValue == 5) {
    client.publish(MQTT_STATE_TOPIC_5, Button_ON, true);
    buttonValue = 0;
    publish_now = false;
    client.loop();
  }
  if (buttonValue == 10) {
    client.publish(MQTT_STATE_TOPIC_5, Button_OFF, true);
    buttonValue = 0;
    publish_now = false;
    client.loop();
  }
}






void loop() {
  // Checks if Touchscreen was touched, and prints X, Y and Pressure (Z) info on the TFT display and Serial Monitor
  if (touchscreen.tirqTouched() && touchscreen.touched()) {
    checkTouchPoints();
  }



  if (buttonPressed == true) {
    buttonPressed = false;
    runCommand();
  }



  doClock();

  if (!client.connected()) {
    reconnect();
  }
  client.loop();


  if (getTimeNow == true) {
    printLocalTime();
    getTimeNow = false;
  }


}
