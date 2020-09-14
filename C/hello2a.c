#include <stdio.h> 
#include <math.h>

#ifdef _WIN32
    #pragma warning(disable : 4996)
#endif

#define DEAD_LEVEL 1.0
int main()  {
    int n,relative;
    float b;
    double c;
    int ret;
    printf( "Please enter type  of strike (>0 relative, 0 absolute: " );
    ret=scanf( "%d", &relative );
    if(ret!=1) {
        fprintf(stderr,"scanf failed\n");
        return 1;
    }
    printf( "Please enter damage per strake: " );
    ret=scanf( "%f", &b );
    if(ret!=1) {
        fprintf(stderr,"scanf failed\n");
        return 2;
    }
    printf( "Please enter life power: " );
    ret=scanf( "%lf", &c );
    if(ret!=1) {
        fprintf(stderr,"scanf failed\n");
        return 3;
    }

    if(relative) {
        n=(int) (log(DEAD_LEVEL/c)/log(1.0-b))+1;
    } else {
        n=(int) ((c-DEAD_LEVEL)/b)+1;
    }
    printf("you need %d strikes to kill\n",n);
    return 0;
}
