#include<iostream>
#include<string>
#include "Arr.h"
using namespace std;
bool IsOperand(char c)
{
    if(c>='0' && c<='9')
    {
        return true;
    }
    return false;
}

bool IsOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/')
    {
        return true;
    }
    return false;
}

float performOperation(char op,float op1,float op2)
{
    if(op=='+') return op1+op2;
    else if(op=='-') return op1-op2;
    else if(op=='*') return op1*op2;
    else if(op=='/') return op1/op2;
}
float evaluate(string exp)
{
    Stack<float>s;
    for(int i=exp.length()-1; i>=0; i--)
    {
        if(exp[i]==' ') continue;
        else if(IsOperator(exp[i]))
        {
            float operand1=s.Pop();
            float operand2=s.Pop();
            float result=performOperation(exp[i],operand1,operand2);
            s.Push(result);
        }
        else if(IsOperand(exp[i]))
        {
            //float operand=0.0;
           /* while(i>=0 && IsOperand(exp[i]))
            {
                operand=(operand*10.0)+(exp[i]-'0');
                i--;

            }
            i++;*/

            s.Push(exp[i]-'0');
            s.Print();

        }



    }
    return s.topValue();
}
int main()
{
    string exp;
    getline(cin,exp);

    //cout<<postfixToInfix(exp)<<endl;;
    cout<<evaluate(exp);
    return 0;
}

