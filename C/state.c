#include "state.h"

int init_state(struct state *s) {
        if(!s) return -1;
        s->next=0;
        s->type=0;
        s->area=0;
        return 0;
}

int print_state(struct state *s) {
        if(!s) return -1;
        printf("name: %s\n",s->name);
        printf("capital: %s\n",s->capital);
        printf("area: %f\n",s->area);
        switch(s->type) {
                case KINGDOM :
                        printf("state type: kingdom");
                        break;
                case REPUBLIC:
                        printf("state type: republic");
                        break;
                default:
                        printf("state type: unknown");
        }
        return 0;
}

