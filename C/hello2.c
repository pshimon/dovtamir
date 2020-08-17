#include <stdio.h> 
#define ONE 1
int main()  {
    int a;
    float b;
    double c;
    printf( "Please enter an integer number: " );
    scanf( "%d", &a );
    printf( "You entered %d\n", a );
    printf( "Please enter an float number: " );
    scanf( "%f", &b );
    printf( "You entered %f\n", b );
    printf( "Please enter an double number: " );
    scanf( "%lf", &c );
    printf( "You entered %lf\n", c );

    return 0;
}
