#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void Insert_First(struct Node**, int);
void Display_LL(struct Node*);
void Delete_First(struct Node**);
void Insert_Last(struct Node**,int);
void Delete_Last(struct Node**);
int Count_LL(struct Node*);
void Insert_At_Position(struct Node** , int ,int);
//void Delete_At_Position(struct Node**,int);

struct Node
{
    int Data;
    struct Node *Next;
};

int iCnt = 0 ;

int main()
{
    struct Node *Head = NULL;

        for(;;)
        {
               int iNo = 0 , Ele = 0 , iRet = 0, Pos = 0;
              char ch = '\0';

            printf("\n=========== Link List Implementation =============\n");

            printf("\n\t01. Insert First Node\n\t02. Insert Last Node\n\t03.Delete First Node\n\t04.Delete Last Node\n\t05.Display Link List\n\t06.Count Link List Node\n\t07.Insert Node At Position\n\t08. Delete Node At Position\n\t09.Exit\n");

            printf("\n=========== ************************* =============\n");

            printf("\n Enter Choice For Performing Link LIst : ");
            scanf("%d",&iNo);

            switch(iNo)
            {
                        case 1 :
                                 printf("\n Enter Element To Insert First : ");
                                 scanf("%d",&Ele);
                                 Insert_First(&Head,Ele);
                                 printf("\n\n Insert Element At First Position Is %d \n", Ele);
                                 printf("\nPress Any Key To Continue !!!");
                                 _getch();
                                 system("cls");
                                 break;
                        case 2 :
                                printf("\n Enter Element To Insert Last : ");
                                scanf("%d",&Ele);
                                Insert_Last(&Head,Ele);
                                printf("\n\n Insert Element At Last Position Is %d \n", Ele);
                                printf("\nPress Any Key To Continue !!!");
                                _getch();
                                 system("cls");
                                 break;
                        case 3 :
                               Delete_First(&Head);
                               printf("\n\nPress Any Key To Continue !!!");
                               _getch();
                                system("cls");
                                break;
                        case 4 :
                                Delete_Last(&Head);
                                printf("\n\nPress Any Key To Continue !!!");
                               _getch();
                                system("cls");
                                break;
                        case 5 :
                                Display_LL(Head);
                                printf("\n\nPress Any Key To Continue !!!");
                               _getch();
                                system("cls");
                                break;
                        case 6 :
                               iRet =  Count_LL(Head);
                               printf("\nCount Of Nodes In Link List Is %d .",iRet);
                               printf("\n\nPress Any Key To Continue !!!");
                               _getch();
                                system("cls");
                                break;
                        case 7 :
                                printf("\n Enter Element To Insert : ");
                                scanf("%d",&Ele);
                                printf("\n Enter Position To Insert Element : ");
                                scanf("%d",&Pos);
                                Insert_At_Position(&Head,Ele,Pos);
                                 printf("\n\nPress Any Key To Continue !!!");
                               _getch();
                                system("cls");
                                break;
                         case 8 :
                                printf("\n Enter Position To Delete Element : ");
                                scanf("%d",&Pos);
                                Delete_At_Position(&Head,Pos);
                                 printf("\n\nPress Any Key To Continue !!!");
                               _getch();
                                system("cls");
                                break;
                           case 9 :
                                fflush(stdin);
                                printf("\n Are You Sure You Want To Exit The Application????\n Then Please Enter The Yes / No :  ");
                                ch = getchar();

                                if(ch == 'Y' || ch == 'y')
                                {
                                    goto down;
                                }
                                fflush(stdin);
                                printf("\n Please Press any key to continue !!");
                                _getch();
                                system("cls");
                                break;
                           default :
                               printf("\n Invalid Choice , Please Enter Correct Choice !!??");
                                printf("\n\n Please Press any Key to continue !!");
                                _getch();
                                system("cls");
                                break;
            }

        }
   down :
         printf("\n\n ============= Thanks For Using This Application =================\n");
         _getch();

        return 0;
}

void Insert_First(struct Node **First , int Ele)
{
    struct Node *New = NULL ;

    New = (struct Node*)malloc(sizeof(struct Node));

    if(New == NULL)
    {
        printf("\n Some Memory Level Issues ???... No Memory Allocated.");
    }

    New -> Data = Ele;
    New -> Next = NULL;

    if(*First == NULL)
    {
        *First = New ;
    }
    else
    {
        New -> Next = *First;
        *First = New ;
    }
    return ;
}

void Delete_First(struct Node **First)
{
    struct Node *Temp = *First ;

    if(*First == NULL)
    {
        printf("\n Link List Is Already Empty , So No Node For Deletion .");
        return ;
    }

    if(Temp ->Next == NULL)
    {
        *First = NULL;
    }
    else
    {
        *First = Temp -> Next ;
    }
    printf("\n We Delete The First Node of Data Is %d .",  Temp -> Data);
    free(Temp);

    return ;
}
void Display_LL(struct Node *First)
{
     if(NULL == First)
    {
        printf("\n Given Link List Is NULL , So No Element For Display .\n");
    }
    else
    {
        printf("\n========== Display Link List =============\n");

        while(First != NULL)
        {
            printf(" | %d |",First -> Data);

            First = First -> Next ;
        }
        printf("  NULL");

        printf("\n========== ***************** =============\n");
    }

    return ;
}
void Insert_Last(struct Node **First,int Ele)
{
    struct Node *New = NULL ;

    New = (struct Node*)malloc(sizeof(struct Node));

    if(New == NULL)
    {
        printf("\n Some Memory Level Issues , No Memory Is Allocated .");
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
        struct Node *Temp = *First ;

        while(Temp != NULL)
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
        printf("\n Link List Is Already Empty ..., No Element To Delete ..!!");
        return ;
    }

    if(Temp -> Next == NULL)
    {
        *First = NULL;
    }
    else
    {
        while((Temp -> Next) -> Next != NULL)
        {
            Temp = Temp -> Next ;
        }
    }

    printf("\n Deleted Last Element Is %d .", (Temp -> Next ) -> Data);
    free(Temp -> Next);
    Temp -> Next = NULL;

    return ;
}

int Count_LL(struct Node *First)
{
    if(First != NULL)
    {
        First = First -> Next ;
        iCnt++;
    }
    return iCnt;
}

void Insert_At_Position(struct Node **First , int Ele ,int Pos)
{
   int  iRet = Count_LL(Head);

    if(Pos <= 0 || Pos > iRet + 1 )
    {
        printf("\n\n Invalid Position ???");
        return ;
    }
    else if(Pos == 1)
    {
        Insert_First(&Head , Ele);
        iCnt++;
    }
    else if(Pos == iRet +1)
    {
        Insert_Last(&Head , Ele);
        iCnt++;
    }
    else
    {
        struct Node *New = NULL ;

        New = (struct Node*)malloc(sizeof(struct Node));

        struct Node *Temp = *First;

        if(New == NULL)
        {
            printf("\n Some Memory Level Issues ");
        }

        New -> Data = Ele;
        New ->Next = NULL;

        while(Pos > 2)
        {
            Temp = Temp -> Next ;
            Pos--;
        }

        New -> Next = Temp -> Next;
        Temp -> Next = New;
    }
}
