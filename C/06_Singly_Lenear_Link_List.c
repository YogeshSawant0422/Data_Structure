#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
    int Data;
    struct Node *Next;
};

void Insert_First(struct Node **First , int Ele)
{
    struct Node *New = NULL;

    New = (struct Node*) malloc (sizeof(struct Node));

    if(NULL == New)
    {
        printf("\n\n Dynamically Memory Not Allocated , Some Memory Level Issue ..\n\n");
        return ;
    }

    New -> Data = Ele;
    New -> Next = NULL;

    if(*First == NULL)
    {
        *First = New;
    }
    else
    {
          New -> Next = *First;
          *First = New;
    }

    printf("\n\n Insert %d Data Successfully ",Ele);
    return ;
}

void Display_LL(struct Node* First)
{
    if(NULL == First)
    {
        printf("\n Given Link List Is NULL , So No Element For Display .\n");
    }
    else
    {
        while(First  != NULL)
        {
            printf("   | %d |  => ",First -> Data);

            First = First -> Next ;
        }
        printf("   NULL");
    }
    return ;
}

void Delete_First(struct Node **First)
{
    struct Node *Temp = *First;

    if(NULL == *First)
    {
        printf("\n Link List Already Empty , No Element To Delete .\n");
        return ;
    }

    if(Temp -> Next == NULL)
    {
        *First = NULL;
    }
    else
    {
        *First = Temp -> Next ;
    }

    printf("\n\n We Delete The %d Node .\n", Temp -> Data);
    free(Temp);

    return ;
}
void Insert_Last(struct Node **First,int Ele)
{
    struct Node *New = NULL;

    New = (struct Node*) malloc (sizeof(struct Node));

    if(NULL == New)
    {
        printf("\n Memory Not Allocated , Some Memory Level Issues ...\n");
        return ;
    }

    New -> Data = Ele;
    New -> Next = NULL;

    if(*First == NULL)
    {
        *First = New ;
    }
    else
    {
        struct Node *Temp = *First;

        while(Temp -> Next != NULL )
        {
            Temp = Temp -> Next;
        }

        Temp -> Next = New ;
    }
    return ;
}
void Delete_Last(struct Node **First)
{
    struct Node *Temp = *First ;

    if(*First == NULL)
    {
        printf("\n\n Given Link List Empty  , Node Is Not Available For Delete..");
        return 0;
    }

    if(Temp -> Next == NULL)
    {
        *First = NULL ;
    }
    else
    {
        while((Temp -> Next) -> Next != NULL)
        {
            Temp = Temp -> Next ;
        }
        printf("\n\n We Remove the element %d .", (Temp -> Next ) -> Data);

        free(Temp -> Next );
        Temp -> Next = NULL;

        return ;
    }
}
int main()
{
    struct Node *Head = NULL;

    Delete_First(&Head);

    Insert_First(&Head, 11);
    Delete_First(&Head);

   printf("\n\n ========== Link List Elements Are =========\n\n");
    Display_LL(Head);
    printf("\n\n ========== ******************** =========\n\n");
    _getch();

    Insert_First(&Head, 45);
    Insert_First(&Head, 21);
   printf("\n\n ========== Link List Elements Are =========\n\n");
    Display_LL(Head);
    printf("\n\n ========== ******************* =========\n\n");

    Delete_Last(&Head);
    _getch();

    Delete_First(&Head);
    Delete_First(&Head);
    printf("\n\n ========== Link List Elements Are =========\n\n");
    Display_LL(Head);
    printf("\n\n ========== ******************* =========\n\n");
    _getch();

    Insert_First(&Head, 75);
    Insert_First(&Head, 56);
     printf("\n\n ========== Link List Elements Are =========\n\n");
    Display_LL(Head);
     printf("\n\n ========== ********************* =========\n\n");

     Delete_Last(&Head);
    _getch();

    Delete_First(&Head);
    Delete_First(&Head);
     printf("\n\n ========== Link List Elements Are =========\n\n");
    Display_LL(Head);
     printf("\n\n ==========********************** =========\n\n");
    _getch();
    return 0;
}
