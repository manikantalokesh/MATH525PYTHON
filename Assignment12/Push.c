#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

void Push(const char input[30], node** top)
{
    if (*top == NULL)
    {
        *top =(node*)malloc(sizeof(struct node));
        (*top)->next = NULL;
        strcpy((*top)->value, input);
        (*top)->position = 1;
    }
    else
    {
        node* temp;
        temp =(node*)malloc(sizeof(struct node));
        temp->next = *top;
        strcpy((*top)->value, input);
        temp->position = 1;
        *top = temp;
        node* ptr = (*top)->next;
    while (ptr!=NULL)
    {
        ptr->position = ptr->position+1;
        ptr = ptr->next;
    }
    }
}