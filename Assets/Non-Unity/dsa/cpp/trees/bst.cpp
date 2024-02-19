#include <iostream>
#include <queue>
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
    else if(data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

Node* InsertNoRec(Node* root, int data)
{
    Node* newNode = GetNewNode(data);
    Node* temp = root;
    while(true)
    {
        if(temp == nullptr)
        {
            temp = newNode;
        }
        else if(data <= temp->data)
        {  
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
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
        return Search(root->right, data); 
    }
}

Node* FindMin(Node* root)
{
    Node* current = root;
    while(current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

int FindMinRec(Node* root)
{
    if(root->left == nullptr)
        return root->data;
    else
        return FindMinRec(root->left);
}

int FindHeight(Node* root)
{
    int heightLeft;
    int heightRight;
    if(root == nullptr)
        return -1;
    else if((heightLeft = FindHeight(root->left)) >= (heightRight = FindHeight(root->right)))
        return heightLeft + 1;
    else
        return heightRight + 1;
}

// Breadth-First
void print_queue(queue<Node*> q)
{
    queue<Node*> temp = q;
    while (!temp.empty()) {
        cout << temp.front()->data <<" ";
        temp.pop();
    }
    cout << '\n';
}

void LevelOrder(Node* root)
{
    if(root == nullptr)
        return;
    
    queue<Node*> Q;
    Q.push(root);   
    print_queue(Q);
    while(!Q.empty())
    {
        Node* current = Q.front();
        //cout << current->data << " ";
        if(current->left != nullptr)
            Q.push(current->left);
        if(current->right != nullptr)
            Q.push(current->right);
        Q.pop();

        print_queue(Q);
        cout << endl;

    }
}

// Depth-First
void Preorder(Node* root)
{
    if(root == nullptr)
        return;
    cout << root->data << endl;
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(Node* root)
{
    if(root == nullptr)
        return;
    
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}

void Postorder(Node* root)
{
    if (root == nullptr)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root-> data << endl;
}


// Is BST?
bool IsSubtreeLesser(Node* root, int value)
{
    if(root == nullptr)
        return true;
    if(root->data <= value 
        && IsSubtreeLesser(root->left, value) 
        && IsSubtreeLesser(root->right, value))
    {
        return true;
    }
    else
        return false;
}

bool IsSubtreeGreater(Node* root, int value)
{
    if(root == nullptr)
        return true;
    if(root->data > value 
        && IsSubtreeGreater(root->left, value) 
        && IsSubtreeGreater(root->right, value))
    {
        return true;
    }
    else
        return false;
}
bool IsBinarySearchTree(Node* root, int minValue, int maxValue)
{
    if(root == nullptr)
        return true;

    // return IsSubtreeLesser(root->left, root->data)
    //         && IsSubtreeGreater(root->right, root->data)
    //         && IsBinarySearchTree(root->left)
    //         && IsBinarySearchTree(root->right);
    return  root->data > minValue
            && root->data < minValue
            && IsBinarySearchTree(root->left, minValue, root->data)
            && IsBinarySearchTree(root->right, root->data, maxValue);
}

// bool IsBinarySearchTreeInorder(Node* root)
// {
//     static int prev = INT_MIN;
//     // checking whether tree is BST or not using DF inorder traversal

//     if(root == nullptr)
//         return true;

//     IsBinarySearchTreeInorder(root->left);
//     if(prev =)
    
// }


Node* Delete(Node* root, int data)
{
    if(root == nullptr)
        return root;
    else if(data < root->data)
    {
        root->left = Delete(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = Delete(root->right, data);
    }
    else // "Wohooo I found you, Get ready to be deleted!" - Harsha Surya
    {
        // Case 1: Childless dink
        if(root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        // Case 2: one and done
        else if(root->left == nullptr)
        {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == nullptr)
        {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: 2 and won
        else
        {
            Node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }

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
    root = Insert(root, 30);
    root = Insert(root, 5);
    root = Insert(root, 40);
    root = Insert(root, 11);

    // cout << "Enter a number to be searched: ";
    // int x;
    // cin >> x;

    // cout << (Search(root, x)?"Exists":"Doesn't Exist");
    // cout << FindHeight(root) << endl;
    
    // Preorder(root);
    // cout << endl << endl;
    // Inorder(root);
    // cout << endl << endl;
    // Postorder(root);

    cout << IsBinarySearchTree(root, INT_MIN, INT_MAX) << endl;
    root->left->left->data = 100;
    cout << IsBinarySearchTree(root, INT_MIN, INT_MAX);

}