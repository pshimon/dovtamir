#include <stdio.h> 
#define ONE 1
int main()  {
    int a;
    float b;
    double c;
    int ret;
    printf( "Please enter an integer number: " );
    ret=scanf( "%d", &a );
    if(ret!=1) {
        fprintf(stderr,"scanf failed\n");
        return 1;
    }
    //printf("ret=%d\n",ret);
    printf( "You entered %d\n", a );
    printf( "Please enter an float number: " );
    ret=scanf( "%f", &b );
    if(ret!=1) {
        fprintf(stderr,"scanf failed\n");
        return 2;
    }
    /*printf("ret=%d\n",ret);*/
    printf( "You entered %f\n", b );
    printf( "Please enter an double number: " );
    ret=scanf( "%lf", &c );
    if(ret!=1) {
        fprintf(stderr,"scanf failed\n");
        return 3;
    }

    //printf("ret=%d\n",ret);
    printf( "You entered %lf\n", c );

    return 0;
}
