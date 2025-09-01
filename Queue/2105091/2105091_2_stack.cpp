#include<iostream>
#include "2105091_2_stack.h"
using namespace std;
template <class T>

Stack<T>::Stack()
{
    top=T();
    length=0;
}
template <class T>
void Stack<T>::Clear()
{
    s.clear();
    top=T();
    length=0;
}
template <class T>
void Stack<T>::push(T item)
{
    s.enqueue(item);
    length++;
    top=item;
}
template <class T>
T Stack<T>::pop()
{
    if (s.is_empty())
    {
        cout << "Stack is empty." << endl;
        return T();
    }

    int size = s.Length();
    for (int i = 0; i < size - 1; i++)
    {
        T element = s.dequeue();
        s.enqueue(element);
        top=element;
    }
    length--;
    return s.dequeue();
}

template <class T>
int Stack<T>::Length()
{
    return length;
}
template <class T>
T Stack<T>::topValue()
{
    return top;
}
template <class T>
bool Stack<T>::isEmpty()
{
    return (length==0);
}
template <class T>
void Stack<T>::Print()
{
    s.Print();
}
template <class T>
void Stack<T>::FunctionDeclaration()
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
            Clear();
            Print();
            break;
        }
        case 2:
        {
            T p;
            cout<<"What do y want to push?"<<endl;
            cin>>p;
            push(p);
            Print();
            break;

        }
        case 3:
        {
            if(length!=0)
            {
                cout<<pop()<<endl;
            }
            else
            {
                cout<<"No elements to pop"<<endl;
            }
            Print();
            break;
        }
        case 4:
        {
            Print();
            cout<<Length()<<endl;
            break;
        }
        case 5:
        {
            Print();
            if(length==0)
            {
                cout<<"0"<<endl;
            }
            else
            {
                cout<<topValue()<<endl;
            }

            break;
        }
        case 6:
        {
            Print();
            if(isEmpty())
            {
                cout<<"True"<<endl;
            }
            else
            {
                cout<<"False"<<endl;
            }

            break;
        }

        }
        cout<<"Which task do you want to perform?"<<endl;
        cin>>Q;

    }
}




