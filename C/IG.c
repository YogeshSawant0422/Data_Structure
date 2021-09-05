#include<stdio.h>

int main()
{
    int a = 1 , b = 0;

    b = ++a + ++a;

    printf("\n %d  And %d ", a,b);

    return 0;
}
