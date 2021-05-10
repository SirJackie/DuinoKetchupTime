#include <U8g2lib.h>
#include "Joystick.h"
#include "PageSystem.h"


/// Global Variables
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ 16, /* data=*/ 17);
int timeCount = 0;
int soundBlinkCount = 0;








void IndexPage(){
  u8g2.firstPage();
  do {
    u8g2.drawStr(15, 15, "Timer");
    u8g2.drawStr(15, 31, "Press A: 25min");
    u8g2.drawStr(15, 49, "Press B:  5min");
  } while ( u8g2.nextPage() );
  DefineRoute(1, 2);
}






void AKeyPage(){
  u8g2.firstPage();
  timeCount = 1500;
  do {
    u8g2.drawStr(15, 15, "Goal: 25 minutes");
  } while ( u8g2.nextPage() );
  
  delay(1000);
  JumpToRoute(3);
}






void BKeyPage(){
  u8g2.firstPage();
  timeCount = 300;
  do {
    u8g2.drawStr(15, 15, "Goal: 5 minutes");
  } while ( u8g2.nextPage() );
  
  delay(1000);
  JumpToRoute(3);
}








void CountingPage(){
  u8g2.firstPage();

  String str = "";
  str += "Left: ";
  str += timeCount / 60;
  str += ":";
  str += timeCount % 60;
  
  do {
    u8g2.drawStr(15, 15, str.c_str());
  } while ( u8g2.nextPage() );

  timeCount -= 1;
  delay(999);

  if(timeCount <= 0){
    JumpToRoute(4);
  }

}







void SoundBlinkPage(){
  u8g2.firstPage();
  do{
    u8g2.drawStr(15, 15, "Times up!!!");
  } while ( u8g2.nextPage() );

  soundBlinkCount--;
  
  if(soundBlinkCount <= 0){
    soundBlinkCount = 5;
  }
  
  else if(soundBlinkCount < 2){
    noTone(5);
  }

  else if(soundBlinkCount <= 5){
    tone(5, 3200);
  }
  
  
  DefineRoute(0, 0);
}








// Setup Function
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  u8g2.begin();
  u8g2.setFont(u8g2_font_wqy15_t_chinese1);
  u8g2.setFontDirection(0);
//  tone(5, 6000);
}


// Loop Function
void loop() {
  // put your main code here, to run repeatedly:
  
  if(page == 0){
    IndexPage();
    return;
  }
  if(page == 1){
    AKeyPage();
    return;
  }
  if(page == 2){
    BKeyPage();
    return;
  }
  if(page == 3){
    CountingPage();
    return;
  }
  if(page == 4){
    SoundBlinkPage();
    return;
  }
  
  //blog: if's hidden continue running probelm
  //blog: don't delay during u8g2.nextPage()'s while loop
}
