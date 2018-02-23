* http://www.toptechboy.com/arduino/lesson-22-build-an-arduino-gps-tracker/
* GPS晶片上的fix紅燈閃爍，表示正在尋找衛星，若有找到fix燈不會閃
* Adafruit_GPS.h有定義#define PGCMD_NOANTENNA "$PGCMD,33,0*6D" (因為我沒有天線)
* GPS程式理解
````
  //一直不斷讀取資料(字元)，一直到新的NMEA完整資料產生
  while (!GPS.newNMEAreceived())
  {
    c = GPS.read();    
  }
  
````
* 在Adafruit_GPS的parsing範例中，是用中斷方式一直不斷讀取資料(字元)，用意在如果你有多工的需求，用上面while的方式會在loop()卡住一些時間
