#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void deletefirst(struct node **head_ref)
{
    struct node *next;
    next = (*head_ref)->next;
    free(*head_ref);
    *head_ref = next;
}

void delfirst(struct node *head)
{
    struct node *tmp = head->next;
    head->data = head->next->data;
    head->next = head->next->next;
    free(tmp);
}


int main()
{
    struct node *l = NULL;
    push(&l, 1);
    push(&l, 2);
    push(&l, 3);
    push(&l, 4);
    printlist(l);
    delfirst(l);
    printlist(l);
    rmlist(&l);
    return 0;
}
