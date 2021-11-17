#include<iostream>
using namespace std;

//Specific Function
void Swap(char *p,char *q)
{
    char temp;

    temp = *p;
    *p = *q;
    *q = temp;
}

//Generic Function
template <class T>
void SwapX(T *p,T *q)
{
    T temp;

    temp = *p;
    *p = *q;
    *q = temp;
}
int main()
{
    char x='\0',y='\0';

    cout<<"Enter first Character\n";
    cin>>x;

    cout<<"Enter second Character\n";
    cin>>y;


    SwapX(&x,&y);

    cout<<"value of X becomes :"<<x<<"\n";
    cout<<"value of y becomes :"<<y<<"\n";

    return 0;
}
