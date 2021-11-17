#include<iostream>

using namespace std;

void Swap(float *p,float *q)
{
    float temp;

    temp = *p;
    *p = *q;
    *q = temp;
}
int main()
{
    float x=0,y=0;

    cout<<"Enter first number\n";
    cin>>x;

    cout<<"Enter second number\n";
    cin>>y;


    Swap(&x,&y);

    cout<<"value of X becomes :"<<x<<"\n";
    cout<<"value of y becomes :"<<y<<"\n";

    return 0;
}
