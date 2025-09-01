#include<iostream>
#include "Arr.h"
using namespace std;

 void getMin(string s)
{
    for(int i=0;i<s.length();i++)
    {
        int min=s[i];
        for(int j=i;j<s.length();j++)
        {
            if(s[j]<min)
            {
                min=s[j];
            }
        }
    }
    if(!s.IsEmpty())
    {
        cout<< min;

    }
    else
    {
        cout<<"-1";
    }
}

int main()
{
    Stack<int>s;
    s.Push(2);
    s.Push(3);
    s.Pop();
    getMin(s);
    s.Push(1);
    getMin(s);
    return 0;
}
