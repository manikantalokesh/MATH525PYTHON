#include <stdio.h>
#include <stdlib.h>
#include "node.h"

GetStackSize(node* top, char* stack_size)
{
if (top==NULL)
{ *stack_size = 0; return stack_size; }

if (top->next == NULL)
{ *stack_size = top->position; return stack_size; }
GetStackSize(top->next,stack_size);
}