#include <iostream>
#include "ListQueue.h"

int main()
{
    Queue q;
    q.Enqueue(10);
    std::cout << std::endl << q.Front() << " , " << q.size();
    q.Enqueue(15);
    std::cout << std::endl << q.Front() << " , " << q.size();
    q.Enqueue(123456);
    std::cout << std::endl << q.Front() << " , " << q.size();
    q.Dequeue();
    std::cout << std::endl << q.Front() << " , " << q.size();
    q.Dequeue();
    std::cout << std::endl << q.Front() << " , " << q.size();
    q.Dequeue();
    std::cout << std::endl << q.Front() << " , " << q.size();
}