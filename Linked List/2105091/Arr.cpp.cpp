#include<iostream>
using namespace std;
//Array based Implementation
class ArrList
{
    int *arr;
    int currpos;
    int maxsize;
    int length;
public:
    ArrList();
    ~ArrList();
    void init(int initialsize, int chunksize);
    void insert(int item);
    int remove();
    void moveToStart();
    void moveToEnd();
    void prev();
    void next();
    int Length();
    int currPos();
    void moveToPos(int pos);
    int getValue();
    void displayList();
    void clear();
    void append(int item);
    int Search(int item);
};
ArrList::ArrList()
{
    int arr=NULL;
    int currpos=0;
    int maxsize=0;
    int length=0;
}
ArrList::~ArrList()
{
    delete[] arr;
}
void ArrList:: init(int initialsize, int chunksize)
{
    maxsize=initialsize+chunksize;
    arr=new int[maxsize];
    length=0;
    currpos=0;
}
void ArrList::insert(int item)
{
    if(length==maxsize)
    {
        maxsize+=maxsize;
        int* temp=new int[maxsize];
        for(int i=0; i<length; i++)
        {
            temp[i]=arr[i];
        }
        delete[] arr;
        arr=temp;
    }
    for(int i=length; i>currpos; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[currpos]=item;
    length++;
    next();
}
int ArrList::remove()
{
    if(length==0)
    {
        return -1;
    }
    int item=arr[currpos];
    for(int i=currpos; i<length-1; i++)
    {
        arr[i]=arr[i+1];
    }
    length--;
    return item;
}

void ArrList::moveToStart()
{
    currpos=0;
}
void ArrList::moveToEnd()
{
    currpos=length-1;
}
void ArrList::prev()
{
    if(currpos>0)
    {
        currpos--;
    }
}
void ArrList::next()
{
    if(currpos<length-1)
    {
        currpos++;
    }
}
int ArrList::Length()
{
    return length;
}
int ArrList::currPos()
{
    return currpos;
}
void ArrList::moveToPos(int pos)
{
    currpos=pos;
}
int ArrList::getValue()
{
    if(length==0)
    {
        return -1;
    }
    return arr[currpos];
}
void ArrList::displayList()
{
    cout<<"<";
    for(int i=0; i<length; i++)
    {
        if(currpos==i)
        {
            cout<<"| ";
        }
        cout<<arr[i]<<" ";
    }
    if(length==currpos)
    {
        cout<<"|";
    }
    cout<<">"<<endl;
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
    cout<<"1.insert(item)"<<endl;
    cout<<"2.remove"<<endl;
    cout<<"3.moveToStart"<<endl;
    cout<<"4.moveToEnd"<<endl;
    cout<<"5.prev"<<endl;
    cout<<"6.next"<<endl;
    cout<<"7.length"<<endl;
    cout<<"8.currPos"<<endl;
    cout<<"9.moveToPos(int pos)"<<endl;
    cout<<"10.getValue"<<endl;
    cin>>Q;
    while(Q!=0)
    {
        switch(Q)
        {
        case 1:
        {
            cout<<"Which element do you want to insert?"<<endl;
            cin>>p;
            list.insert(p);
            list.displayList();
            cout<<"-1"<<endl;
            break;
        }
        case 2:
        {

            int t=list.remove();
            list.displayList();
            cout<<t<<endl;
            break;
        }
        case 3:
        {
            list.moveToStart();
            list.displayList();
            cout<<"-1"<<endl;
            break;
        }
        case 4:
        {

            list.moveToEnd();
            list.displayList();
            cout<<"-1"<<endl;
            break;
        }
        case 5:
        {
            list.prev();
            list.displayList();
            cout<<"-1"<<endl;
            break;
        }
        case 6:
        {
            list.next();
            list.displayList();
            cout<<"-1"<<endl;
            break;
        }
        case 7:
        {
            list.displayList();
            cout<<list.Length()<<endl;
            break;
        }
        case 8:
        {
            list.displayList();
            cout<<list.currPos()<<endl;
            break;
        }
        case 9:
        {
            cout<<"Input position:"<<endl;
            cin>>p;
            list.moveToPos(p);
            list.displayList();
            cout<<"-1"<<endl;
            break;
        }
        case 10:
        {
            list.displayList();
            cout<<list.getValue()<<endl;
            break;
        }
        }
        cout<<"Which operation do you want to perform?"<<endl;
        cin>>Q;

    }
    return 0;
}

