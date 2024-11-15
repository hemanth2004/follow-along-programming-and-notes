#include <iostream>
#include <set> //sets are implemented using binary trees so logarithmic time
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int length(Node* head)
{
    int len = 0;
    while(head != nullptr)
    {
        len++;
        head = head->next;
    }
    return len;
}    
// Brute force solution
Node* FindMergePoint_BF(Node* A, Node* B)
{
    int m = length(A); // TC = O(n)
    int n = length(B); // TC = O(m)
    Node* B_restart = B;
    for(int i = 0; i < m; i++) // TC = O(m*n)
    {
        B = B_restart;
        for(int j = 0; j < n; j++)
        {
            if(A == B)
            {
                return A;
            }
            B = B->next;
        }
        A = A->next;
    }
    return nullptr;
}
// One way to make this code quicker is using time-memory tradeoff
// invest memory to decrease time/vicaserva

// Brute force with tradeoff
Node* FindMergePoint_BF_TO(Node* A, Node* B)
{
    int m = length(A); // TC = O(n)
    int n = length(B); // TC = O(m)

    set<Node*> addresses;
    for(int i = 0; i < n; i++)
    {
        addresses.insert(B);
        B = B->next;
    }

    Node* B_restart = B;
    for(int i = 0; i < m; i++) // TC = O(m*n)
    {
        B = B_restart;
        if(addresses.find(A) != addresses.end())
        A->next;
    }
    return nullptr;
}