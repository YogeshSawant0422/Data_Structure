#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int Data;
    struct node *next;
};

typedef struct Node NODE;
typedef struct Node *PNODE;
typedef struct Node **PPNODE;

void InsertFirst(PPNODE Head , int no)
{
   PNODE newn = NULL;

   newn = (PNODE)malloc(sizeof(NODE));

   newn ->Data = no;
   newn ->next = NULL;

   if(*Head == NULL)
   {
       *Head = newn;
   }
   else
   {
        newn -> next = *Head;
        *Head = newn;
   }
}
void InsertLast(PPNODE Head , int no)
{
   PNODE newn = NULL;
   PNODE temp = *Head;

   newn = (PNODE)malloc(sizeof(NODE));

   newn ->Data = no;
   newn ->next = NULL;

   if(*Head == NULL)
   {
       *Head = newn;
   }
   else
   {
     while(temp -> next != NULL)
     {
         temp = temp -> next;
     }
      temp -> next = newn;
   }
}

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf("%d\n",Head -> Data);
        Head = Head -> next;
    }
}

int Count(PNODE Head)
{
    int iCnt = 0;

    while(Head != NULL)
    {
        iCnt++;
        Head = Head -> next;
    }
    return iCnt;
}

void DeleteFirst(PPNODE Head)
{
    PNODE temp = *Head;

    if(*Head != NULL)
    {
        *Head = (*Head) -> next;
        free(temp);
    }
}
void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;

    if(*Head == NULL) // LL is Empty
    {
        return;
    }
    else if((*Head) -> next == NULL) // LL Contains one node
    {
        free(*Head);
        *Head = NULL;
    }
    else   // LL Contains more than one node
    {
        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }
        free(temp -> next);
        temp -> next = NULL;
    }
}

int main()
{
    PNODE first = NULL;
    int iRet = 0;

    InsertFirst(&first,101);
    InsertFirst(&first,51);  //InsertFirst(50,51);
    InsertFirst(&first,21);  //InsertFirst(50,21);
    InsertFirst(&first,11);  //InsertFirst(50,11);

    InsertLast(&first,111);
    Display(first);   // Display(100)

    iRet = Count(first);

    printf("\n Number of elements are :%d\n",iRet);

    DeleteFirst(&first);

    Display(first);   // Display(100)

    iRet = Count(first);

    printf("\n Number of elements are :%d\n",iRet);

    DeleteLast(&first);

    Display(first);   // Display(100)

    iRet = Count(first);

    printf("\n Number of elements are :%d\n",iRet);

    return 0;
}
