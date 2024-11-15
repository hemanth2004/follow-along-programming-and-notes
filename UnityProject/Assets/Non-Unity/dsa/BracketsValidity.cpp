// Determine validity of a string of various brackets
// using stack

#include <iostream>
#include <vector>
#define MAX_SIZE 101

using namespace std;

enum BracketType
{
    curly,
    rect,
    paranth
};
struct Bracket
{
    BracketType type;
    bool isOpener;
};
class BracketStack
{
    private:
    vector<Bracket*> arr;
    int top = -1;

    public:
    void Push(Bracket* ptr)
    {
        if(top == MAX_SIZE)
        {
            printf("Error: Stack Overflow");
            return;
        }
        arr[++top] = ptr;
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

    static void Print(BracketStack* stack)
    {
    }
};

int main()
{
    BracketStack bracketStack;

    Bracket* add =  new Bracket();
    add->type = BracketType.curly;
    add->isOpener = true;


    bracketStack.Push(add);
}