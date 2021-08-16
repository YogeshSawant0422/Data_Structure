#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define Size 7

int Stack[Size] = {0};
int TOP = -1 , i = 0 ;

void pop();
void push(int Ele);
int Is_Stack_Empty();
int Is_Stack_Full();
void Is_Display();
int Is_Count_Element();
void Is_Search_Element();

int main()
{
    printf("\n ======= Stack Implementation ===========\n");

	pop();

	push(10);
	push(20);
	push(30);

    printf("\n\n Count Of Element In Stack Is %d .",Is_Count_Element());

    Is_Search_Element();

	pop();
	_getch();
	printf("\n Count Of Element In Stack Is %d .",Is_Count_Element());

	_getch();
	system("cls");
	printf("\n\n ========= Display Stack =========== \n");
	Is_Display();
	printf("\n\n =========== ******* ============== \n");
    _getch();

	push(40);
	push(50);
	push(60);
	push(70);
	push(80);
	push(90);
	printf("\n\n ========= Display Stack =========== \n");

	Is_Display();

	printf("\n\n =========== ******* ============== \n");

	printf("\n Count Of Element In Stack Is %d .",Is_Count_Element());
    Is_Search_Element();

	_getch();
	system("cls");

    printf("\n\n ========= Display Stack =========== \n");
	Is_Display();
	printf("\n\n =========== ******* ============== \n");

	printf("\n\n Count Of Element In Stack Is %d .",Is_Count_Element());
    Is_Search_Element();

	printf("\n\n ======= Thanks For Watching Stack Implementation =========== \n");

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
		printf("\n Element %d Inserted in Stack Successfully in %d Location ",Ele,TOP + 1);
	}
	return ;
}
int Is_Stack_Full()
{
	int Ret = 0;

	if(TOP+1 == Size)
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

	for( i = TOP; i >= 0 ;i--)
	{
		printf("\n\t\t| %d |",Stack[i]);
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
        for(i = 0 ; i <= TOP ;i++);
    }
    return i ;
}
void Is_Search_Element()
{
    int Src_Ele = 0;

    printf("\n\n Enter The Element For Searching In Stack : ");
    scanf("%d",&Src_Ele);

    if(Is_Stack_Empty())
    {
        printf("\n Stack Is Already Empty  , So No Element For Searching .\n");
    }
    else
    {
         for( i = 0 ; i < TOP ; i++)
        {
            if(Src_Ele == Stack[i])
            {
                break;
            }
        }
        if( i == TOP)
        {
            printf("\n Given Search Element %d Is Not Found In Stack .",Src_Ele);
        }
        else
        {
            printf("\n Search Element %d Found In Given Stack And %d Location .", Src_Ele, TOP);
        }
    }
    return ;
}
