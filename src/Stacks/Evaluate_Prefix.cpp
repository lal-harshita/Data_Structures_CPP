#include <iostream>
#include <stack>
#include <string>

using namespace std;

/* Evaluates a prefix expression and returns the result
 * Time complexity = O(n) -> due to traversal of expression
 * Space complexity = O(n) -> due to use of stack */
int evaluatePrefix(string exp)
{
    char c;
    int op1, op2, result, idx;
    stack<int> stk;

    /* Traverse the expression from right to left */
    for(idx = (exp.length()-1); idx >= 0; idx--)
    {
        c = exp[idx];
        if(c >= '0' && c <= '9')
        {
            /* Push operands into stack */
            stk.push(int(c - '0'));
        }
        else
        {
            /* If character in expression is operator, pop 2 operands and 
             * perform the operation. Push the result back on to the stack */
            op1 = stk.top();
            stk.pop();
            op2 = stk.top();
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
    return stk.top();
}

int main()
{
    string exp;
    
    cout<<"Enter a prefix expression : ";
    getline(cin, exp);

    cout<<"Result = "<<evaluatePrefix(exp);
}