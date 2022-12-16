#include <iostream>
#include <stack>
#include <string>

using namespace std;

/* Reverse the string using stack 
 * Time complexity = O(n) 
 * Space complexity = O(n) -> due to use of stack */
void reverseStringUsingStack(string *str)
{
    int idx, strLen;
    stack<char> stk;

    strLen = (*str).length();
    /*Inserting each character from string to stack*/
    for(idx=0; idx<strLen; idx++)
        stk.push((*str)[idx]);

    /*Fetching each character from stack and inserting back to string in reverse order*/
    for(idx=0; idx<strLen; idx++)
    {
        (*str)[idx] = stk.top();
        stk.pop();
    }
}

/* Reverse the string using array
 * Time complexity = O(n)
 * Space complexity = O(1) -> because no other data structure used for reversal */
void reverseStringUsingArray(string *str)
{
    int head, tail;
    char temp;

    head = 0;
    tail = (*str).length() - 1;

    while(head < tail)
    {
        /* Swap elements at head and tail position */
        temp = (*str)[head];
        (*str)[head] = (*str)[tail];
        (*str)[tail] = temp;

        /*Shift head to right and tail to left*/
        head++;
        tail--;
    }
}

int main()
{
    string s;

    cout<<"Enter a string ";
    getline(cin, s);

    reverseStringUsingStack(&s);
    cout<<"\nReversed string : "<<s;

    reverseStringUsingArray(&s);
    cout<<"\nReversed string : "<<s;
}