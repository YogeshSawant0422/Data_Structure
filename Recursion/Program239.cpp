#include<iostream>
#include<stdio.h>

using namespace std;

int CountCapI(char *str)
{
    int iCnt = 0;

    while(*str != '\0')
    {
        if((*str >= 'A') && (*str <= 'Z'))
        {
            iCnt++;
        }
        str++;
    }
    return iCnt;
}

int CountCapR(char *str)
{
    static int iCnt = 0;

    if(*str != '\0')
    {
        if((*str >= 'A') && (*str <= 'Z'))
        {
            iCnt++;
        }
        str++;
        CountCapR(str);
    }
    return iCnt;
}

int main()
{
    char Arr[20];
    int iRet = 0;

    cout<<"Enter string\n";
    scanf("%[^'\n']s",Arr);

    iRet = CountCapR(Arr);

    cout<<"Capital letters are :"<<iRet<<"\n";

    return 0;
}
