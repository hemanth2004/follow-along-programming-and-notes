#include <iostream>
#include <math.h>
#include <set>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* Insert(Node* head, int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    if(head != nullptr) temp->next = head;
    head = temp;

}
void Print(Node* head)
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
int main()
{
    Node* head = nullptr;

    head = Insert(head, 5);
    Print(head);
    
}

// for(range_declaration : range_expression)
// {
    
// }