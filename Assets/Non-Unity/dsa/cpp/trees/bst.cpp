#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* GetNewNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}


Node* Insert(Node* root, int data)
{
    if(root == nullptr)
    {
        root = GetNewNode(data);
        return root;
    }
    else if(data <= root -> data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}
bool Search(Node* root, int data)
{
    if(root == nullptr)
    {
        return false;
    }
    else if(root->data == data)
    {
        return true;
    }
    else if(data <= root->data) 
    {
        return Search(root->left, data); 
    }
    else 
    { 
        return Search(root->left, data); 
    }
}
int main()
{
    Node* root = nullptr;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 13);
    root = Insert(root, 11);
    root = Insert(root, 30);

    cout << "Enter a number to be searched: ";
    int x;
    cin >> x;

    cout << (Search(root, x)?"Exists":"Doesn't Exist");
}