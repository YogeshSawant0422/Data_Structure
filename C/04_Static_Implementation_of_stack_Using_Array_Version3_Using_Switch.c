#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define Size 7

int Stack[Size] = {0};
int TOP = -1 , i = 0;

void pop();
void push(int Ele);
int Is_Stack_Empty();
int Is_Stack_Full();
void Is_Display();
int Is_Count_Element();
void Is_Search_Element();
int Is_Max();
int Is_Min();

int main()
{
    int choice = 0 , Ele = 0;
    char ch = '\0';
    printf("\n ======= Stack Implementation ===========\n");

   up:
            printf("\n\n============= WELCOME =============\n");
            printf("\n\t 01. Push Element \n\t 02. POP Element \n\t 03. Display Element \n\t 04. Search Stack Element \n\t 05. Count Stack Element \n\t 06. Maximum Element In Stack \n\t 07. Minimum Element In Stack  \n\t 08. Exit");
            printf("\n\n=============*****=============\n");

            printf("\n\n Please Enter The Choice : ");
            scanf("%d",&choice);

            switch(choice)
            {
                case 1 :
                        printf("\n Enter The Element For Push In Stack : ");
                        scanf("%d",&Ele);
                        push(Ele);
                        printf("\n\n Press Any Key To Continue !!!!");
                        _getch();
                        system("cls");
                        goto up;
                case 2 :
                        pop();
                        printf("\n\n Press Any Key To Continue !!!!");
                        _getch();
                        system("cls");
                        goto up;
                case 3 :
                        Is_Display();
                        printf("\n\n Press Any Key To Continue !!!!");
                        _getch();
                        system("cls");
                        goto up;
                case 4 :
                        Is_Search_Element();
                        printf("\n\n Press Any Key To Continue !!!!");
                        _getch();
                        system("cls");
                        goto up;
                case 5 :
                         printf("\n Total Count Of Elements In Stack : %d ",Is_Count_Element());
                         printf("\n\n Press Any Key To Continue !!!!");
                        _getch();
                        system("cls");
                        goto up;
                case 6 :
                         printf("\n Maximum Element In Stack : %d ",Is_Max());
                         printf("\n\n Press Any Key To Continue !!!!");
                        _getch();
                        system("cls");
                        goto up;
                case 7 :
                         printf("\n Minimum Element In Stack : %d ",Is_Min());
                         printf("\n\n Press Any Key To Continue !!!!");
                        _getch();
                        system("cls");
                        goto up;
                case 8 :
                         fflush(stdin);
                        printf("\n Are You Sure You Want To Exit . \n\n Please Enter Yes Or No :\t");
                        ch = getchar();

                        if(ch == 'Y' || ch == 'y')
                        {
                            goto down;
                        }
                        fflush(stdin);
                        system("cls");
                        goto up;
                default :
                    printf("\n\n Invalid Choice ???? Please Enter Valid Choice...!!");
                    printf("\n\n Press Any Key To Continue !!!!");
                    _getch();
                    system("cls");
                    goto up;
            }
    down :
            printf("\n\n ======= Thanks For Watching Stack Implementation =========== \n");
            _getch();

	return 0;
}
void pop()
{
	int Ret = Is_Stack_Empty();

	if(1 == Ret)
	{
		printf("\n Stack Is Already Empty  , Please PUSH  The Element \n");
	}
	else
	{
		printf("\n\n We Remove the element : %d \n",Stack[TOP]);
		TOP--;
	}
	return ;
}
void push(int Ele)
{
	int Ret = Is_Stack_Full();

	if(1 == Ret)
	{
		printf("\n\n Stack Is Full , We Cant PUSH the element . \n");
	}
	else
	{
		Stack[++TOP] = Ele;
		printf("\n Element %d Inserted in Stack Successfully in %d index ",Ele,TOP);
	}
	return ;
}
int Is_Stack_Full()
{
	int Ret = 0;

	if(TOP +1 == Size)
	{
		Ret = 1;
	}
	return Ret;
}
int Is_Stack_Empty()
{
	int Ret = 0;

	if(TOP == -1)
	{
		Ret = 1;
	}
	return Ret;
}
void Is_Display()
{
	printf("\n ===== The Element Of Stack Is ===== \n ");

	if(TOP >= 0)
    {
        for( i = TOP; i >= 0 ;i--)
        {
            printf("\n\t\t| %d |",Stack[i]);
        }
    }
    else
    {
        printf("\n No Element For Display , First Push The Element .");
    }
	return ;
}
int Is_Count_Element()
{
    if(Is_Stack_Empty())
    {
        printf("\n Stack Is Already Empty  , So No Element For Counting .\n");
    }
    else
    {
        return TOP + 1;
    }
}
void Is_Search_Element()
{
    int Src_Ele = 0;

    if(Is_Stack_Empty())
    {
        printf("\n Stack Is Already Empty  , So No Element For Searching .\n");
    }
    else
    {
        printf("\n\n Enter The Element For Searching In Stack : ");
        scanf("%d",&Src_Ele);

         for( i = 0 ; i <= TOP ; i++)
        {
            if(Src_Ele == Stack[i])
            {
                break;
            }
        }

        if( i == TOP + 1)
        {
            printf("\n Given Search Element %d Is Not Found In Stack .",Src_Ele);
        }
        else
        {
            printf("\n Search Element %d Found In Given Stack And %d Location .", Src_Ele, i + 1);
        }
    }
    return ;
}
int Is_Max()
{
    int Max = 0 ;

    for(i = 0 ; i <= TOP ;i++)
    {
        if(Stack[i] > Max)
        {
            Max = Stack[i];
        }
    }
    return Max;
}
int Is_Min()
{
    int Min = 0;

    for(i = 0 ; i <= TOP ;i++)
    {
        if( i == 0 || Min > Stack[i])
        {
            Min = Stack[i];
        }
    }
    return Min;
}

