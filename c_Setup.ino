
void setup()
{
  // Serial initialisation
  Serial.begin(115200);
  Serial.println();   Serial.println();  Serial.println();
  Serial.println(F("Here is ESP-Karajan at work,  hello Serial!"));
  slice = 1;

  // Settings for ADC
#if defined(ESP32)
  analogSetWidth(10);                           // 10Bit resolution
  analogSetAttenuation((adc_attenuation_t) 0);   // 0=0db (0..1V) 1= 2,5dB; 2=-6dB (0..2V); 3=-11dB
#endif

  getWiFi();

  getNTP();
  delay(3000);
  getEpoch();            // writes the Epoch (Numbers of seconds till 1.1.1970...
  getTimeData();         // breaks down the Epoch into discrete values.

#if defined (OFFLINE)
  Serial.println(F("Going off-line "));
  disConnect();
  Serial.println (F("Sketch is now running offline with own time"));
#endif

  // Examples with Strings
  Serial.print(F("Thanks God, it is: "));   Serial.print( DayName );
  Serial.print(F("! Date is "));   Serial.print( Date );
  Serial.print(F(" and Time is "));   Serial.println( Time );

  // Examples with a character buffer (can be used for displays as well)
  sprintf(charbuff, "Now is %02d Hour, %02d Minutes and %02d Seconds. The Epoch is: %10lu" , Hour , Minute, Second, Epoch);
  Serial.println(charbuff);
  sprintf(charbuff, "Date is %s, %02d %s %04d ", DayName , Day , MonthName, Year);
  Serial.print(charbuff);
  Serial.println();

  delay(3000);
  Serial.println(F("now 3 seconds later.."));
  getEpoch();            // writes the Epoch (Numbers of seconds till 1.1.1970...
  getTimeData();         // breaks down the Epoch into discrete values.
  Serial.print(F("Thanks God, it is: "));   Serial.print( DayName );
  Serial.print(F("! Date is "));   Serial.print( Date );
  Serial.print(F(" and Time is "));   Serial.println( Time );
}
//end Setup
