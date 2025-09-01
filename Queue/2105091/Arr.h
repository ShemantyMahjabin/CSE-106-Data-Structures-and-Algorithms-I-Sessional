#include<iostream>
#define MAX_SIZE 5
using namespace std;
template <class T>
class arraylist
{
    T *A;
    int front;
    int rear;
    int size;
    int currpos;
    int maxsize;
    int length;
public:
    arraylist()
    {
        A=new T[MAX_SIZE];
        front=1;
        rear=0;
        size=MAX_SIZE;
    }
    ~arraylist()
    {
        delete[] A;
    }
     bool IsEmpty()
    {
        if(front==1 && rear==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void append(int x)
    {
         if((front==0 && rear==size-1)||(rear+2)%size==front)
        {
            T *A2=new T[size*2];
            size=size*2;
            for(int i=0; i<=rear; i++)
            {
                A2[i]=A[i];
            }
            delete[]A;
            A=A2;
            rear=(rear+1)%size;


        }

        /*if((rear+2)%MAX_SIZE==front)
        {
            return;
        }*/
        else if(IsEmpty())
        {
            front=rear=0;
            A[front]=x;
        }
        else
        {
            rear=(rear+1)%size;
        }
        A[rear]=x;

    }

    T qremove()
    {
        T item=A[front];
       if(IsEmpty())
        {
            return T();
        }

         /*if(front==rear)
        {
            T item=A[front];
            front=rear=-1;
        }
        else
        {*/
            front=(front+1)%size;
        //}
        return item;
    }
    T qFront()
    {
        return A[front];
    }
    T qBack()
    {
        return A[rear];
    }
    void qClear()
    {
        delete[] A;
        A=new T[size];
        front=1;
        rear=0;
    }
    int qlength()
    {
        if(IsEmpty())
        {
            return 0;
        }
        else
            return ((rear+size)-front+1)%size;
    }
     void qPrint()
    {
        if(IsEmpty())
        {
            cout<<"< >"<<endl;
        }
        else
        {
            cout<<"<";
            for(int i=front;i<=rear;i++)
            {
                cout<<A[i]<<" ";
            }
            cout<<">"<<endl;
        }
    }




    void insert(T item)
{
    if(length==maxsize)
    {
        maxsize+=maxsize;
        T* temp=new T[maxsize];
        for(int i=0; i<length; i++)
        {
            temp[i]=A[i];
        }
        delete[] A;
        A=temp;
    }
    for(int i=length; i>currpos; i--)
    {
        A[i]=A[i-1];
    }
    A[currpos]=item;
    length++;
    next();
}

int remove()
{
    if(length==0)
    {
        return -1;
    }
    int item=A[currpos];
    for(int i=currpos; i<length-1; i++)
    {
        A[i]=A[i+1];
    }
    length--;
    return item;
}

void moveToStart()
{
    currpos=0;
}
void moveToEnd()
{
    currpos=length;
}
void prev()
{
    if(currpos>0)
    {
        currpos--;
    }
}
void next()
{
    if(currpos<length)
    {
        currpos++;
    }
}
int Length()
{
    return length;
}
int currPos()
{
    return currpos;
}
void moveToPos(int pos)
{
    currpos=pos;
}
int getValue()
{
    if(length==0)
    {
        return -1;
    }
    return A[currpos];
}
void displayList()
{
    cout<<"<";
    for(int i=0; i<length; i++)
    {
        if(currpos==i)
        {
            cout<<"| ";
        }
        cout<<A[i]<<" ";
    }
    if(length==currpos)
    {
        cout<<"|";
    }
    cout<<">"<<endl;
}

};


