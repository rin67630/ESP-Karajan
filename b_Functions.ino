// Remember tu use the F macro: Serial.println(F(“Hello World”)); to put strings in Progmem instead of variables.

// RunEvery Macro useful for scheduling tasks.
// usage: runEvery(25){//periodical code)} to run every 25mS
#define runEvery(t) for (static uint16_t _lasttime;\
                         (uint16_t)((uint16_t)millis() - _lasttime) >= (t);\
                         _lasttime += (t))

// Constructors

#if defined(ESP8266)
// WiFiUDP ntpUDP;
#endif

#if defined(THINGER)
 #if defined(ESP8266)
  ThingerWifi thing(THINGER_USERNAME, THINGER_DEVICE, THINGER_CREDENTIALS);
 #elif defined(ESP32)
 ThingerESP32 thing(THINGER_USERNAME, THINGER_DEVICE, THINGER_CREDENTIALS);
 #endif
#endif

void getWiFi()
{
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while ( WiFi.status() != WL_CONNECTED )
  {
    delay ( 500 );
    Serial.print ( "." );
  }
  ip = WiFi.localIP();
  sprintf(charbuff, "Connected to IP: %03d.%03d.%03d.%03d", ip[0], ip[1], ip[2], ip[3]);
  Serial.println(charbuff);
}

void getNTP()
{
#if defined(ESP8266)
  configTime(MYTZ, NTP_SERVER);
#elif defined(ESP32)
  configTime(GMT_OFFSET_SEC, DAYLIGHT_OFFSET_SEC, NTP_SERVER);
#endif
  now = time(nullptr);
  Epoch = now;
}

void getEpoch()
{
  now = time(nullptr);
  Epoch = now;
}
void getTimeData()
{
  timeinfo  = localtime(&now);  // cf: https://www.cplusplus.com/reference/ctime/localtime/
  Second    = timeinfo->tm_sec;
  Minute    = timeinfo->tm_min;
  Hour      = timeinfo->tm_hour;
  Weekday   = timeinfo->tm_wday + 1 ;
  Day       = timeinfo->tm_mday;
  Month     = timeinfo->tm_mon + 1;
  Year      = timeinfo->tm_year + 1900; //returns years since 1900
  strftime (DayName , 12, "%A", timeinfo); //cf: https://www.cplusplus.com/reference/ctime/strftime/
  strftime (MonthName, 12, "%B", timeinfo);
  strftime (Time,10, "%T", timeinfo);
  strftime (Date,12, "%d/%m/%Y", timeinfo);
}


void reConnect()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin();
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(10);
    //    Serial.print(".");
  }
}

void disConnect()
{
  //  WiFi.disconnect(); //temporarily disconnect WiFi as it's no longer needed
  WiFi.mode(WIFI_OFF);
}


void myIP()
{
  sprintf(charbuff, "IP= %03d.%03d.%03d.%03d", ip[0], ip[1], ip[2], ip[3]);
}
