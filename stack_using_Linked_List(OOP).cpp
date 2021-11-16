
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
        PNODE newn = new NODE;

        newn -> data = no;
        newn -> next = NULL;

        if(size == 0)
        {
            first = newn;
        }
        else
        {
            newn -> next = first;
            first = newn;
        }
        size++;
    }

    void pop()   // DeleteFirst()
    {
        if(size == 0)
        {
            return;
        }
        else if(size == 1)
        {
            delete first;
            first = NULL;

            return;
        }
        else
        {
            PNODE temp = first;

            first = temp -> next;
            delete temp;
        }
        size--;
    }

    void Display()
    {
        PNODE temp = first;

        for(int i = 1 ; i <= size ; i++)
        {
            cout<<"|"<<temp ->data<<"|->";
            temp = temp -> next;
        }
        cout<<" NULL";
    }

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

    obj.pop();       // 101
                        // 101

    obj.Display();          // 51       21      11
   int iret = obj.Count();

    cout<<"\n Size of stack is : "<<iret<<"\n";        // 3

    return 0;
}
