#include<iostream>
#include<string>
#include "Arr.h"
using namespace std;
bool IsOperator(char C)
{
    if(C=='+' || C=='-'  || C=='*' || C=='/')
        return true;
    else
        return false;
}


bool IsOperand(char C)
{
    if(C>='0' && C<='9')
        return true;
    else
        return false;
}
bool IsOpeningParenthesis(char opening)
{
    if(opening=='(' || opening=='{' || opening=='[')
    {
        return true;
    }
    else
        return false;
}
bool IsClosingParenthesis(char closing)
{
    if(closing==')' || closing=='}' || closing==']')
    {
        return true;
    }
    else
        return false;
}
int GetOperatorWeight(char op)
{
    int weight=-1;
    switch(op)
    {
    case '+':
    case '-':
        weight=1;
        break;
    case '*':
    case '/':
        weight=2;
        break;
    }
}
bool HasHigherPrecedence(char op1,char op2)
{
    int operator1=GetOperatorWeight(op1);
    int operator2=GetOperatorWeight(op2);
    if(operator1==operator2)
    {
        return true;
    }
    return operator1>operator2 ? true:false;
}

int performOperation(char op,int op1,int op2)
{
    if(op=='+') return op1+op2;
    else if(op=='-') return op1-op2;
    else if(op=='*') return op1*op2;
    else if(op=='/') return op1/op2;
}

int infixEvaluation(string exp)
{
    Stack<char>operators;
    Stack<int>vals;
    for(int i=0; i<exp.length(); i++)
    {
        if(exp[i]==' ') continue;
        else if(IsOpeningParenthesis(exp[i]))
        {
        operators.Push(exp[i]);
        }
        else if(IsOperand(exp[i]))
        {
            int value=0;
            while(i<exp.length() && IsOperand(exp[i]))
            {
                value=value*10+exp[i]-'0';
                i++;
            }
            vals.Push(value);
            i--;
        }
        else if(IsClosingParenthesis(exp[i]))
        {
            while(!operators.IsEmpty() && !IsOpeningParenthesis(operators.topValue()))
            {
                int op2=vals.Pop();
                int op1=vals.Pop();
                char op=operators.Pop();
                int result=performOperation(op,op1,op2);
                vals.Push(result);
            }
            if(!operators.IsEmpty())
            {
                operators.Pop();

            }
        }

        else
        {
            while(!operators.IsEmpty() && HasHigherPrecedence(operators.topValue(),exp[i]))
                  {
                       int op2=vals.Pop();
                int op1=vals.Pop();
                char op=operators.Pop();
                int result=performOperation(op,op1,op2);
                vals.Push(result);
                  }
                  operators.Push(exp[i]);
        }
    }

        while(!operators.IsEmpty())
        {
              int op2=vals.Pop();
                int op1=vals.Pop();
                char op=operators.Pop();
                int result=performOperation(op,op1,op2);
                vals.Push(result);

        }


    return vals.topValue();
}

int main()
{
    string exp;
    getline(cin,exp);
    cout<<infixEvaluation(exp)<<endl;
    return 0;
}
