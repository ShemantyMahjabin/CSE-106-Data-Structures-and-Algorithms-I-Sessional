#include<iostream>
#include<string>
#include "includes/LL2.h"
using namespace std;
int main()
{
    linkedlist list;
    string str;
    cin>>str;
    for(int i=0; i<str.length(); i++)
    {
        //char a;
        //cin>>a;
        list.insert(str[i]);
        list.next();

    }
    int n=str.length();

    for(int i=0; i<n/2;i++)
    {
        list.moveToPos(i);
        char x=list.getValue();
        list.moveToPos(n-1+i);
         if(list.getValue()!=x)
            {
                cout<<"No";
                return 0;
            }
        /*for(int j=n-1; j>=0; j--)
        {
            list.moveToPos(j);
            if(list.getValue()!=x)
            {
                cout<<"No";
                return 0;
            }


        }*/

    }
    cout<<"Yes"<<endl;
    return 0;

}
