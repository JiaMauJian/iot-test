#include "U8glib.h"

// setup u8g object, please remove comment from one of the following constructor calls
// IMPORTANT NOTE: The following list is incomplete. The complete list of supported 
// devices with all constructor calls is here: http://code.google.com/p/u8glib/wiki/device
U8GLIB_ST7920_128X64_1X u8g( 12, 11, 10);	// SPI Com: SCK = en = 18, MOSI = rw = 16, CS = di = 17
U8GLIB_ST7920_128X64_1X u8g2( 7, 6, 5);	// SPI Com: SCK = en = 18, MOSI = rw = 16, CS = di = 17

String strMachineNo;
char cMachineNo[3];
String strBinNo;
char cBinNo[3];
String strBinInfo;
char cBinInfo[7];

//bin+eff+color
//01168 DB02192 MB03170 SB04172 DB
String data = "^^Hello ^^Hello ^^Hello ^^Hello ";

void draw1() { 
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_fub25);  
  u8g.drawStr( 5, 30, cBinInfo);
  u8g.drawStr( 45, 65, cBinNo);   
  
  u8g.setFont(u8g_font_5x7);
  u8g.drawStr( 0, 60, cMachineNo);   
}

void draw2() {  
  // graphic commands to redraw the complete screen should be placed here  
  u8g2.setFont(u8g_font_fub25);  
  u8g2.drawStr( 5, 30, cBinInfo);
  u8g2.drawStr( 45, 65, cBinNo);   
  
  u8g2.setFont(u8g_font_5x7);
  u8g2.drawStr( 0, 60, cMachineNo); 
}

void setup(void) {
  
  Serial.begin(9600);
  Serial.println("Hello Serial");

  Serial1.begin(9600);
  Serial1.println("Hello Serial1");

  Serial2.begin(9600);
  Serial2.println("Hello Serial2");
  
  Serial3.begin(9600);
  Serial3.println("Hello Serial3");
  
  pinMode( 13, OUTPUT);   // LED
  
  //pinMode(  9, OUTPUT);
  //digitalWrite( 9, HIGH );  // Select pin must be high
  
  // flip screen, if required
  u8g.setRot180();
  
  u8g2.setRot180();
  
  // set SPI backup if required
  //u8g.setHardwareBackup(u8g_backup_avr_spi);

  // assign default color value
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
  
  if ( u8g2.getMode() == U8G_MODE_R3G3B2 ) {
    u8g2.setColorIndex(255);     // white
  }
  else if ( u8g2.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g2.setColorIndex(3);         // max intensity
  }
  else if ( u8g2.getMode() == U8G_MODE_BW ) {
    u8g2.setColorIndex(1);         // pixel on
  }
  else if ( u8g2.getMode() == U8G_MODE_HICOLOR ) {
    u8g2.setHiColorByRGB(255,255,255);
  }
}

void loop(void) {
  
  /* Blink the LED */
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(500);              // wait for a second 
  
  /* Send a message */
  if (Serial.available()) {
    data = Serial.readStringUntil('\n');
    Serial.print("Serial rev: "); 
    Serial.println(data); 
  }   
//  if (Serial.available()) {
//    String str = Serial.readStringUntil('\n');
//    Serial.print("Serial rev: "); 
//    Serial.println(data); 
//  }   
//  if (Serial1.available()) {
//    String str = Serial1.readStringUntil('\n');
//    Serial.print("Serial1 rev: "); 
//    Serial.println(str); 
//  }   
//  if (Serial2.available()) {
//    String str = Serial2.readStringUntil('\n');
//    Serial.print("Serial2 rev: "); 
//    Serial.println(str); 
//  }   
//  if (Serial3.available()) {
//    String str = Serial3.readStringUntil('\n');
//    Serial.print("Serial3 rev: "); 
//    Serial.println(str); 
//  }   
//  Serial.println("Hello Serial");
  //Serial1.println("Hello Serial1");
  //Serial2.println("Hello Serial2");
  //Serial3.println("Hello Serial3");
   
   strMachineNo = "";
   if (digitalRead(30) == 1)
     strMachineNo = "#1";
   if (digitalRead(31) == 1)
     strMachineNo = "#2";
   if (digitalRead(32) == 1)
     strMachineNo = "#3";
   if (digitalRead(33) == 1)
     strMachineNo = "#4";     
   if (digitalRead(34) == 1)
     strMachineNo = "#5";     
   if (digitalRead(35) == 1)
     strMachineNo = "#6";    
   if (digitalRead(36) == 1)
     strMachineNo = "#8";     
   if (digitalRead(37) == 1)
     strMachineNo = "#7";     
     
   if (strMachineNo != "")
     strMachineNo.toCharArray(cMachineNo, strMachineNo.length()+1);
   
//    Serial3.print("30 : "); //sw1
//    Serial3.print(digitalRead(30));
//    Serial3.print(" 31 : "); //sw2
//    Serial3.print(digitalRead(31));
//    Serial3.print(" 32 : "); //sw3
//    Serial3.print(digitalRead(32));  
//    Serial3.print(" 33 : "); //sw4
//    Serial3.print(digitalRead(33));
//    Serial3.print(" 34 : "); //sw5
//    Serial3.print(digitalRead(34));
//    Serial3.print(" 35 : "); //sw6
//    Serial3.print(digitalRead(35));
//    Serial3.print(" 36 : "); //sw8
//    Serial3.print(digitalRead(36));
//    Serial3.print(" 37 : "); //sw7
//    Serial3.println(digitalRead(37));
    
  // picture loop
  u8g.firstPage();  
  do {     
    strBinNo = data.substring(0,2);
    strBinNo.toCharArray(cBinNo, strBinNo.length()+1);
    strBinInfo = data.substring(2,8);
    strBinInfo.toCharArray(cBinInfo, strBinInfo.length()+1);
    draw1();
  } while( u8g.nextPage() );
  
  u8g2.firstPage();  
  do {     
    strBinNo = data.substring(8,10);
    strBinInfo = data.substring(10,16);
    strBinNo.toCharArray(cBinNo, strBinNo.length()+1);
    strBinInfo.toCharArray(cBinInfo, strBinInfo.length()+1);
    draw2();
  } while( u8g2.nextPage() );
  
  // rebuild the picture after some delay
  //delay(50);
}

