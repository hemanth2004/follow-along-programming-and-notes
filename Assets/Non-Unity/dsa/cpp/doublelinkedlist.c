#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

struct Node* CreateNode(int value)
{
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void InsertAtHead(int value)
{
    struct Node* newNode = CreateNode(value);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void Print()
{
    struct Node* temp = head;
    printf("Forward Print: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrint()
{
    struct Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    printf("Reverse Print: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    InsertAtHead(5);
    InsertAtHead(1);
    InsertAtHead(0);
    Print();
    ReversePrint();
    
}