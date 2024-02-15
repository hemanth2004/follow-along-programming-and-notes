#include <iostream>
#include <math.h>
#include "exp_utility.h"

using namespace std;

int PerformOp(char op, int a, int b)
{
    switch(op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int EvaluatePostFix(vector<string> args, int n)
{
    Stack stack;

    for(int i = 0; i < n; i++)
    {
        if(IsOperator(args[i][0]))
        {
            if(stack.count < 2)
            {
                cout << "Not enough operands at position " << i;
                return 1;
            }
            int b = stack.GetTop();
            stack.Pop();
            int a = stack.GetTop();
            stack.Pop();

            int result = PerformOp(args[i][0], a, b);

            stack.Push(result);
        }
        else if(IsNumber(args[i]))
        {
            int num = Number(args[i]);
            stack.Push(num);
        }
    }

    if(stack.IsEmpty())
    {
        cout << "Error: answer lost" << endl;
        return -11111;
    }

    return stack.GetTop();
}