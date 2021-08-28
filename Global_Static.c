#include<stdio.h>
#include<conio.h>

extern int No;

void Global();

int main()
{
	printf("\n Inside the main function . \n");

	Global();
	getch();
	Global();
	getch();
	Global();

	return 0;
}
void Global()
{
	No++;
	printf("\n Value of Global Is : %d",No);
}
