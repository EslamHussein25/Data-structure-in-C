#include "main.h"

int main()
{

    Node * node ;
    node = CreateStack();
    Push(node , 50 );
    Push(node , 60 );
    Push(node , 70 );

    PrintStack(node);

    Pop(node);
    Pop(node);
    Pop(node);

    DestroyStack(node);
    return 0;
}


Node * CreateStack(void)
{
    Node * node ;
    node = (Node*)malloc(sizeof(Node));
    node->data = -1;
    Top = node ;
    node->Link = NULL;
    return node ;
}

void Push(Node * main_node , Data data)
{
    if(main_node != NULL)
    {
        if(main_node->data == -1)
        {
            main_node->data = data ;
        }
        else 
        {
            Node * newNode = (Node*)malloc(sizeof(Node));
            newNode->Link = Top;
            Top = newNode  ;
            newNode->data = data ;
        }
    }

}

void Pop(Node * main_node)
{
    if(main_node != NULL)
    {
        if(main_node->data  == -1)
        {
            DestroyStack(main_node);
        }
        else 
        {
            Node * CurrentNode = Top ;
            Top = Top->Link ;
            free(CurrentNode);         
        }
    }
    else 
    {
        printf("No data in this stack!\n");
    }
}

void PrintStack()
{
    Node * CurrentNode = Top;
    while (CurrentNode != NULL)
    {
        printf("\n%d\n" , CurrentNode->data);
        CurrentNode = CurrentNode->Link ;
    }
}

void DestroyStack(Node * node)
{
    while (Top != NULL)
    {
        Pop(node);
    }
    Top = NULL; 
}