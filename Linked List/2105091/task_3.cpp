#include<iostream>
#include<sstream>
#include "includes/LL.h"
#include "includes/Arr.h"
using namespace std;


class CRS
{
    //ArrList *gar;
    linkedlist *gar;
    int totalCars;
    int totalGarages;
    int maxCapacity;
public:
    CRS(int x,int y,int z);
    ~CRS();
    void initialize(int garageNo,int carNo);
    int req();
    void ret(int p);
    void printcrs();
};
CRS::CRS(int x,int y,int z)
{

    //gar=new ArrList[y];
    gar=new linkedlist[y];
    totalCars=x;
    totalGarages=y;
    maxCapacity=z;
    for(int i=0; i<totalGarages; i++)
    {
        gar[i].moveToStart();
    }
}
void CRS::initialize(int garageNo,int carNo)
{
    gar[garageNo-1].insert(carNo);
    gar[garageNo-1].next();
}


CRS::~CRS()
{
    delete[] gar;
}

int CRS::req()
{
    for(int i=0; i<totalGarages; i++)
    {
        int a=0;
        int flag=0;
        int length= gar[i].Length();
        if(length==0)
        {
            continue;
        }
        else
        {
            gar[i].moveToStart();
            int least=gar[i].getValue();
            for(int j=1; j<length; j++)
            {
                gar[i].next();
                int u=gar[i].getValue();
                if(u<least)
                {
                    least=u;
                    a=j;
                }
            }
            gar[i].moveToPos(a);
            gar[i].remove();
            flag++;
        }
        if(flag!=0)
        {
            return 1;
        }
    }
    return -1;
}


void CRS::ret(int p)
{
    int flag =0;
    for(int i=(totalGarages-1); i>=0; i--)
    {
        int length=gar[i].Length();
        if(length==maxCapacity)
        {
            continue;
        }
        else if(length==0)
        {
            gar[i].insert(p);
            flag=1;
            break;
        }
        else
        {

            gar[i].moveToStart();
            int highest=gar[i].getValue();
            int a=0;
            for(int j=0; j<length; j++)
            {
                gar[i].next();
                int u=gar[i].getValue();
                if(u>highest)
                {
                    highest=u;
                    a=j;
                }
            }
            gar[i].moveToPos(a+1);
            gar[i].insert(p);
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        cout<<"All garages are full"<<endl;
    }

}



void CRS::printcrs()
{
    for(int i=0; i<totalGarages; i++)
    {
        int length=gar[i].Length();
        if(length==0)
        {
            cout<<endl;
        }
        else
        {
            gar[i].moveToStart();
            for(int j=0; j<length; j++)
            {
                cout<<gar[i].getValue()<<" ";
                gar[i].next();
            }
            cout<<endl;
        }
    }
}

int main(){


    int x,y,z;
    cin>>x>>y>>z;
    cin.ignore();
    CRS car(x,y,z);
    string label;
    int garageNo;
    int a=0;
    for(int i=0; i<y; i++)
    {
        cin>>garageNo;
        getline(cin,label);
        istringstream st(label);
        for(int j=0; j<z; j++)
        {
            st>>a;
            if(a==0)
                break;
            else
            {
                car.initialize(garageNo,a);
                a=0;
            }
        }
    }
    car.printcrs();
    string operation;
    cout<<"Which operation do you wanna perform req or ret?"<<endl;
    while(cin>>operation && operation!="end")
    {
        if(operation=="req")
        {
            int a=car.req();
            if(a==1)
            {
                car.printcrs();
            }
            else
                cout<<"No cars are available"<<endl;
        }
        else if(operation=="ret")
        {
            int label;
            cin>>label;
            car.ret(label);
            car.printcrs();

        }
        else
        {
            car.printcrs();
        }
    }

    return 0;
}
