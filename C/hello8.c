#include <stdio.h>   
#include <string.h>
#define STR_SIZE 50
void strip_newline( char str[], int size )
{
    int i;
 
    /* remove the null terminator */
    for (  i = 0; i < size; ++i )
    {
        if ( str[i] == '\n' )
        {
            str[i] = '\0';
 
            /* we're done, so just exit the function by returning */
            return;   
        }
    }
    /* if we get all the way to here, there must not have been a newline! */
}
 
int main()
{
    char name[STR_SIZE];
    char lastname[STR_SIZE];
    char fullname[2*STR_SIZE]; /* Big enough to hold both name and lastname */
 
    printf( "Please enter your name: " );
    fgets( name, STR_SIZE, stdin );
 
    /* see definition above */
    strip_newline( name, STR_SIZE );
 
    /* strcmp returns zero when the two strings are equal */
    if ( strcmp ( name, "Alex" ) == 0 ) 
    {
        printf( "That's my name too.\n" );
    }
    else                                    
    {
        printf( "That's not my name.\n" );
    }
    // Find the length of your name
    printf( "Your name is %ld letters long \n", strlen ( name ) );
    printf( "Enter your last name: " );
    fgets( lastname, STR_SIZE, stdin );
    strip_newline( lastname, STR_SIZE );
    fullname[0] = '\0';            
    /* strcat will look for the \0 and add the second string starting at
       that location */
    strcat( fullname, name );     /* Copy name into full name */
    strcat( fullname, " " );      /* Separate the names by a space */
    strcat( fullname, lastname ); /* Copy lastname onto the end of fullname */
    printf( "Your full name is %s\n",fullname );
 
     
    return 0;
}
