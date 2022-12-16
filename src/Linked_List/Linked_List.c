#include "stdio.h"
#include "stdlib.h"

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;
node *head;

void insertNodeToList(int nodeData)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = nodeData;
    newNode->next = NULL;

    //Insert at beginning of list
#if 0
    newNode->next = head;
    head = newNode;
#endif

    //Insert at end of list
#if 0
    node *currNode = head;
    if(head == NULL)
        head = newNode;
    else
    {
        while(currNode->next != NULL)
            currNode = currNode->next;
        currNode->next = newNode;
    }
#endif

   //Insert at specific position
}

void printList()
{
    node *currNode = head;
    printf("\nList : ");
    while(currNode->next != NULL)
    {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("%d ", currNode->data);
}

int main()
{
    int numNodes, nodeData;

    head = NULL;

    printf("\nEnter number of nodes ");
    scanf("%d", &numNodes);

    for (int n=0; n < numNodes; n++)
    {
        printf("\nEnter node data :");
        scanf("%d", &nodeData);
        insertNodeToList(nodeData);
        printList();
    }
    return 0;
}