#include <stdio.h> 
#define ONE 1
int main()  {
    int a,b,c;
    double a1,b1,c1;
    printf( "Please enter 2 integer numbers: " );
    scanf( "%d %d", &a,&b );
    c=a/b;
    printf( "%d/%d=%d\n", a,b,c );
    printf( "Please enter 2 double numbers: " );
    scanf( "%lf %lf", &a1,&b1 );
    c1=a1/b1;
    printf( "%f/%f=%f\n", a1,b1,c1 );
    c=a1/b;
    c1=a/b1;
    printf( "%d %f\n", c,c1 );
    return 0;
}
