#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE,*PNODE;

class DoublyCL
{
private:
    PNODE first;
    PNODE last;
    PNODE size;

public:
    DoublyCL()
    {
        first = NULL;
        last = NULL;
        size = 0;
    }
    void Display();
    int Count();
    void InsertFirst(int no);
    void InsertLast(int no);
    void InsertAtPos(int no , int ipos);
    void deletefirst();
    void deletelast();
    void DeleteAtPos(int ipos);
};

void DoublyCL :: InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((first == NULL)&&(last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn -> next = fisrt;
        first -> prev = newn;
        first = newn;
    }
    last -> next = first;
    first -> prev = last;
    size++;
}

void DoublyCL :: InsertLast(int no)
{
    PNODE newn = new NODE;

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((first == NULL)&&(last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last -> next = newn;
        newn -> prev = last;
        last = newn ;

       // newn -> prev = last;
       // last -> next = newn ;
       // newn -> next = first;
    }
    last -> next = first;
    first -> prev = last;
    size++;
}

void DoublyCL :: Display()
{
    PNODE temp = first;

    for(int i = 1;i <= size; i++)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp -> next;
    }
    cout<<"\n";
}

int DoublyCL :: Count()
{
    return size;
}

void DoublyCL :: DeleteFirst()
{
    if((first == NULL)&&(last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
       first = first -> next ;
       delete last -> next;
       first -> prev = last;
       last -> next = first;
    }+
    size--;
}

void DoublyCL :: deleteLast()
{
    if((first == NULL)&&(last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
       last = last -> prev;
       delete last -> next;
       first -> prev = last;
       last -> next = first;
    }
    size--;
}

void DoublyCL :: InsertAtPos(int no,int ipos)
{
    if((ipos < 1) || (ipos > size + 1))
    {
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == size + 1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE newn = new NODE ;

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        PNODE temp = first;

        for(int i = 0; i< ipos-1;i++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        newn -> next -> prev = newn ;
        temp -> next = newn;
        newn -> prev = temp;

        size++;
    }
}
void DoublyCL :: DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > size))
    {
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == size)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = first;

        for(int i = 1; i < ipos - 1; i++)
        {
            temp = temp -> next;
        }
        temp -> next = temp ->next->next;
        delete temp -> next -> prev;
        temp -> next -> prev = temp;

        size--;
    }
}

int main()
{
    DoublyCL obj;

    return 0;
}
