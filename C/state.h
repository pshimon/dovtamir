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

struct state {
//  struct state *next;
  double area;
  double population;
  int type;  // STATE_TYPE
 // char name[16];
 Str name;
 // char capital[16];
 Str capital;
 // char currency[16];
 Str currency;
};

int print_state(struct state *s);
#endif

