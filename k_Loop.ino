void loop()
{
  getEpoch();            // writes the Epoch (Numbers of seconds till 1.1.1970...
  getTimeData();
  menuRun();
  delay(10);             
  runEvery(125) //125mS
  {
    data125mSRun();
    delay(50);          // set as high as possible to save energy but low enough to get the tasks done.

    slice += 1;
    if (slice > 8) slice = 1;
    switch (slice)
    {
      case 1:
        data1SRun();
        break;
      case 3:
        displayRun();
        break;
      case 5:
        serialRun();
        break;
      case 7:
        wirelessRun();
        break;
    }

  }
  if (Second != lastSecond)
  {
    lastSecond = Second;
    // here you may  program general tasks to run every second or slower.
    strftime (charbuff, 80, " %T", timeinfo);
    yield();  Serial.println(charbuff);
  }

}
//end loop
