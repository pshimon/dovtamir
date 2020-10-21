#ifndef STATE_H
#define STATE_H
#include "cdefs.h"
typedef char Str[16];

enum STATE_TYPE{
        UNKNOWN, //0
        KINGDOM,   //1
        REPUBLIC,  //2
        NUM_OF_STATE_TYPE  //3
};

typedef struct _State {
//  State *next;
  double area;
  double population;
  int type;  // STATE_TYPE
 // char name[16];
 Str name;
 // char capital[16];
 Str capital;
 // char currency[16];
 Str currency;
} State;

typedef struct _State_array {
        int n;//the length of array
        State *data;//[n]
} State_array;

int print_state(State *s);
#endif

