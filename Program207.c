#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE, * PNODE, **PPNODE;

void Display(PNODE Head)
{
    while (Head != NULL)
    {
        printf("|%d| -> ",Head->data);
        Head = Head -> next;
    }

    printf(" NULL\n");
}

int Count(PNODE Head)
{
    int iCnt = 0;

    while(Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }

    return iCnt;
}

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head, int no)
{
    PNODE newn = NULL;
    PNODE temp = *Head;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }

}

void DeleteFirst(PPNODE Head)
{
    PNODE temp = *Head;

    if(*Head != NULL)
    {
        *Head = (*Head)->next;
        free(temp);
    }

}

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;

    if(*Head == NULL)
    {
        return;
    }
    else if((*Head) ->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }

}

int main()
{
    PNODE first = NULL;

    int iChoice = 1, value = 0, iRet = 0, pos = 0;

    while(iChoice != 0)
    {
        printf("\n________________________________________\n");
        printf("Enter the desired operation that you want to perform on LinkedList\n");
        printf("1 : Insert the node at first position\n");
        printf("2 : Insert the node at last position\n");
        printf("3 : Insert the node at  the desired position\n");
        printf("4 : Delete the first node\n");
        printf("5 : Delete the last node\n");
        printf("6 : Delete the node at desired position\n");
        printf("7 : Display the contents of linked list\n");
        printf("8 : Count the number of nodes from linked list\n");
        printf("0 : Terminate the application\n");
        printf("\n________________________________________\n");

        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
                printf("Enter the data to insert\n");
                scanf("%d",&value);
                InsertFirst(&first,value);
                break;

            case 2:
                printf("Enter the data to insert\n");
                scanf("%d",&value);
                InsertLast(&first,value);
                break;

            case 3:
                printf("Enter the data to insert\n");
                scanf("%d",&value);
                printf("Enter the position\n");
                scanf("%d",&pos);
                // InsertAtPos(&first,value,pos);
                break;

            case 4:
                DeleteFirst(&first);
                break;

            case 5:
                DeleteLast(&first);
                break;

            case 6 :
                printf("Enter the position\n");
                scanf("%d",&pos);
                //DeleteAtPos(&first,pos);
                break;

            case 7:
                printf("Elemenet of Linked list are\n");
                Display(first);
                break;

            case 8:
                iRet = Count(first);
                printf("Number of elements are : %d\n",iRet);
                break;

            case 0:
                printf("Thank for using Marvellous Linked List\n");
                break;

            default:
                printf("Please enter proper choice\n");
                break;
        }
    }

    return 0;
}
