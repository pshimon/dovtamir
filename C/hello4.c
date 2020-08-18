#include <stdio.h> 
#define ONE 1
int main()  {
    int a,b,c,d;
    double a1,b1,c1;
    printf( "Please enter 2 integer numbers: " );
   d=scanf( "%d %d", &a,&b );
   if(d!=2) {
       fprintf(stderr,"scanf failed\n");
       return 1;
   }
    c=a/b;
    printf( "%d/%d=%d\n", a,b,c );
    printf( "Please enter 2 double numbers: " );
    d=scanf( "%lf %lf", &a1,&b1 );
     if(d!=2) {
       fprintf(stderr,"scanf failed\n");
       return 2;
   }

    c1=a1/b1;
    printf( "%f/%f=%f\n", a1,b1,c1 );
    if (c1>c) {
        printf( "%f\n", c1 );
    } else {
        printf( "%f\n", (double)c );
    }
    return 0;
}
