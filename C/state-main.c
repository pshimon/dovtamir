#include "state.h"
 
int main()
{
        struct state s;
        init_state(&s);
        sprintf(s.name,"Israel");
        sprintf(s.capital,"Jerusalem");
        print_state(&s);
    return 0;
}

