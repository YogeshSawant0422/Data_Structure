#include<iostream>
#include<stdio.h>

using namespace std;

typedef struct node
{
    int data;
    struct node* next;
}NODE,*PNODE,**PPNODE;

void InsertFirst(PNODE Head, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn -> next = *first
        *first = newn;
    }
}

int mian()
{
    PNODE first = NULL;

    InsertFirst(&first,101);
    InsertFirst(&first,51);
    InsertFirst(&first,11);

    Display(first);

    return 0;
}
