#ifndef STATE_H
#define STATE_H
#include "cdefs.h"
enum STATE_TYPE{
        KINGDOM,   //0
        REPUBLIC,  //1
        NUM_OF_STATE_TYPE  //2
};

struct state {
  struct state *next;
  double area;
  int type;  // STATE_TYPE
  char name[16];
  char capital[16];
};
int init_state(struct state *s);
int print_state(struct state *s);
#endif

