#include <iostream>
#include <conio.h>

using namespace std;

struct Node
{
    int data;    //stores data in node
    Node *prev;  //stores pointer to previous node in LL
    Node *next;  //stores pointer to next node in LL
};

Node *head;  //stores pointer to first node in LL
int numOfNodesInLL; //stores total number of nodes in LL

/* Function to create a new node */
Node *createNode(int data)
{
    Node *newNode = new Node();

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

/* Function to insert new node at specific position in LL
 * Time complexity = O(n)
 * Space complexity = O(1) */
void insertNodeAtPosInLL(Node *newNode, int position)
{
    int idx;
    Node *currNode = head;

    if(position == 1)
    {
        newNode->next = currNode;
        if(currNode)
           currNode->prev = newNode;
        head = newNode;
    }
    else
    {
        for(idx=0; idx<position-2  ; idx++)
        {
            currNode = currNode->next;
        }
        newNode->next = currNode->next;
        newNode->prev = currNode;
        currNode->next = newNode;
        if(newNode->next)
            newNode->next->prev = newNode;
    }
    numOfNodesInLL++;
}

/* Function to delete a node from given position in LL
 * Time complexity = O(n)
 * Space complexity = O(1) */
void deleteNodeAtPosInLL(int position)
{
    int idx;
    Node *currNode = head;
    Node *nodeToDelete = NULL;

    /* Check if position is valid */
    if(!((position > 0) && (position <= numOfNodesInLL)))
    {
        cout<<"\nInvalid position requested to be deleted";
        return;
    }

    if(position == 1)
    {
        nodeToDelete = currNode;
        currNode = head = nodeToDelete->next;
        currNode->prev = nodeToDelete->prev; //or NULL
    }
    else
    {
        for(idx=0; idx < position-2; idx++)
            currNode = currNode->next;
        nodeToDelete = currNode->next;
        currNode->next = nodeToDelete->next;
        if(currNode->next)
            currNode->next->prev = currNode; //or nodeToDelete->prev
    }

    if(nodeToDelete)
    {
        delete(nodeToDelete);
        numOfNodesInLL--;
    }

}

/* Function to print LL in forward order
 * Time complexity = O(n)
 * Space complexity = O(1) */
void printLL()
{
    Node *currNode = head;

    if (numOfNodesInLL)
    {
        cout << "\nList : ";
        while (currNode)
        {
            cout << currNode->data << " ";
            currNode = currNode->next;
        }
    }
}

/* Function to print LL in reverse order
 * Time complexity = O(n)
 * Space complexity = O(1) */
void reversePrintLL()
{
    Node *currNode = head;

    if (numOfNodesInLL)
    {
        cout << "\nReverse List : ";
        while (currNode->next)
        {
            currNode = currNode->next;
        }

        while (currNode)
        {
            cout << currNode->data << " ";
            currNode = currNode->prev;
        }
    }
}

int main()
{
    int numNodes = 0, idx, data, position;
    Node *newNode;

    head = NULL;
    numOfNodesInLL = 0;

    cout<<"Enter number of node : ";
    cin>>numNodes;

    while(numOfNodesInLL < numNodes)
    {
        cout<<"\nEnter data and position of node "<<(numOfNodesInLL+1)<<" : ";
        cin>>data>>position;

        /* Check if position is valid */
        if(!((position > 0) && (position <= (numOfNodesInLL+1))))
        {
            cout<<"\nInvalid position "<<position;
            continue;
        }

        /* Create and insert new node in LL*/
        newNode = createNode(data);
        insertNodeAtPosInLL(newNode, position);
    }
    printLL();

    /* Delete node at given position */
    deleteNodeAtPosInLL(4);

    /* Print LL */
    printLL();

    /* Reverse print LL */
    reversePrintLL();

    return 0;
}