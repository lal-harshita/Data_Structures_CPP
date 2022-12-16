#include <iostream>
#include <conio.h>

using namespace std;

struct Node
{
    int data;   // stores data in a node of LL
    Node *next; // stores address to next node in LL
};

Node *head;         // stores address to first node in LL
int numOfNodesInLL; // stores total number of nodes in LL

/* Function to create a new node to be inserted in LL */
Node *createNode(int nodeData)
{
    Node *newNode = new Node();
    newNode->data = nodeData;
    newNode->next = NULL;
    return newNode;
}

/* Function to insert a node at beginning of LL
 * Time complexity = O(1)
 * Space complexity = O(1) */
void insertNodeAtBeginOfList(Node *newNode)
{
    newNode->next = head;
    head = newNode;
    numOfNodesInLL++;
}

/* Function to insert a node at end of LL
 * Time complexity = O(n)
 * Space complexity = O(1) */
void inserNodeAtEndOfList(Node *newNode)
{
    Node *currNode = head;

    if (head == NULL)
        head = newNode;
    else
    {
        while (currNode->next != NULL)
            currNode = currNode->next;
        currNode->next = newNode;
    }
    numOfNodesInLL++;
}

/* Function to insert a node at nth position in a LL.
 * It also supports insertion at beginning and end of LL
 * Time complexity = O(n)
 * Space complexity = O(1) */
void inserNodeAtPosInList(Node *newNode, int position)
{
    int currPos = 0;
    Node *currNode = head;

    /* Check if position is valid */
    if (!((position > 0) && (position <= (numOfNodesInLL + 1))))
    {
        cout << "\nInvalid position " << position;
        return;
    }

    /* Special case : Insert at beginning */
    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        for (currPos = 0; currPos < position - 2; currPos++)
            currNode = currNode->next;
        newNode->next = currNode->next;
        currNode->next = newNode;
    }
    numOfNodesInLL++;
}

/* Function to delete a node at nth position in LL
 * Includes deletion frpm beginning/end of LL .
 * Time complexity = O(n)
 * Space complexity = O(1)*/
void deleteNodeAtPosInList(int position)
{
    int currPos = 0;
    Node *currNode = head;
    Node *nodeToDelete = NULL;

    /* Check if position is valid */
    if (!(position > 0 && position <= numOfNodesInLL))
    {
        cout << "\nInvalid position " << position;
        return;
    }

    /* Special case : delete from beginning */
    if (position == 1)
    {
        nodeToDelete = head;
        head = nodeToDelete->next;
    }
    else
    {
        for (currPos = 0; currPos < position - 2; currPos++)
            currNode = currNode->next;
        nodeToDelete = currNode->next;
        currNode->next = nodeToDelete->next;
    }

    /* Delete memory of the node */
    if (nodeToDelete)
    {
        delete (nodeToDelete);
        numOfNodesInLL--;
    }
}

/* Function to delete node with a particular value  
 * Time complexity = O(n)
 * Space complexity = O(1) */
void deleteNodeWithValue(int value)
{
    int position = 1;
    Node *prevNode = NULL;
    Node *currNode = head;
    Node *nodeToDelete = NULL;

    while (currNode)
    {
        if (currNode->data == value)
        {
            nodeToDelete = currNode;
            /*If value to be deleted is at first node */
            if (position == 1)
            {
                head = nodeToDelete->next;
            }
            else
            {
                prevNode->next = nodeToDelete->next;
            }
            break;
        }
        else
        {
            prevNode = currNode;
            currNode = currNode->next;
            position++;
        }
    }
    if (nodeToDelete)
    {
        delete (nodeToDelete);
        cout << "Node deleted from position " << position;
    }
    else
        cout << "\nValue " << value << " not found in LL";
}

/* Function to reverse LL (Iterative method)
 * Time complexity = O(n)
 * Space complexity = O(1) */
void reverseLL()
{
    Node *prevNode = NULL, *currNode = head, *nextNode;

    while (currNode)
    {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    head = prevNode;
}

/* Function to reverse LL (Recursive method)
 * Time complexity = O(n)
 * Space complexity = O(n) -> due to use of implicit stack */
void reverseLLRecursion(Node *currNode)
{
    Node *nextNode = NULL;
    if (currNode->next == NULL)
    {
        head = currNode;
        return;
    }
    else
    {
        reverseLLRecursion(currNode->next);
        nextNode = currNode->next;
        nextNode->next = currNode;
        currNode->next = NULL;
    }
}

/* Function to print all nodes in LL (Iterative method)
 * Time complexity = O(n)
 * Space complexity = O(1) */
void printList()
{
    Node *currNode = head;

    if (currNode)
    {
        cout << "\nList : ";
        while (currNode->next)
        {
            cout << currNode->data << " ";
            currNode = currNode->next;
        }
        cout << currNode->data << " ";
    }
}

/* Function to print all nodes in LL (Recursion)
 * Time complexity = O(n)
 * Space complexity = O(n) */
void printLLRecursion(Node *currNode)
{
    cout << currNode->data << " ";
    if (currNode->next)
        printLLRecursion(currNode->next);
}

/* Function to print all nodes in LL in reverser order (Recursion)
 * Time complexity = O(n)
 * Space complexity = O(n) */
void reversePrintLLRecursion(Node *currNode)
{
    if (currNode->next == NULL)
    {
        cout << currNode->data << " ";
    }
    else
    {
        reversePrintLLRecursion(currNode->next);
        cout << currNode->data << " ";
    }
}

int main()
{
    int numNodes, nodeData, position;
    Node *newNode;

    head = NULL;
    numOfNodesInLL = 0;

    cout << "\nEnter number of nodes ";
    cin >> numNodes;

    /* Insertion of Node in Linked List */
    /* If position entered in list in invalid, user must enter new position
    until required number of nodes are entered in LL. Hence using below
    condition in while loop instead of a for loop */
    while (numOfNodesInLL < numNodes)
    {
        cout << "\nEnter node data and position:";
        cin >> nodeData;
        cin >> position;
        newNode = createNode(nodeData);
        // insertNodeAtBeginOfList(newNode);
        // inserNodeAtEndOfList(newNode);
        inserNodeAtPosInList(newNode, position);
        printList();
    }

    /* Deletion of node at nth position from LL */
    // deleteNodeAtPosInList(3);

    /* Deletion of a value from LL */
    // deleteNodeWithValue(2);

    /* Reverse LL (Iterative method) */
    // reverseLL();

    /* Reverser LL (Recursive method) */
    reverseLLRecursion(head);

    /* Print LL in forward order through recursion */
    cout << "\nLL in forward order : ";
    printLLRecursion(head);

    /* Print LL in reverse order through recursion */
    // cout<<"\nLL in reverse order : ";
    // reversePrintLLRecursion(head);

    return 0;
}