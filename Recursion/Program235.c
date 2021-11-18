#include<iostream>
using namespace std;

int FactorialI(int iNo)
{
   int iFact = 1 ;

   while(iNo != 0)
   {
       iFact = iFact * iNo;
       iNo--;
   }
   return iFact;
}

int factR(int iNo)
{

}

int main()
{
    int x = 0 ,iRet = 0;

    cout<<"Enter number for factorial\n";
    cin>>x;

    iRet = FactorialI(x);

    cout<<"Factorial is :"<<iRet<<"\n";

    return 0;
}
