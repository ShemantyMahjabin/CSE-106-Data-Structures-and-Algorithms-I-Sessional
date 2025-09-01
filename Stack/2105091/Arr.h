#include<iostream>
using namespace std;

template<class T>
class Stack
{
    int top;
    T *A;
    int size;

public:
    Stack()
    {

        A=new T[size];
        top=-1;
    }
    ~Stack()
    {
        delete[] A;
    }
    void init(int chunk_size,int length)
    {
        size=chunk_size;
        for(int i=0; i<length; i++)
        {
            T element;
            cin>>element;
            Push(element);
        }
    }
    void Push(T x)
    {
        if(top==size-1)
        {
            T *A2=new T[size*2];
            size=size*2;
            for(int i=0; i<=top; i++)
            {
                A2[i]=A[i];
            }
            delete[]A;
            A=A2;
            A[++top]=x;

        }
        else
            A[++top]=x;
    }
    T Pop()
    {

        return A[top--];
    }
     void pop()
    {
        top--;
    }
    int length()
    {
        return (top+1);
    }

    T topValue()
    {
        return A[top];
    }
    bool IsEmpty()
    {
        return top==-1;
    }
    void Print()
    {

        cout<<"<";
        for(int i=0; i<=top; i++)
        {
            cout<<A[i]<<"  ";
        }
        cout<<">"<<endl;
    }
    void clear()
    {
        top=-1;
    }
    void functionDeclaration()
    {
        cout<<"Which task do you want to perform?"<<endl;
        cout<<"1.clear"<<endl;
        cout<<"2.push(item)"<<endl;
        cout<<"3.pop()"<<endl;
        cout<<"4.length()"<<endl;
        cout<<"5.topValue"<<endl;
        cout<<"6.isEmpty"<<endl;
        int Q;
        cin>>Q;
        while(Q!=0)
        {
            switch(Q)
            {

            case 1:
            {
                clear();
                Print();
                break;
            }
            case 2:
                {
                    T p;
                    cout<<"What do y want to push?"<<endl;
                    cin>>p;
                    Push(p);
                    Print();
                    break;

                }
            case 3:
                {
                    if(top!=-1)
                    {
                        cout<<Pop()<<endl;
                    }
                    else
                    {
                        Pop();
                    }
                    Print();
                    break;
                }
            case 4:
                {
                    Print();
                    cout<<length()<<endl;
                    break;
                }
            case 5:
                {
                    Print();
                    cout<<topValue()<<endl;
                    break;
                }
            case 6:
               {
                   Print();
                   if(IsEmpty())
                   {
                      cout<<"True"<<endl;
                   }
                   else{
                    cout<<"False"<<endl;
                   }

                   break;
               }

            }
             cout<<"Which task do you want to perform?"<<endl;
             cin>>Q;

        }
    }
};

