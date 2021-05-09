#include <U8g2lib.h>
#include "Joystick.h"
#include "PageSystem.h"
#include "MakeSound.h"


/// Global Variables
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ 16, /* data=*/ 17);








// Pages
void IndexPage(){
  u8g2.drawStr(15, 15, "Timer");
  u8g2.drawStr(15, 31, "Press A: 52min");
  u8g2.drawStr(15, 49, "Press B: 17min");
  DefineRoute(1, 2);
}

void AKeyPage(){
  u8g2.drawStr(15, 15, "AKey Pressed");
  DefineRoute(0, 2);
}

void BKeyPage(){
  u8g2.drawStr(15, 15, "BKey Pressed");
  DefineRoute(1, 0);
}








// Setup Function
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  u8g2.begin();
  u8g2.setFont(u8g2_font_wqy15_t_chinese1);
  u8g2.setFontDirection(0);
}


// Loop Function
void loop() {
  // put your main code here, to run repeatedly:
  u8g2.firstPage();
  do {
    if(page == 0){
      IndexPage();
    }
    else if(page == 1){
      AKeyPage();
    }
    else if(page == 2){
      BKeyPage();
    }
  } while ( u8g2.nextPage() );
}
