#include <iostream>
#include <stack> //stack from standard template library

using namespace std;

int main()
{
    stack<int> S;

    /* Insert into stack
     * Time complexity = O(1)*/
    S.push(5);
    S.push(8);
    S.push(3);
    S.push(9);

    /* Size of stack
     * Time complexity = O(1)*/
    cout<<"\nSize of stack = "<<S.size();

    /* Check if stack is empty
     * Time complexity = O(1) */
    cout<<"\nIs stack empty ? "<<S.empty();

    /* Remove from stack
     * Time complexity = O(1) */
    S.pop();

    /* Display top element in stack
     * Time complexity = O(1)*/
    cout<<"\nTop element in stack = "<<S.top();

    /*Display all elements in stack*/
    cout<<"\nStack : ";
    while(!S.empty())
    {
        cout<<S.top()<<" ";
        S.pop();
    }

    return 0;
}
