#include<iostream>
#include<string>
#include "Arr.h"
//#include "LL.h"
using namespace std;
int p=0;
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
bool ArePair(char opening,char closing)
{
    if(opening == '(' && closing == ')') return true;
    else if(opening == '{' && closing == '}') return true;
    else if(opening == '[' && closing == ']') return true;
    return false;
}

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



bool BalancedParenthesis(string exp)
{
    Stack<char>s;
    for(int i=0; i<exp.length(); i++)
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
                s.pop();
        }
    }
    return s.IsEmpty() ? true:false;
}

bool NoOperatorRepeat(string exp)
{
    for(int i=0; i<exp.length(); i++)
    {
        if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/')
        {
            if(exp[i+1]=='+' || exp[i+1]=='*' || exp[i+1]=='/')
            {
                return false;
            }
        }
        else if(IsOpeningParenthesis(exp[i]))
        {
            if(exp[i+1]=='*' || exp[i+1]=='/')
            {
                return false;
            }
        }
        else if(IsClosingParenthesis(exp[i]))
        {
            if(IsOperand(exp[i+1]))
            {
                return false;
            }
        }
        else if(IsOperand(exp[i]))
        {
            if(IsOpeningParenthesis(exp[i+1]))
            {
                return false;
            }
        }


    }
    return true;
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
    return weight;
}

int HasHigherPrecedence(char op1, char op2)
{
    int op1weight=GetOperatorWeight(op1);
    int op2weight=GetOperatorWeight(op2);
    if(op1weight==op2weight)
    {
        return true;
    }
    return op1weight > op2weight ? true:false;
}




float PerformOperation(char operation, float op1, float op2)
{
    if(operation=='+') return op1+op2;
    else if(operation=='-') return op1-op2;
    else if(operation=='*') return op1*op2;
    else if(operation=='/')
    {
        if(op2==0)
        {
            cout<<"Math error:Division by zero"<<endl;
            p++;
            return NULL;
        }
        else
        {
            return op1/op2;
        }
    }
    else
    {
        cout<<"Unexpected Error \n";
        return -1;
    }
}

string modified(string exp)
{
    bool unary=false;
    if(exp[0]=='-')
    {
        unary=true;
        char element='0';
        int position=0;
        exp.insert(position,1,element);
    }
    for(int i=1; i<exp.length(); i++)
    {
        if(exp[i]=='(')
        {
            if(exp[i+1]=='-')
            {
                unary=true;
                char element='0';
                int position=i+1;
                exp.insert(position,1,element);

            }
        }
        else if(IsOperator(exp[i]))
        {
            if(exp[i+1]=='-')
            {
                unary=true;
                char element='0';
                int position=i+1;
                exp.insert(position,1,element);
            }
        }
        else if(exp[i]=='-')
        {
            if(exp[i+1]=='-')
            {
                unary=true;
                char element='0';
                int position=i+1;
                exp.insert(position,1,element);
            }
        }
    }
    return exp;

}



float evaluate(string exp)
{
    int i;
    Stack<float> values;
    Stack<char> oparetors;

    for(i = 0; i < exp.length(); i++)
    {
        if(exp[i] == ' ')
            continue;
        else if(IsOpeningParenthesis(exp[i]))
        {
            oparetors.Push(exp[i]);
        }
        else if(IsOperand(exp[i]))
        {
            float val = 0.0;



            // Parse the number
            while(i < exp.length() && IsOperand(exp[i]))
            {
                val = (val*10.0) + (exp[i]-'0');
                i++;
            }

            // Apply unary minus if necessary

            values.Push(val);
            i--;
        }
        else if(IsClosingParenthesis(exp[i]))
        {
            while(!oparetors.IsEmpty() && !IsOpeningParenthesis(oparetors.topValue()))
            {
                float val2 = values.Pop();


                float val1 = values.Pop();


                char op = oparetors.Pop();


                values.Push(PerformOperation(op,val1, val2));
            }

            // pop opening brace.
            if(!oparetors.IsEmpty())
                oparetors.pop();
        }

        // Current token is an operator.
        else
        {
            // While top of 'ops' has same or greater
            // precedence to current token, which
            // is an operator. Apply operator on top
            // of 'ops' to top two elements in values stack.
            while(!oparetors.IsEmpty() && HasHigherPrecedence(oparetors.topValue(),exp[i]))
            {
                float val2 = values.Pop();


                float val1 = values.Pop();


                char op = oparetors.Pop();


                values.Push(PerformOperation(op,val1, val2));
            }

            // Push current token to 'ops'.
            oparetors.Push(exp[i]);
        }
    }

    // Entire expression has been parsed at this
    // point, apply remaining ops to remaining
    // values.
    while(!oparetors.IsEmpty())
    {
        float val2 = values.Pop();


        float val1 = values.Pop();


        char op = oparetors.Pop();


        values.Push(PerformOperation(op,val1, val2));
    }

    // Top of 'values' contains result, return it.
    return values.topValue();
}








int main()
{
    string expression;
    getline(cin,expression);
    if(BalancedParenthesis(expression) && NoOperatorRepeat(expression))
    {

        string Modified=modified(expression);
        float result=evaluate(Modified);
        if(p==0)
        {
            cout<<"Valid expression."<<endl;
            cout<<"Computed value: "<<result<<endl;
        }
        else
        {
            cout<<"Not valid"<<endl;
        }

    }
    else
    {
        cout<<"Not valid"<<endl;
    }

    return 0;
}
