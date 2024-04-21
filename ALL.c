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
void llAppend(char info, node_t *ll);
node_t *llFinal(node_t *ll);
void llReader(node_t *ll);


int main(int argc, char *argv[])
{
    node_t *ll = llInit('c');

    llAppend('a', ll);
    llAppend('m', ll);
    llReader(ll);
    
    free(ll);
    return(0);
}


/* Create a new linked list. */
node_t *llInit(char info)
{
    node_t *ll = malloc(NODESIZE);
    ll->data = info;
    ll->next = ll;
    ll->prev = ll;
    
    return(ll);
}

/* Append to an existsing linked list. */
void llAppend(char info, node_t *ll)
{
    node_t *node = malloc(NODESIZE);
    node_t *llEnd = llFinal(ll);

    node->data = info;
    node->next = ll;

    node->prev = llEnd;
    llEnd->next = node;
}

/* So the idea for this guy is to store the address
   of the first index of the ll, and then assume whatever
   node has a pointer to that address is the final node.

   Then, we return a pointer to that final node.
*/
node_t *llFinal(node_t *ll)
{
    node_t *nextNode = ll->next;
    while(nextNode != ll) nextNode = nextNode->next;
    return(nextNode);
}

/* Prints out a linked list. */
void llReader(node_t *ll)
{
    for(node_t *nextNode = ll; nextNode->next != ll; nextNode = nextNode->next) printf("%c\n", nextNode->data);
}
