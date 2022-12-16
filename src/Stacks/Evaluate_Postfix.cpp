#include <iostream>
#include <string>
#include <stack>

using namespace std;

/* Evaluates a postfix expression and returns the result
 * Time complexity = O(n) -> due to traversal of expression
 * Space complexity = O(n) -> due to use of stack */
int evaluatePostfix(string exp)
{
    char c;
    int result, idx;
    int op1, op2;
    stack<int> stk;

    /* Traverse from left to right */
    for(idx=0; idx<exp.length(); idx++)
    {
        c = exp[idx];
        
        if(c>='0' && c<='9')
        {
            /* Push operands onto the stack */
            stk.push(int(c - '0'));
        }
        else
        {
            /* If character in expression is an operator, pop 2 elements from stack
             * and perform the operation. Push the result back into the stack */
            op2 = stk.top();
            stk.pop();
            op1 = stk.top();
            stk.pop();

            switch(c)
            {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                default:
                    break;
            }
            stk.push(result);
        }
    }
    return result;
}

int main()
{
    int result;
    string exp;

    cout<<"Enter a postfix expression :";
    getline(cin, exp);

    cout<<"Result = "<<evaluatePostfix(exp);   
}