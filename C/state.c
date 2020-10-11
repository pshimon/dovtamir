#include "state.h"


int print_state(struct state *s) {
        if(!s) return -1;
        printf("name: %s\n",s->name);
        printf("capital: %s\n",s->capital);
        printf("currency: %s\n",s->currency);
        printf("population: %10.3f million\n",s->population);
        printf("area: %10.3f km^2\n",s->area);
        switch(s->type) {
                case KINGDOM :
                        printf("state type: kingdom\n");
                        break;
                case REPUBLIC:
                        printf("state type: republic\n");
                        break;
                default:
                        printf("state type: unknown\n");
        }
        return 0;
}

