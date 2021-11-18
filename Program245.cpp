#include<iostream>
#include<stdio.h>

using namespace std;

typedef struct node
{
    int data;
    struct node * next;
}NODE, *PNODE, ** PPNODE;

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = new NODE;
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

void Display(PNODE Head)
{
    while(Head != NULL)
    {
        cout<<"|"<<Head->data<<"|-> ";
        Head = Head -> next;
    }
    cout<<"\n";
}

void DisplayR(PNODE Head)
{
    if(Head != NULL)
    {
        cout<<"|"<<Head->data<<"|-> ";
        Head = Head -> next;
        DisplayR(Head);
    }
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

int CountR(PNODE Head)
{
    static int iCnt = 0;

    if(Head != NULL)
    {
        iCnt++;
        Head = Head->next;
        CountR(Head);
    }

    return iCnt;
}

int main()
{
    PNODE first = NULL;
    int iRet = 0;

    InsertFirst(&first, 101);
    InsertFirst(&first, 51);
    InsertFirst(&first, 21);
    InsertFirst(&first,11);

    DisplayR(first);

    iRet = CountR(first);

    cout<<"Number of elements are "<<iRet<<"\n";

    return 0;
}
