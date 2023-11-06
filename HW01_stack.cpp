#include <stack>
#include <iostream>
using namespace std;

bool isOperator(char x)
{
    return(x=='/'||x=='*'||x=='+'||x=='-'||x=='^');
}

bool isOperand(char x)
{
    return(x!='*'&&x!='/'&&x!='+'&&x!='-'&&x!='('&&x!=')'&&x!='^');
}

template <typename T>
void printTheStack(stack<T> s)
{
    stack<T> r;
    while(!s.empty())
    {
        r.push(s.top());
        s.pop();
    }
    while(!r.empty())
    {
        cout<<r.top()<<" ";
        r.pop();
    }
    cout<<endl;
}

void InfixToPostfix(string formula)
{
    stack<char> token;
    stack<char> output;
    for(int i=0; i<formula.length(); i++)
    {
        if(formula[i]=='(') token.push(formula[i]);
        else if(isOperator(formula[i])) token.push(formula[i]);
        else if(isOperand(formula[i])) output.push(formula[i]);
        else{
            output.push(token.top());
            token.pop();
            token.pop();
        }
    }
    cout<<"Postfix: ";
    printTheStack(output);
    // cout<<"token: ";
    // printTheStack(token);
    if(token.empty()) cout<<"the token stack is empty! "<<endl;
    else cout<<"the expression was not fully parenthesized! "<<endl;
}

void PostfixToInfix(string formula)
{
    stack<string> myStack;
    for(int i=0; i<formula.length(); i++)
    {
        if(isOperand(formula[i])) myStack.push(string(1, formula[i]));
        else//if it's an operator
        {
            string operand1=myStack.top();
            myStack.pop();
            string operand2=myStack.top();
            myStack.pop();
            string newFormula="("+operand2+formula[i]+operand1+")";
            myStack.push(newFormula);
        }
    }
    //print the infix formula out
    cout<<"Infix: ";
    printTheStack(myStack);

}

int main()
{
    // InfixToPostfix("(a-(b*2))");
    PostfixToInfix("H42//E9//793/*561-+*+");
}