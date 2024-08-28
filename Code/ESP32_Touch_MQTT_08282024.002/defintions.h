//debug output settings
bool errorWifi = true;  //true for serial output*************************
boolean fDebug = true;  //true for serial output*************************


// Touchscreen pins
#define XPT2046_IRQ 36   // T_IRQ
#define XPT2046_MOSI 32  // T_DIN
#define XPT2046_MISO 39  // T_OUT
#define XPT2046_CLK 25   // T_CLK
#define XPT2046_CS 33    // T_CS



#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define FONT_SIZE 2




// label position and size
#define FRAME_X 10
#define LINE0_Y 10
#define LINE1_Y 72
#define LINE2_Y 135
#define FRAME_W 60
#define FRAME_H 60
#define LBL_FRAME_H 50

// LABEL_1 size
#define LABEL_1_X FRAME_X            
#define LABEL_1_Y LINE0_Y            
#define LABEL_1_W FRAME_W
#define LABEL_1_H LBL_FRAME_H            

// LABEL_2 size
#define LABEL_2_X (LABEL_1_X +  LABEL_1_W + 2) 
#define LABEL_2_Y LINE0_Y
#define LABEL_2_W FRAME_W 
#define LABEL_2_H LBL_FRAME_H

// LABEL_3 size
#define LABEL_3_X (LABEL_2_X +  LABEL_2_W + 2) 
#define LABEL_3_Y LINE0_Y
#define LABEL_3_W FRAME_W 
#define LABEL_3_H LBL_FRAME_H

// LABEL_4 size
#define LABEL_4_X (LABEL_3_X +  LABEL_3_W + 2) 
#define LABEL_4_Y LINE0_Y
#define LABEL_4_W FRAME_W 
#define LABEL_4_H LBL_FRAME_H

// LABEL_5 size
#define LABEL_5_X (LABEL_4_X +  LABEL_4_W + 2) 
#define LABEL_5_Y LINE0_Y
#define LABEL_5_W FRAME_W 
#define LABEL_5_H LBL_FRAME_H


//*********************************************************


// BUTTON_1 size
#define BUTTON_1_X FRAME_X            
#define BUTTON_1_Y LINE1_Y            
#define BUTTON_1_W FRAME_W
#define BUTTON_1_H FRAME_H            

// BUTTON_2 size
#define BUTTON_2_X (BUTTON_1_X +  BUTTON_1_W + 2) 
#define BUTTON_2_Y LINE1_Y
#define BUTTON_2_W FRAME_W 
#define BUTTON_2_H FRAME_H

// BUTTON_3 size
#define BUTTON_3_X (BUTTON_2_X +  BUTTON_2_W + 2) 
#define BUTTON_3_Y LINE1_Y
#define BUTTON_3_W FRAME_W 
#define BUTTON_3_H FRAME_H

// BUTTON_4 size
#define BUTTON_4_X (BUTTON_3_X +  BUTTON_3_W + 2) 
#define BUTTON_4_Y LINE1_Y
#define BUTTON_4_W FRAME_W 
#define BUTTON_4_H FRAME_H

// BUTTON_5 size
#define BUTTON_5_X (BUTTON_4_X +  BUTTON_4_W + 2) 
#define BUTTON_5_Y LINE1_Y
#define BUTTON_5_W FRAME_W 
#define BUTTON_5_H FRAME_H



// second row

// BUTTON_6 size
#define BUTTON_6_X FRAME_X
#define BUTTON_6_Y LINE2_Y
#define BUTTON_6_W FRAME_W 
#define BUTTON_6_H FRAME_H


// BUTTON_7 size
#define BUTTON_7_X (BUTTON_6_X +  BUTTON_6_W + 2) 
#define BUTTON_7_Y LINE2_Y
#define BUTTON_7_W FRAME_W 
#define BUTTON_7_H FRAME_H

// BUTTON_8 size
#define BUTTON_8_X (BUTTON_7_X +  BUTTON_7_W + 2) 
#define BUTTON_8_Y LINE2_Y
#define BUTTON_8_W FRAME_W 
#define BUTTON_8_H FRAME_H

// BUTTON_9 size
#define BUTTON_9_X (BUTTON_8_X +  BUTTON_8_W + 2) 
#define BUTTON_9_Y LINE2_Y
#define BUTTON_9_W FRAME_W 
#define BUTTON_9_H FRAME_H

// BUTTON_10 size
#define BUTTON_10_X (BUTTON_9_X +  BUTTON_9_W + 2) 
#define BUTTON_10_Y LINE2_Y
#define BUTTON_10_W FRAME_W 
#define BUTTON_10_H FRAME_H






// RGB LED Pins
#define CYD_LED_BLUE  17
#define CYD_LED_RED   4
#define CYD_LED_GREEN 16





//***********************************************************************


const char* mqtt_server = "192.168.X.XXX";                          //change it for your MQTT server IP or network name
int                     mqttPort            = 1883;                 //1883 is the default port for MQTT. Change if necessary
char                    deviceId[]          = "touch-001";          //every device should have a different name
char                    temp[50];
char                    topic[]             = "/touch-001/command"; //these topics should be different for each device as well
const char*             MQTT_STATE_TOPIC_1  = "/touch-001/status_1";
const char*             MQTT_STATE_TOPIC_2  = "/touch-001/status_2";
const char*             MQTT_STATE_TOPIC_3  = "/touch-001/status_3";
const char*             MQTT_STATE_TOPIC_4  = "/touch-001/status_4";
const char*             MQTT_STATE_TOPIC_5  = "/touch-001/status_5";
const char*             MQTT_SIGNAL_TOPIC   = "/touch-001/signal";
unsigned long           lastOperation;
const long              MIN_OPERATION_INTERVAL  = 2000L;
boolean                 publish_now               = false;
long                    rssi;
const char*             Button_ON                  = "ON";
const char*             Button_OFF                = "OFF";
char                    mqttUser[]                = "MWTT_USER";
char                    mqttPassword[]            = "MWTT_PASSWORD";


char timeHour[3];
char timeMin[3];
char timeWeekDay[10];
char timeMonth[4];
char timedate[3];

// Touchscreen coordinates: (x, y) and pressure (z)
static int x, y, z;
static int buttonValue = 0;
static int curScreen = 0;
static int waitTime = 0;
static int newTime = 0;
static int newFailedTime = 0;
static int ipAddress = 0;

bool readypublishSignal = false;
bool buttonPressed = false;
bool getTimeNow = true;
bool timeFailed = false;
bool wifi_Connected = false;

//time
unsigned long timeNow = 0;
unsigned long timeLast = 0;
unsigned long startTime = 0;
unsigned long endTime = 0;
//time
