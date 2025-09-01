#include<iostream>
#include "2105091_2_stack.cpp"
using namespace std;
int main()
{
    cout<<"What type of stack 1.int, 2.char you would like to construct?"<<endl;
    int d;
    cin>>d;
    switch(d)
    {
    case 1:
    {
        Stack<int>intList;
        intList.FunctionDeclaration();
        break;
    }
    case 2:
    {
        Stack<char>charList;
        charList.FunctionDeclaration();
        break;
    }
    }
    return 0;

}

