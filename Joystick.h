#define LBTN_PIN     6
#define RBTN_PIN     7

#define LBTN_REVERSE 0
#define RBTN_REVERSE 0

#define LBTN_STATE   (LBTN_REVERSE) ? ( !digitalRead(LBTN_PIN) ) : ( digitalRead(LBTN_PIN) )
#define RBTN_STATE   (RBTN_REVERSE) ? ( !digitalRead(RBTN_PIN) ) : ( digitalRead(RBTN_PIN) )

#define ABTN_STATE   RBTN_STATE
#define BBTN_STATE   LBTN_STATE

#define X_PIN        A3
#define Y_PIN        A2

#define X_REVERSE    1
#define Y_REVERSE    0

#define CLAMP_VAL_1  0
#define CLAMP_VAL_2  200

#define X_STATE      (analogRead(X_PIN)<=CLAMP_VAL_1) ? (X_REVERSE) : ( (analogRead(X_PIN)>=CLAMP_VAL_2) ? (!X_REVERSE) : (-1) )
#define Y_STATE      (analogRead(Y_PIN)<=CLAMP_VAL_1) ? (Y_REVERSE) : ( (analogRead(Y_PIN)>=CLAMP_VAL_2) ? (!Y_REVERSE) : (-1) )
