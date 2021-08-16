#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define Size 7

int Stack[Size] = {0};
int TOP = -1;

void pop();
void push(int Ele);
int Is_Stack_Empty();
int Is_Stack_Full();
void Is_Display();

int main()
{
	pop();

	push(10);
	push(20);
	push(30);

	pop();

	_getch();
	system("cls");
	Is_Display();
    _getch();

	push(40);
	push(50);
	push(60);
	push(70);
	push(80);
	push(90);
	push(100);

	_getch();
	system("cls");

	Is_Display();

	printf("\n ======= Thanks For Watching Stack Implementation ===========\n");

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
		printf("\n We Remove the element : %d \n",Stack[TOP]);
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
	    TOP++;
		Stack[TOP] = Ele;

		printf("\n Element %d Inserted in Stack Successfully ",Ele);
	}
	return ;
}
int Is_Stack_Full()
{
	int Ret = 0;

	if(TOP == Size)
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
    int i =0;
	printf("\n ===== The Element Of Stack Is =====");

	for( i = TOP ; i >=0 ;i--)
	{
		printf("\n\t\t%d",Stack[i]);
	}
	return ;
}
