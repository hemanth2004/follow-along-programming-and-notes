#include <iostream>

#pragma once

class Stack
{
    private:
    struct Node
    {   
        int data;
        struct Node* link;
    };
    
    Node* top = NULL;
    
    public:
    int count = 0;

    void Push(int x)
    {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->link = top;
        top = newNode;
        count++;
    }
    void Pop()
    {
        if(top == NULL)
        return;
    
        Node* del = top;
        top = top->link;
        delete del;
        count--;
    }
    void Print()
    {
        Node* bar = top;
        std::cout << "Stack: ";
        while(bar != NULL)
        {
            std::cout << (char) bar->data << " ";
            bar =  bar->link;
        }
        std::cout << std::endl;
    }
    int Recount()
    {
        Node* bar = top;
        int _count = 0;
        while(bar != NULL)
        {
            _count++;
            bar =  bar->link;
        }
        if(count != _count)
        {
            count = _count;
        }
        return _count;
    }
    bool IsEmpty()
    {
        return count == 0;
    }
    int GetTop()
    {
        return top->data;
    }
};