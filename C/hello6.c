#include <stdio.h>
#define N 10
int main()
{
    int j;
    double a[N];
    double *p;
    for ( j = 0; j < N; j++ ) {
        a[j]=(j+0.0)/N;
        printf( "%d %f\n", j,a[j] );
    }
    j=0;
    p=a;
    while ( j < N ) { 

        printf( "%d %f %f\n", j ,*(p+j),p[j]);
        j++;
    }
    j = 0;
    do {
        printf( "Hello, world!\n" );
    } while ( j != 0 );
}

