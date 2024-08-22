#include "main.h"

int main()
{
    Node * node ;
    node = CreateList();
    Append(node , 10);
    Append(node , 20);
    Append(node , 30);
    Insert(node , 1 , 50);
    PrintList(node);
    printf("element index 1: %d\n" , GetElement(node , 2));

   
    printf("\nAfter Edit: \n");
    Edit(node , 5 , 80 );
    PrintList(node);

    
    DistroyList(node);
    return 0;
}


Node * CreateList(void)
{
    Node * main_node ; // first main_node in the list 
    main_node = (Node*)malloc(sizeof(Node));
    main_node->Index = -1 ;// index zero - first element 
    main_node->Next = NULL ;
    main_node->Prev = NULL ;
    return main_node ;
}

void Insert(Node * main_node , int Index , Data data)
{
    if(Index >= 0)
    {
        if(main_node != NULL)
        {
            if(main_node->Index == -1)
            {
                main_node->data = data;
                main_node->Index = 0 ;
            }
            else 
            {
                Node * CurrentNode = main_node ;
                while (CurrentNode->Index != Index && CurrentNode->Next !=NULL)
                {
                    CurrentNode = CurrentNode->Next ;
                }   
                if(CurrentNode->Index == Index)
                {
                    if(CurrentNode->Next == NULL) // last node so append 
                    {
                        Append(main_node , data);
                    }
                    else 
                    {
                        Node * NewNode ;
                        NewNode = (Node*)malloc(sizeof(Node));
                        NewNode->Prev = CurrentNode ;
                        CurrentNode->Next->Prev = NewNode ;
                        NewNode->Next = CurrentNode->Next ;
                        CurrentNode->Next = NewNode ;
                        NewNode->data = data ;
                        NewNode->Index = (NewNode->Prev->Index + 1) ;
                        //free(NewNode);
                    }
                }
                else 
                {
                    printf("Not Found!");
                }
               

            }
        }
        else 
        {
            printf("Create List First then add the data!\n");
        }
    }
    else 
    {
        printf("Invalid Index");
    }
}

void Delete(Node * main_node , int Index)
{
 if(Index >= 0)
    {
        if(main_node != NULL)
        {
            Node * CurrentNode = main_node ;
            while (CurrentNode->Index != Index && CurrentNode->Next !=NULL)
            {
                CurrentNode = CurrentNode->Next ;
            }              
            if(CurrentNode->Index == Index)
            {
                if(CurrentNode->Next == NULL)
                {
                    //delete last node 
                    CurrentNode->Prev->Next = NULL;
                }
                else if(Index == 0)
                {
                    printf("Can't delete first node");
                }
                else 
                {
                    CurrentNode->Prev->Next = CurrentNode->Next;
                    CurrentNode->Next->Prev = CurrentNode->Prev;
                    while (CurrentNode->Next !=NULL)
                    {
                        CurrentNode = CurrentNode->Next;
                        CurrentNode->Index--;
                    }
                    CurrentNode->Next = NULL ;
                    CurrentNode->Prev = NULL;
                    free(CurrentNode);
                }
                
            }
            else 
            {
                printf("Not Found!");
            }

            
        }
        else 
        {
            printf("No Lists to delete!\n");
        }
    }
    else 
    {
        printf("Invalid Index");
    }
}

void Append(Node * main_node , Data data)
{
    if(main_node != NULL) // no lists here 
    {

        if(main_node->Index == -1)//first node - so add the first data to it 
        {
            main_node->data = data;
            main_node->Index = 0 ;
        }
        else 
        {
            Node * NewNode ;
            NewNode = (Node*)malloc(sizeof(Node));
            Node * CurrentNode = main_node ; //counter 
            while (CurrentNode->Next != NULL)
            {
            // printf("%d" , CurrentNode->data);
            CurrentNode = CurrentNode->Next ;
            }   
            NewNode->Prev = CurrentNode ;
            CurrentNode->Next = NewNode ;
            NewNode->Next = NULL ;
            NewNode->data = data ;
            NewNode->Index = (NewNode->Prev->Index + 1) ;
        }
    }
    else 
    {
        printf("Create List First then add the data!\n");
    }
}

void Edit(Node * main_node , int Index , Data Newdata)
{
 if(Index >= 0)
    {
        if(main_node != NULL)
        {
            if(main_node->Index == -1)
            {
                main_node->data = Newdata;
                main_node->Index = 0 ;
            }
            else 
            {
                Node * CurrentNode = main_node ;
                while (CurrentNode->Index != Index && CurrentNode->Next !=NULL)
                {
                    CurrentNode = CurrentNode->Next ;
                }   
                if(CurrentNode->Index == Index)
                {
                    CurrentNode->data = Newdata ;

                    /*
                    if(CurrentNode->Next == NULL) // last node so append 
                    {
                        Append(main_node , data);
                    }
                    else 
                    {
                        Node * NewNode ;
                        NewNode = (Node*)malloc(sizeof(Node));
                        NewNode->Prev = CurrentNode ;
                        CurrentNode->Next->Prev = NewNode ;
                        NewNode->Next = CurrentNode->Next ;
                        CurrentNode->Next = NewNode ;
                        NewNode->data = data ;
                        NewNode->Index = (NewNode->Prev->Index + 1) ;
                    }*/
                }
                else 
                {
                    printf("Not Found!");
                }

            }
        }
        else 
        {
            printf("Create List First then add the data!\n");
        }
    }
    else 
    {
        printf("Invalid Index");
    }
}

Data GetElement(Node * main_node , int Index)
{
    Data data = -1 ;
    if(Index < 0)
    {
        printf("Invalid index!\n");
    }
    else 
    {   
        Node * CurrentNode = main_node ;
        while (CurrentNode->Index != Index)
        {
            CurrentNode = CurrentNode->Next ;
        }
        if(CurrentNode->Index == Index)
        {
            data = CurrentNode->data ;
        }
    }
    return data ;
}

void PrintList(Node * main_node)
{
    Node * CurrentNode = main_node ; //counter 
    while (CurrentNode != NULL)
    {
        printf("\n%d\n" , CurrentNode->data);
        CurrentNode = CurrentNode->Next;
    }
}

void DistroyList(Node * main_node)
{
    Node * CurrentNode = main_node ; //counter 
    Node * next = main_node ;
    while (next != NULL)
    {
        next = CurrentNode->Next ;
        free(CurrentNode);
        CurrentNode = next;
    }
}