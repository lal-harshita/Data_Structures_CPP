#include <iostream>
#include <stack>
#include <string>

using namespace std;

/* Check if paranthesis are balanced in an expression 
 * Time complexity = O(n)
 * Space complexity = O(n) */
bool isBalancedParanthesis(string s)
{
    int idx;
    char c;
    stack<char> stk;

    for(idx=0; idx < s.length(); idx++)
    {
        c = s[idx];
        if(c == '(' || c == '[' || c == '{')
            stk.push(c);
        else
        {
            if (c == ')' || c == ']' || c == '}')
            {
                if (stk.empty())
                    return false;

                switch (c)
                {
                case ')':
                    if (stk.top() == '(')
                        stk.pop();
                    else
                        return false;
                    break;
                case ']':
                    if (stk.top() == '[')
                        stk.pop();
                    else
                        return false;
                    break;
                case '}':
                    if (stk.top() == '{')
                        stk.pop();
                    else
                        return false;
                    break;
                default:
                    break;
                }
            }
        }
    }
    
    if(stk.empty())
        return true;
    return false;
}

int main()
{
    string s;
    
    cout<<"Enter an expression : ";
    getline(cin, s);

    if(isBalancedParanthesis(s))
        cout << "\nExpression is balanced.";
    else
        cout << "\nExpression is unbalanced.";
}