#include <stdlib.h>
#include <stdio.h>

typedef int Data ;

typedef struct Node 
{

 Data data ;
 struct Node * Link;

}Node ;

Node * Top ;
Node * CreateStack(void);
void Push(Node * main_node , Data data);
void Pop(Node * main_node);
void PrintStack();
void DestroyStack(Node * node);