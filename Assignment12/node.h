#ifndef __NODE_H__
#define __NODE_H__

typedef struct node node;
struct node
{
int position;
char value[30];
node* next;
};

// Functions associated with struct node
// int GetNumberOfNodes();
void Push(const char input[30], node** top);
void Pop(node** top, char* output);
int Peek(node* top);
void GetStackSize(node* top, char* stack_size);
void DisplayStack(node* top);
void DeleteStack(node** top);
void ExecuteOption(const int option, node** top);
void DisplayOptions();
int QueryOption();





#endif