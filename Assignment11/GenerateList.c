#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "node.h"

void GenerateList(node** head, const int num_nodes)
{
    node* temp; 
    // srand(time(NULL));

    for (int i=0; i<num_nodes; i++)
    {
        temp = (node*)malloc(sizeof(node));
        temp->value = rand()%26+'a'; 
        temp->position = 0;
        printf("%c",temp->value);

    if (*head == NULL)
    {
        *head = temp;
        (*head)->next = NULL;
    }
    else
    {
        temp->next = *head;
        *head = temp;
    }
    }
        printf("\n");
        node* ptr = *head; 
        int pos = 1;
        while(ptr!=NULL)
    {
        ptr->position = pos;
        pos = pos+1;
        ptr = ptr->next;
    }
}