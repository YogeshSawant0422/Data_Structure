using namespace std;
#include<iostream>

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE;

class SinglyCL
{
private:
    PNODE first;
    PNODE last;
    int size;

public:
    SinglyCL()
    {
        first = NULL;
        last = NULL;
        size = 0;
    }
    void Display()
    {
        PNODE temp = first;

        if((first == NULL) && (last == NULL))
        {
            return;
        }

        do
        {
            cout<<"|"<<temp -> data<<"|->";
            temp = temp -> next;
        }while(temp != last -> next);

        cout<<"\n";
    }
    int Count()
    {
        return size;
    }
    void InsertFirst(int no)
    {
        PNODE newn = new NODE;

        newn -> data = no;
        newn -> next = NULL;

        if(first == NULL && last == NULL)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn -> next = first;
            first = newn;
        }

        last -> next = first;
        size++;
    }
    void InsertLast(int no)
    {
        PNODE newn = new NODE;

        newn -> data = no;
        newn -> next = NULL;

        if(first == NULL && last == NULL)
        {
            first = newn;
            last = newn;
        }
        else
        {
           last -> next = newn;
           last = newn;
        }

        last -> next = first;
        size++;
    }
    void InsertAtPos(int no , int ipos)
    {
        if((ipos < 1) || (ipos > (size + 1)))
        {
            return ;
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
            PNODE newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;

            PNODE temp = first;

            for(int i = 1; i< ipos - 1;i++)
            {
                temp = temp -> next;
            }

            newn -> next = temp -> next ;
            temp -> next = newn;

            size++;
        }
    }
    void DeleteFirst()
    {
        if((first == NULL) && (last == NULL))
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
            first = first -> next;
            delete last->next;
            last -> next = first;
        }
        size--;
    }
    void DeleteLast()
    {
        PNODE temp = first;

        if((first == NULL) && (last == NULL))
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
            while(temp -> next != last)
            {
                temp = temp -> next;
            }

            delete last;
            last = temp;

            last -> next = first;
        }
        size--;
    }
    void DeleteAtPos(int ipos)
    {

    }
};

int main()
{
   SinglyCL obj;
   int iret = 0;

   obj.InsertFirst(51);
   obj.InsertFirst(21);
   obj.InsertFirst(11);

   obj.InsertLast(101);

   obj.InsertAtPos(55,4);

   obj.Display();
   iret = obj.Count();
   cout<<"Number of elements are : "<<iret<<"\n";

   obj.DeleteAtPos(4);

   obj.DeleteFirst();
   obj.DeleteLast();

    obj.Display();
   iret = obj.Count();
   cout<<"Number of elements are : "<<iret<<"\n";


  return 0;
}
