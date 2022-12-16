#include <iostream>
#include <conio.h>

using namespace std;

#define MAX_SIZE_OF_STACK 101
int stack[MAX_SIZE_OF_STACK];
int top;

/*Function to check is stack is empty
 * Time complexity = O(1) 
 * Space complexity = O(1) */
bool isEmpty()
{
    if(top == -1)
    {
        cout<<"\nStack is empty";
        return true;
    }
    else
        return false;
}

/*Function to push an element to top of stack
 * Time complexity = O(1) 
 * Space complexity = O(1) */
void push(int data)
{
    if(top == MAX_SIZE_OF_STACK-1)
    {
        cout<<"\nStack full. Push failed.";
        return;
    }
    top += 1;
    stack[top] = data;
}

/*Function to remove an element from top of stack
 * Time complexity = O(1) 
 * Space complexity = O(1) */
void pop()
{
    if(isEmpty())
        return;

    cout<<"\nPopped element is "<<stack[top];
    top -= 1;
}

/*Function to display the element at top of stack
 * Time complexity = O(1) 
 * Space complexity = O(1) */
void topElement()
{
    if(isEmpty())
        return;

    cout<<"\nElement at top of stack : "<<stack[top];
}

/*Function to display all elements in stack
 * Time complexity = O(n) 
 * Space complexity = O(1) */
void displayStack()
{
    int idx;

    if(isEmpty())
        return;

    cout<<"\nStack : ";
    for(idx = 0; idx <= top; idx++)
    {
        cout<<stack[idx]<<" ";
    }
}

int main()
{
    int operation;
    int data;
    char continueOp;

    top = -1;

    do
    {
        cout << "\n\nEnter operation to be performed (1:Push; 2:Pop; 3:Display Top; 4:Check Empty 5:Display stack) : ";
        cin >> operation;
        switch (operation)
        {
        case 1:
            cout <<"\nEnter element to be pushed : ";
            cin >> data;
            push(data);
            break;

        case 2:
            pop();
            break;

        case 3:
            topElement();
            break;

        case 4:
            if(isEmpty() == false)
                cout<<"\nStack is not empty";
            break;

        case 5:
            displayStack();
            break;

        default:
            cout<<"Invalid operation.";
            break;
        }

        cout<<"\nDo you wish to continue (Y/N) ? ";
        cin>>continueOp;
    } while (continueOp == 'y' || continueOp == 'Y');

    return 0;
}