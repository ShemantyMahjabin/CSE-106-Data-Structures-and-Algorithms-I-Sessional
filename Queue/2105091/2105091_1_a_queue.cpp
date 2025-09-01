#include<iostream>

#include "2105091_1_a_queue.h"

using namespace std;
template <class T>
    void Queue<T>:: enqueue(int x)
    {
        arr.append(x);

    }
    template <class T>
    T Queue<T>:: dequeue()
    {

        return arr.qremove();
    }
    template <class T>
     int Queue<T>:: Length()
    {
        return arr.qlength();
    }
    template <class T>
    T Queue<T>::Front()
    {
        if(is_empty())
        {
            return T();
        }
        return arr.qFront();
    }
    template <class T>
    T Queue<T>::back()
    {
         if(is_empty())
        {
            return T();
        }
        return arr.qBack();
    }
    template <class T>
    bool Queue<T>::is_empty()
    {
        return arr.IsEmpty();
    }
    template <class T>
    void Queue<T>::clear()
    {
        arr.qClear();
    }
    template <class T>

    void Queue<T>::Print()
    {
        arr.qPrint();
    }
   template <class T>
   void Queue<T>::functionDeclaration()
{
    Print();
    cout<<"Which task do you want to perform?"<<endl;

    cout<<"1.Enqueue(item)"<<endl;
    cout<<"2.Dequeue()"<<endl;
    cout<<"3.length()"<<endl;
    cout<<"4.Front()"<<endl;
    cout<<"5.back()"<<endl;
    cout<<"6.Is_Empty()"<<endl;
    cout<<"7.clear()"<<endl;
    int Q;
    cin>>Q;
    while(Q!=0)
    {
        switch(Q)
        {


        case 1:
        {
            T p;
            cout<<"What do y want to Enqueue?"<<endl;
            cin>>p;
            enqueue(p);
            Print();
            break;

        }
        case 2:
        {
            T p=dequeue();
            Print();
            cout<< p<<endl;
            break;
        }
        case 3:
        {
            Print();
            cout<<Length()<<endl;
            break;
        }
        case 4:
        {
            Print();
            cout<<Front()<<endl;
            break;
        }
        case 5:
        {
            Print();
            cout<<back()<<endl;
            break;
        }

        case 6:
        {
            Print();
            if(is_empty())
            {
                cout<<"True"<<endl;
            }
            else
            {
                cout<<"False"<<endl;
            }

            break;
        }
        case 7:
        {
            clear();
            Print();
            break;
        }

        }
        cout<<"Which task do you want to perform?"<<endl;
        cin>>Q;
    }
}





