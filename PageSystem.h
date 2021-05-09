#ifndef __PAGESYSTEM_H__
#define __PAGESYSTEM_H__

#include "JoyStick.h"

int page = 0;

// General Route Function
void DefineRoute(int pageWhenA, int pageWhenB){
  if(ABTN_STATE == true){
    page = pageWhenA;
    delay(500);
    noTone(5);
  }
  else if(BBTN_STATE == true){
    page = pageWhenB;
    delay(500);
    noTone(5);
  }
  else{
    ;
  }
}

void JumpToRoute(int pageToJump){
  page = pageToJump;
}

#endif
