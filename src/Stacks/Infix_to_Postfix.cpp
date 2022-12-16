#include <iostream>
#include <stack>
#include <string>

using namespace std;

/* Checks if character is an operand */
bool isOperand(char c)
{
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9'))
        return true;
    return false;
}

/* Checks if character is an opening bracket */
bool isOpeningBraces(char c)
{
    if (c == '(' || c == '[' || c == '{')
        return true;
    return false;
}

/* Checks if character is a closing bracket */
bool isClosingBraces(char c)
{
    if (c == ')' || c == ']' || c == '}')
        return true;
    return false;
}

/* Returns the precedence of oparator */
int fetchPrecedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

/* Compares the precendence of 2 operators
 * Returns true if first character has higher or same precendece as second character */
bool hasHigherPrecedence(char c1, char c2)
{
    int c1Precedence = fetchPrecedence(c1);
    int c2Precedence = fetchPrecedence(c2);

    cout << "\nc1 = " << c1 << " precedence = " << c1Precedence;
    cout << "\nc2 = " << c2 << " precedence = " << c2Precedence;

    if (c1Precedence >= c2Precedence)
        return true;
    else
        return false;
}

/* Converts infix expression to postfix expression
 * Time complexity = O(n)
 * Space complexity = O(n) */
string infixToPostfix(string infixExp)
{
    char c;
    int infxIdx, pstfxIdx;
    string postfixExp = "";
    stack<char> stk;

    pstfxIdx = 0;

    /* Traverese infix expression from left to right */
    for (infxIdx = 0; infxIdx < infixExp.length(); infxIdx++)
    {
        c = infixExp[infxIdx];

        /* If operand, insert directly into postfix expression.
         * Doing so because we know that the order of operand in
         * resultant postifx expression will be the same as the
         * order in infix expression */
        if (isOperand(c))
            postfixExp += c;
        else
        {
            /* If opening braces, push into stack*/
            if (isOpeningBraces(c))
                stk.push(c);

            else if (isClosingBraces(c))
            {
                /* If closing braces, pop all characters until stack
                 * top is an opening bracket. Add all the popped characters
                 * to postfix expression.
                 * At the end, pop the opening bracket too */
                while (!(isOpeningBraces(stk.top())))
                {
                    postfixExp += stk.top();
                    stk.pop();
                }
                stk.pop();
            }
            else
            {
                /* If operator, check if the top if stack is an operator
                 * higher or same precendence. If so, pop the operator 
                 * add to postfix expression. Do so until all such
                 * operators are popped or stack is empty. 
                 * At the end, push the current operator to stack */
                while ((!stk.empty()) && hasHigherPrecedence(stk.top(), c))
                {
                    postfixExp += stk.top();
                    stk.pop();
                }
                stk.push(c);
            }
        }
    }

    /* Once infix traversal is done, pop the remaining operators from stack
     * and add to postfix expression */
    while (!stk.empty())
    {
        postfixExp += stk.top();
        stk.pop();
    }
    return postfixExp;
}

int main()
{
    string infixExp, postfixExp;

    cout << "Enter an infix expression : ";
    getline(cin, infixExp);

    postfixExp = infixToPostfix(infixExp);
    cout << "\nPostfix expression : " << postfixExp;
}