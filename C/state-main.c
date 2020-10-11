#include "state.h"
 
int main()
{
        struct state s={0};
        sprintf(s.name,"Israel");
        sprintf(s.capital,"Jerusalem");
        sprintf(s.currency,"new shekel");
        s.type=REPUBLIC;
        s.area=22.145;
        s.population=8.884;
        print_state(&s);
    return 0;
}

