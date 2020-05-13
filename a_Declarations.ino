#if defined(ESP8266)
#include <ESP8266WiFi.h>  // default from Espressif
//#include <WiFiUdp.h>      // default from Espressif
#include <TZ.h>           // default from Espressif 
#elif defined(ESP32)
#include <WiFi.h>         // defaults from Espressif
#include <time.h>
#endif

#define WIFI_SSID "Your SSD"
#define WIFI_PASS "Your Password"
#define HOST_NAME "ESP-IoT"
#define NTP_SERVER "de.pool.ntp.org"

// maintain for ESP32
#define TZ            1               // (utc+) TZ in hours
#define DST_MN        60              // use 60mn for summer time in some countries
#define GMT_OFFSET_SEC 3600 * TZ      // Do not change here...
#define DAYLIGHT_OFFSET_SEC 60 * DST_MN // Do not change here...
// maintain for ESP8266
#define MYTZ TZ_Europe_Paris

// Variables for Time
static int lastSecond;
byte slice;
tm*        timeinfo;                 //localtime returns a pointer to a tm structstatic int Second;
time_t     Epoch;
time_t     now;

int Second;
int Minute;
int Hour;
int Day;
int Month;
int Year;
int Weekday;
char DayName[12];
char MonthName[12];
char Time[10];
char Date[12];

static IPAddress ip;

//*** Buffers ***
static char charbuff[80];    //Char buffer for many functions
