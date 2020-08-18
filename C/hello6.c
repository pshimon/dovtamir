#include <stdio.h>
int main()
{
    int x;

    for ( x = 0; x < 10; x++ ) {
        printf( "%d\n", x );
    }
    x=0;
    while ( x < 10 ) { 
        printf( "%d\n", x );
        x++;
    }
    x = 0;
    do {
        printf( "Hello, world!\n" );
    } while ( x != 0 );
}

