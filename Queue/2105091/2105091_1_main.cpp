#include<iostream>

//#include "2105091_1_a_queue.cpp"

#include "2105091_1_ll_queue.cpp"
using namespace std;
int main()
{
    cout<<"What type of queue 1.int, 2.char you would like to construct?"<<endl;
    int d;
    cin>>d;
    switch(d)
    {
    case 1:
    {
        Queue<int>integerList;
        integerList.functionDeclaration();
        break;
    }
    case 2:
    {
        Queue<char>characterList;
        characterList.functionDeclaration();
        break;
    }
    }
    return 0;
}
