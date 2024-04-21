/* Advanced Linked List.

   The general idea for this was described in the README.
*/

#include <stdio.h>
#include <stdlib.h>

#define NODESIZE sizeof(node_t)


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
    node_t *ll = malloc(NODESIZE);
    ll->data = info;
    ll->next = ll;
    ll->prev = ll;
    
    return(ll);
}

void llAppend(char info, node_t ll)
{
    node_t *node = malloc(NODESIZE);
    note_t *llEnd = llFinal(ll);

    node->data = info;
    node->next = ll;

    node->prev = llEnd;
    llEnd->next = node;
}
