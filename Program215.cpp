#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE;

class Stack     // Singly Linear Linked List
{
private:
    PNODE first;
    int size;
    
public:
    Stack()
    {
        first = NULL;
        size = 0;
    }
    
    void push(int no)   // InsertFirst()
    {
        // Logic
    }
    
    int pop()   // DeleteFirst()
    {
        // Logic
    }
    
    void Display()
    {}
    
    int Count()
    {
        return size;
    }
};

int main()
{
    Stack obj;
    
    obj.push(11);
    obj.push(21);
    obj.push(51);
    obj.push(101);
    
    int iret = obj.pop();       // 101
    cout<<iret;                     // 101
    
    obj.Display();          // 51       21      11
    iret = obj.Count();
    
    cout<<"Size of stack is : "<<iret<<"\n";        // 3
    
    return 0;
}
