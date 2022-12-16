#include <iostream>
#include <conio.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head;

/*Create a new node to be added to stack*/
Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/*Function to check if stack is empty
 * Time complexity = O(1) 
 * Space complexity = O(1) */
bool isEmpty()
{
    if(head == NULL)
    {
        cout<<"\nStack is empty";
        return true;
    }
    return false;

}

/*Insert new node to top of stack
 * Time complexity = O(1) 
 * Space complexity = O(1) */
void push(int data)
{
    Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

/*Remove a node from top of stack
 * Time complexity = O(1) 
 * Space complexity = O(1) */
void pop()
{
    Node *nodeToPop = head;
    if(isEmpty() == false)
    {
        head = head->next;
        delete(nodeToPop);
    }

}

/*Display the top element in stack
 * Time complexity = O(1) 
 * Space complexity = O(1) */
void topElement()
{
    if(isEmpty() == false)
    {
        cout<<"\nTop element in stack is "<<head->data;
    }
}

/*Display all element in the stack 
 * Time complexity = O(n) 
 * Space complexity = O(1) */
void displayStack()
{
    Node *currNode = head;
    if(isEmpty() == false)
    {
        cout<<"\nStack : ";
        while(currNode)
        {
            cout<<currNode->data<<" ";
            currNode = currNode->next;
        }
    }
}

int main()
{
    int operation;
    int data;
    char continueOp;

    head = NULL;

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