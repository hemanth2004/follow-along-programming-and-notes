#include <iostream>
#include "ArrayQueue.h"

int main()
{
    Queue q;
    q.Enqueue(10);
    std::cout << q.Peek() << std::endl;
    q.Enqueue(15);
    std::cout << q.Peek();
    std::cout << std::endl << q.IsFull();
    q.Dequeue();
    q.Dequeue();
}