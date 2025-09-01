#include<iostream>
#include "includes/Arr.h"
using namespace std;

void ArrList::clear()
{
    moveToStart();
    while(length>0)
    {
        remove();
        moveToStart();
    }
}

void ArrList::append(int item)
{
    moveToEnd();
    next();
    insert(item);
}



int ArrList::Search(int item)
{
    int lastpos = currPos();
    moveToStart();
    int pos = 0;
    while (currPos()<length-1)
    {
        if (getValue() == item)
        {
            moveToPos(lastpos);
            return pos;
        }
        next();
        pos++;
    }
    if(currPos()==length-1)
    {
        if(getValue()==item)
        {
            moveToPos(lastpos);
            return (length-1);
        }
        else
        {
            moveToPos(lastpos);
            return -1;
        }
    }

}

int main()
{
   int initialize,chunksize;
    cin>>initialize>>chunksize;
    ArrList list;
    list.init(initialize,chunksize);
    int item;
    for(int i=0;i<initialize;i++)
    {
        cin>>item;
        list.insert(item);
    }

    int Q,p;
    cout<<"Which operation do you want to perform?"<<endl;
    cout<<"1.clear()"<<endl;
    cout<<"2.append(item)"<<endl;
    cout<<"3.Search(item)"<<endl;
    cin>>Q;
    while(Q!=0)
    {
        switch(Q)
        {
        case 1:
        {
            list.clear();
            list.displayList();
            cout<<"-1"<<endl;
            break;
        }
        case 2:
        {
            cout<<"Which item you want to append?"<<endl;
            cin>>p;
            list.append(p);
            list.displayList();
            cout<<"-1"<<endl;
            break;
        }
        case 3:
        {
            cout<<"What do you want to search?"<<endl;
            cin>>p;
            list.displayList();
            int t=list.Search(p);
            cout<<t<<endl;
            break;
        }
        }
        cout<<"Which operation do you want to perform?"<<endl;
        cin>>Q;

    }
    return 0;

}


