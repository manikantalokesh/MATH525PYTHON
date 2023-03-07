#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "node.h"

void DeleteList(node** head)
{
node* temp;
while (*head!=NULL)
{
temp = *head;
*head = (*head)->next;
free(temp);
}
}