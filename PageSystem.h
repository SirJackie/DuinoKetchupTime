int page = 0;

// General Route Function
void DefineRoute(int pageWhenA, int pageWhenB){
  if(ABTN_STATE == true){
    page = pageWhenA;
    delay(500);
  }
  else if(BBTN_STATE == true){
    page = pageWhenB;
    delay(500);
  }
  else{
    ; // Do Nothing
  }
}
