#include <stdio.h>
#define ARRAY_SIZE 10
int main()
{
    int j;
    double a[ARRAY_SIZE];
    double *p;
    for ( j = 0; j < ARRAY_SIZE; j++ ) {
        a[j]=(j+0.0)/ARRAY_SIZE;
        printf( "%d %f\n", j,a[j] );
    }
    j=0;
    p=a;
    while ( j < ARRAY_SIZE ) { 

        printf( "%d %f %f\n", j ,*(p+j),p[j]);
        j++;
    }
    j = 0;
    do {
        printf( "Hello, world!\n" );
    } while ( j != 0 );
    for(j = ARRAY_SIZE-1; j>=0; j--){
            printf( "%d %f\n",j,a[j]);
    }
}

