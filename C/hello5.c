#include <stdio.h>    
 
int main()                           {
    int ret;
    int age;                            
    printf( "Please enter your age" );      
    fflush(stdout);
    ret=scanf( "%d", &age );                    
    if(ret!=1) {
        fprintf(stderr,"scanf failed\n");
        return 1;
    }

    if ( age < 100 ) {                  /* If the age is less than 100 */
        printf ("You are pretty young!\n" ); /* Just to show you it works... */
    }
    else if ( age == 100 ) {            /* I use else just to show an example */
        printf( "You are old\n" );       
    }
    else {
        printf( "You are really old\n" );     /* Executed if no other statement is */
    }
    return 0;
}
