#include <stdio.h>
#include <stdlib.h>
 
struct node {
  struct node *next;
  int x;
};
 
int main()
{
    /* This won't change, or we would lose the list in memory */
    struct node *root=0;       
    /* This will point to each node as it traverses the list */
    struct node *conductor=0;  
    printf("size of node is %ld\n",sizeof(struct node));
    root = malloc( sizeof(struct node) );
    if(!root) {
        fprintf(stderr,"malloc failed\n");
        return 1;
    }
    root->next = 0;   
    root->x = 12;
    conductor = root; 
    if ( conductor != 0 ) {
        while ( conductor->next != 0)
        {
            conductor = conductor->next;
        }
    }
    /* Creates a node at the end of the list */
    conductor->next = malloc( sizeof(struct node) );  
 
    conductor = conductor->next; 
 
    if ( conductor == 0 )
    {
        fprintf( stderr,"Out of memory" );
        return 2;
    }
    /* initialize the new memory */
    conductor->next = 0;         
    conductor->x = 42;
 
    return 0;
}
