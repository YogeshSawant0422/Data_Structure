#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void Insert_First(struct Node**, int);
void Delete_First(struct Node**);

void Display_LL(struct Node*);

struct Node
{
    int Data;
    struct Node *Next;
};

int main()
{
    struct Node *Head = NULL;

    Delete_First(&Head);

    Insert_First(&Head, 11);
    Delete_First(&Head);

    Display_LL(Head);
    getch();

    Insert_First(&Head, 45);
    Insert_First(&Head, 21);

    Display_LL(Head);
    getch();

    Delete_First(&Head);
    Delete_First(&Head);
    Display_LL(Head);
    getch();

    Insert_First(&Head, 75);
    Insert_First(&Head, 56);

    Display_LL(Head);
    getch();

    Delete_First(&Head);
    Delete_First(&Head);

    Display_LL(Head);

    getch();
    return 0;
}

void Insert_First(struct Node **First, int Ele)
{
    struct Node *NewN = NULL;

    NewN = (struct Node*) malloc (sizeof(struct Node));

    if(NULL == NewN)
    {
        printf("\n\n Node Creation Denied, Some Memory Level Issue..");
        return;
    }

    NewN -> Data = Ele;
    NewN -> Next = NULL;

    if( NULL == *First )
    {
        *First = NewN;
    }
    else
    {
        NewN -> Next = *First;
        *First = NewN;
    }

    return;
}

void Display_LL(struct Node* First)
{
    if( NULL == First )
    {
        printf("\n\n Link List is already Empty, No Element to Display!!!");
    }
    else
    {
        printf("\n\n Elements in Link List are => \n\n\t ");
        while(First != NULL)
        {
            printf("  | %d | -> ",First->Data );

            First = First -> Next;
        }
        printf("  NULL");
    }

    return;
}

void Delete_First( struct Node** First )
{
    struct Node *Temp = *First;

    if( NULL == *First )
    {
        printf("\n\n Link list is already empty, No element to delete...\n ");
        return;
    }

    if( NULL == Temp -> Next )
    {
        *First = NULL;
    }
    else
    {
        *First = Temp -> Next;
    }

    printf("\n\n Removed Element From Link List is = %d.\n", Temp->Data);
    free(Temp);

    return;
}
