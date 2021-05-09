#define ABTN_PIN     7
#define BBTN_PIN     6

#define ABTN_REVERSE 0
#define BBTN_REVERSE 0

#define ABTN_STATE   (ABTN_REVERSE) ? ( !digitalRead(ABTN_PIN) ) : ( digitalRead(ABTN_PIN) )
#define BBTN_STATE   (BBTN_REVERSE) ? ( !digitalRead(BBTN_PIN) ) : ( digitalRead(BBTN_PIN) )

#define X_PIN        A3
#define Y_PIN        A2

#define X_REVERSE    1
#define Y_REVERSE    0

#define CLAMP_VAL_1  0
#define CLAMP_VAL_2  200

#define X_STATE      (analogRead(X_PIN)<=CLAMP_VAL_1) ? (X_REVERSE) : ( (analogRead(X_PIN)>=CLAMP_VAL_2) ? (!X_REVERSE) : (-1) )
#define Y_STATE      (analogRead(Y_PIN)<=CLAMP_VAL_1) ? (Y_REVERSE) : ( (analogRead(Y_PIN)>=CLAMP_VAL_2) ? (!Y_REVERSE) : (-1) )
