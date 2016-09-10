/*
    Experiments on linked lists (for educational purposes)
    Copyright (C) 2016 Yagmur Oymak

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
