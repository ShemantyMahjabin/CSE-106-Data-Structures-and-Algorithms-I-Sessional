#include<iostream>
#include "Arr.h";
using namespace std;
bool IsOpeningParenthesis(char x)
{
    if(x=='(' || x=='{' || x=='[')
        {
            return true;
        }
        else
        {
            return false;
        }
}
bool IsClosingParenthesis(char x)
{
     if(x==')' || x=='}' || x==']')
        {
            return true;
        }
        else
        {
            return false;
        }
}
bool ArePair(char opening,char closing)
{
    if(opening=='(' && closing==')') return true;
    else if(opening=='{' && closing=='}') return true;
    else if(opening=='[' && closing==']') return true;
    return false;

}
bool BalancedParenthesis(string exp)
{
    Stack<char>s;
    for(int i=0;i<exp.length();i++)
    {
        if(IsOpeningParenthesis(exp[i]))
        {
            s.Push(exp[i]);
        }
        else if(IsClosingParenthesis(exp[i]))
                {
                    if(s.IsEmpty() || !ArePair(s.topValue(),exp[i]))
                    {
                        return false;
                    }
                    else
                    {
                       s.pop();
                    }

                }


    }
    return s.IsEmpty()? true:false;
}
int main()
{
    string exp;
    getline(cin,exp);
    if(BalancedParenthesis(exp))
    {
        cout<<"Balanced"<<endl;
    }
    else
    {
        cout<<"Unbalanced"<<endl;
    }
}
