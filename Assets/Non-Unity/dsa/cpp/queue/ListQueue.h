struct Node
{
    int data;
    Node* next;
};

class Queue
{
    private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int _size;

    public:
    void Enqueue(int x)
    {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;
        if(IsEmpty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        _size++;
    }
    void Dequeue()
    {
        if(IsEmpty())
        {
            return;
        }
        else if(head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node* toBeDeleted = head;
            head = head->next;
            delete toBeDeleted;

        }
        _size--;
    }

    int Front() 
    { 
        if(head == nullptr) return -1000; return head->data;
    }
    bool IsEmpty() { return head == nullptr && tail == nullptr; }
    int size() { return _size; }
};