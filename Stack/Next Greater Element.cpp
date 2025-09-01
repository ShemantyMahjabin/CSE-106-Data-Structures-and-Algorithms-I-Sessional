#include<iostream>
#include "Arr.h";
using namespace std;
int main()
{
    Stack<int>s;
    int N;
    cin>>N;
    int arr[100];
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<N;i++)
    {
        int p=0;
        int ele=arr[i];
        for(int j=i;j<N;j++)
        {
            if(ele<arr[j])
            {
                p++;
                s.Push(arr[j]);
                break;
            }
        }
        if(p==0 || i==N-1)
        {
            s.Push(-1);
        }


    }
    s.Print();
    return 0;
}
