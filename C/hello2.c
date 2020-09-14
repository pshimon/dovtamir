#include <stdio.h> 
#include <math.h>

#pragma warning(disable : 4996)
#define DEAD_LEVEL 1.0
int main()  {
    int n,relative;
    float b;
    double c,d;
    int ret;
    printf( "Please enter number of strikes: " );
    ret=scanf( "%d", &n );
    if(ret!=1) {
        fprintf(stderr,"scanf failed\n");
        return 1;
    }
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

    //printf("ret=%d\n",ret);
    printf( "You entered %lf\n", c );
    if(relative) {
    d=pow(1.0-b,n)*c;
    } else {
        d=c-n*b;
    }
    printf( "after %d strikes you have %f life power\n",n,d);
    if(d<DEAD_LEVEL ) {
        printf("Dead!\n");
    } else {
        printf("Alive!\n");
    }

    return 0;
}
