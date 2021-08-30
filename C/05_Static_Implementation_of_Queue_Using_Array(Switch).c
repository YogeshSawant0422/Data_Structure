#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define size 7

void Is_Enqueue(int Ele);
void Is_Dequeue();
int Is_Queue_Empty();
int Is_Queue_Full();
void Is_Display();
int Is_Count_Element();
void Is_Search_Element();
int Peek_Element();
int Max_Element();
int Min_Element();

int Queue[size] = {0};
char ch = '\0';
int Front = 0 , Rear = 0 , Ret = 0 , i = 0 ;

int main()
{
    printf("\n\t======== Queue Implementation =========");

    for(;;)
    {
        int choice = 0 , Ele = 0;

        printf("\n\n\t ========= WELCOME TO MY APPLICATION ============\n");

        printf("\t01.Enqueue Element \n\t02.Dequeue Element \n\t03. Display Element \n\t04. Search Element \n\t05.Count Of Element \n\t06.Peek Element\n\t07.Max Element \n\t08.Min Element \n\t09.Exit");

        printf("\n\n\t =================================================\n");

        printf("\n Please Enter Your Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
                    case 1 :
                                printf("\n Enter A Element For Enqueue : ");
                                scanf("%d",Ele);
                                Is_Enqueue(Ele);
                                printf("\n Please press any key to continue !!");
                                _getch();
                                system("cls");
                                break;
                    case 2 :
                                Is_Dequeue();
                                printf("\n Please press any key to continue !! ");
                                _getch();
                                system("cls");
                                break;
                    case 3 :
                                Is_Display();
                                printf("\n\n Please press any key to continue !!");
                                _getch();
                                system("cls");
                                break;
                    case 4 :
                               Is_Search_Element();
                               printf("\n Please press any key to continue !!");
                               _getch();
                               system("cls");
                               break;
                    case 5 :
                                printf( "\n The Count Of Element In Queue Is : %d ",Is_Count_Element());
                                printf("\n Please press any key to continue !!");
                                _getch();
                                system("cls");
                                break;
                    case 6 :
                                printf("\n The Peek element in queue is : %d ",Peek_Element());
                                printf("\n Please press any key to continue !!");
                                _getch();
                                system("cls");
                                break;
                    case 7 :
                                printf("\n The maximum element in Queue is %d",Max_Element());
                                printf("\n Please press any key to continue !!");
                                _getch();
                                system("cls");
                                break;
                    case 8 :
                                printf("\n The minimum element in Queue is %d", Min_Element());
                                printf("\n Please press any key to continue !!");
                                _getch();
                                system("cls");
                                break;
                    case 9 :
                                fflush(stdin);
                                printf("\n Are You Sure You Want To Exit The Application????\n Please Enter The Yes / No , For Do It :  ");
                                ch = getchar();

                                if(ch == 'Y' || ch == 'y');
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
          printf("\n ================ !!!!! Thanks For Watching The Application !!!! =================\n\n");
}

void Is_Enqueue(int Ele)
{
    Ret = Is_Queue_Full();

    if(Ret == 1)
    {
        printf("\n Queue Is Full , We Can not Enqueue The New Element ..");
    }
    else
    {
        printf("\n New Element %d Enqueue Successfully .",Ele);
        Rear++;
    }
    return ;
}
int Is_Queue_Full()
{
    if(Rear == size)
    {
        Ret = 1;
    }
    return Ret;
}
void  Is_Dequeue()
{
    Ret = Is_Queue_Empty();

    if(Ret == 1)
    {
        printf("\n Queue is already Empty , So no element for Dequeue ??");
    }
    else
    {
        printf("\n We can remove the element %d . ", Queue[Front]);
        Queue[Front] = 0;
        Front++;
    }
return ;
}
int Is_Queue_Empty()
{
    if(Front == Rear)
    {
        Ret = 1;
    }
    return Ret;
}
int Is_Count_Element()
{
    return Rear +1 ;
}
void Is_Search_Element()
{
    int Src_Ele = 0 ;

    printf("\n Enter a element for Searching  in queue : ");
    scanf("%d",Src_Ele);

    for( i = 0 ; i <= Rear ;i++)
    {
        if(Src_Ele == Queue[i])
        {
            break;
        }
    }
    if( i == Rear + 1)
    {
        printf("\n Given Element %d is not found in queue ..",Src_Ele);
    }
    else
    {
        printf("\n Given Element %d is found in queue at %d location .", Src_Ele,Rear + 1);
    }
    return ;
}
void Is_Display()
{
    for(i = Front ; i <= Rear ; i++)
    {
        printf("\n\n | %d | ",Queue[i]);
    }
    return ;
}
int Peek_Element()
{
    return Queue[Front];
}
int Max_Element()
{
    int Max = 0 ;

    for(i = 0 ; i <= Rear ; i++)
    {
        if(Max > Queue[i])
        {
            Max = Queue[i];
        }
    }
    return Max;
}
int Min_Element()
{
    int Min = 0;

    for(i = 0 ; i <= Rear ; i++)
    {
        if(i == 0  ||  Min > Queue[i] )
        {
            Min = Queue[i];
        }
    }
    return Min;
}


