#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE;

class Queue     // Singly Linear Linked List
{
private:
    PNODE first;
    int size;

public:
    Queue()
    {
        first = NULL;
        size = 0;
    }

    void Enqueue(int no)   // InsertLast()
    {
        PNODE newn = new NODE;

        newn -> data = no;
        newn -> next = NULL;

        if(first == NULL)
        {
            first = newn;
        }
        else
        {
           PNODE temp = first;

           while(temp -> next != NULL)
           {
               temp = temp -> next;
           }

           temp -> next = newn;
        }
        size++;
    }

    void Dequeue()   // DeleteFirst()
    {
        if(first == NULL)
        {
            return;
        }

        if(first -> next == NULL)
        {
            delete first;
            first = NULL;
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

        for(int i = 1; i <= size ; i++)
        {
            cout<<"|"<<temp->data<<"|->";
            temp = temp -> next;
        }
        cout<<"NULL";
    }

    int Count()
    {
        return size;
    }
};

int main()
{
    Queue obj;

    obj.Enqueue(11);
    obj.Enqueue(21);
    obj.Enqueue(51);
    obj.Enqueue(101);
    // int iret =
    obj.Dequeue();       // 11
    //cout<<iret;                     // 11

    obj.Display();          // 11       21          51
    int iret = obj.Count();     // 3

    cout<<"\n Size of queue is : "<<iret<<"\n";        // 3

    return 0;
}
