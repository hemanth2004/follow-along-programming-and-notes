#define MAX 50

class Queue
{
    private:
    int n = MAX;
    int q[MAX] = {0};
    int _size = 0;

    int front = -1, rear = -1;

    public:
    void Enqueue(int x)
    {
        if(IsFull())
            return;
        else if(IsEmpty())
        {
            front = rear = 0;
            _size++;
        }
        else
        {
            rear = (rear + 1) % n;
            _size++;
        }

        q[rear] = x;
    }
    void Dequeue()
    {
        if(IsEmpty())
            return;
        else if(front == rear)
        {
            front = rear = -1;
            _size--;
        }
        else
        {
            front = (front + 1)%10;
            _size--;
        }
    }
    bool IsFull()
    {
        return (rear + 1) % n == front;
    }
    bool IsEmpty()
    {
        return rear == -1 && front == -1;
    }
    int Peek()
    {
        return q[rear];
    }
    int size()
    {
        return _size;
    }
};
