/* Advanced Linked List.

   The general idea for this was described in the README.
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct nodeStruct {
    char data;
    struct nodeStruct *next;
    struct nodeStruct *prev;
} node_t;


node_t *llInit(char info);
void llAppend(char info, node_t ll);


int main(int argc, char *argv[])
{
    node_t *ll;

    ll = llInit('c');
    free(ll);
    
    return(0);
}


node_t *llInit(char info)
{
    node_t *ll = malloc(sizeof(node_t));
    ll->data = info;
    ll->next = ll;
    ll->prev = ll;
    
    return(ll);
}

void llAppend(char info, node_t ll)
{
}
