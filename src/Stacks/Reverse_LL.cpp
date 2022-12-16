#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head;

/* Inser nodes in LL */
void insertInLL(int data)
{
    Node *newNode = new Node();

    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

/* Print LL */
void printLL()
{
    Node *currNode = head;
    while(currNode)
    {
        cout<<currNode->data<<" ";
        currNode = currNode->next;
    }
}

/* Reverse values in LL keeping all links unchanged 
 * Time complexity = O(n)
 * Space complexity = O(n) -> using explicit stack */
void reverseValueInLL()
{
    stack<int> stk;
    Node *currNode = head;

    /* Push value of each node into stack */
    while(currNode)
    {
        stk.push(currNode->data);
        currNode = currNode->next;
    }

    /* Pop values from stack and store into nodes of LL in reverse order */
    currNode = head;
    while(currNode)
    {
        currNode->data = stk.top();
        currNode = currNode->next;
        stk.pop();
    }
}

/* Reverse nodes in LL 
 * Time complexity = O(n)
 * Space complexity = O(n) -> using explicit stack */
void reverseNodesInLL()
{
    stack<Node *> stk;
    Node *currNode = head;

    /* Push all nodes into stack */
    while(currNode)
    {
        stk.push(currNode);
        currNode = currNode->next;
    }

    /* Pop each node and create a reverse LL */
    currNode = stk.top();
    head = currNode;
    stk.pop();
    while(!stk.empty())
    {
        currNode->next = stk.top();
        stk.pop();
        currNode = currNode->next;
    }
    currNode->next = NULL;
}

int main()
{
    head = NULL;

    /* Insert elements in linked list */
    insertInLL(1);
    insertInLL(2);
    insertInLL(3);
    insertInLL(4);
    insertInLL(5);

    /* Original LL */
    cout<<"\nOriginal LL : ";
    printLL();

    /* Reverse values in LL */
    reverseValueInLL();

    /* Print LL */
    cout<<"\nReversed LL : ";
    printLL();

    /* Reverse Nodes in LL */
    reverseNodesInLL();

    /* Print LL */
    cout<<"\nReversed LL : ";
    printLL();
}