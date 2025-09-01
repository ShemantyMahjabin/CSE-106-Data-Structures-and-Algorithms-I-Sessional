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
    currpos=length;
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
    if(currpos<length)
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
