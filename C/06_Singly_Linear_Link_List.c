#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void Insert_First(struct Node**, int);
void Display_LL(struct Node *First);
struct Node
{
    int Data;
    struct Node *Next;
};
int main()
{
    struct Node *Head = NULL;

    Insert_First(&Head ,11);
    Insert_First(&Head,21);

    getch();
    return 0;
}
void Insert_First(struct Node **First , int Ele)
{
    struct Node *NewN = NULL;

    NewN = (struct Node*)malloc(sizeof(struct Node));

    if(NewN == NULL)
    {
        printf("\n\n Node Creation Denied , Some Memory Level Issue .");
        return;
    }

    NewN -> Data = Ele;
    NewN -> Next = NULL;

    if(NULL == *First)
    {
        *First = NewN;
    }
    else
    {
        NewN -> Next = *First;
        *First = NewN;
    }
    return ;
}
void Display_LL(struct Node* First)
{
    if(NULL == First)
    {
        printf("\n\n Link List is already Empty , No Element to Display!!!!");
    }
    else
    {
        printf("\n\n Element in link list are => \n\n\t ");
        while(First != NULL)
        {
            printf("  | %d | -> ",First -> Data);

            First = First -> Next;
        }
        printf("   NULL");
    }
    return;
}
