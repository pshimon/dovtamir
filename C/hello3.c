#include <stdio.h>

#ifdef _WIN32
    #pragma warning(disable : 4996)
#endif

#define ONE 1
int main()  {
    int a,b,c;
    double a1,b1,c1;
    int ret;
    printf( "Please enter 2 integer numbers:\n " );
    ret=scanf( "%d %d", &a,&b );
    if(ret!=2) {
        fprintf(stderr,"scanf failed\n");
        return 1;
    }

    c=a/b;
    printf( "%d/%d=%d\n", a,b,c );
    printf( "Please enter 2 double numbers:\n " );
    ret=scanf( "%lf %lf", &a1,&b1 );
    if(ret!=2) {
        fprintf(stderr,"scanf failed\n");
        return 2;
    }

    c1=a1/b1;
    printf( "%f/%f=%f\n", a1,b1,c1 );
    c=(int) (a1/b);
    c1=a/b1;
    printf( "%d %f\n", c,c1 );
    return 0;
}
