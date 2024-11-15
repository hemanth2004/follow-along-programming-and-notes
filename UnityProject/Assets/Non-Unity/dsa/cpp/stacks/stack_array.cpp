#include <iostream>
#define MAX_SIZE 101
class Stack
{
    
    
    private:
    enum class Type
    {
        curly,
        rect,
        paranth
    };
    int arr[MAX_SIZE];
    int top = -1;

    public:
    void Push(int x)
    {
        if(top == MAX_SIZE)
        {
            printf("Error: Stack Overflow");
            return;
        }
        arr[++top] = x;
    }
    void Pop()
    {
        if(top == -1)
        {
            printf("Error: No element to pop");
            return;
        }

        top--;
    }
    int Top()
    {
        return arr[top];
    }
    int Size()
    {
        return top + 1;
    }

    static void Print(Stack* stack)
    {
        printf("Stack: ");
        for(int i = 0; i <= stack->top; i++)
            printf("%d ", stack->arr[i]);
        printf("\n");
    }
};

int main()
{
    Stack myStack;
    myStack.Push(10);
    Stack::Print(&myStack);
}