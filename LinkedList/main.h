#include <stdlib.h>
#include <stdio.h>

typedef int Data ;

typedef struct Node 
{
    int Index ;
    Data data ;
    struct Node * Next ;
    struct Node * Prev ;

}Node;

Node * CreateList(void);
void Insert(Node * main_node , int Index , Data data);
void Delete(Node * main_node , int Index);
void Append(Node * main_node , Data data);
void Edit(Node * main_node , int Index , Data data);
Data GetElement(Node * main_node , int Index);
void PrintList(Node * main_node);
void DistroyList(Node * main_node);