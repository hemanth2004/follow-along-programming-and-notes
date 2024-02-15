//program to check validity of string of paranthesis

#include <iostream>
#include "exp_utility.h"

using namespace std;

int IsParanthesisValid(vector<string> args, int n)
{
    Stack stack;
    bool isInvalid = false;

    int i = 0;
    for(i = 0; i < n; i++)
    {
        if(isInvalid)
            break;
        
        switch(args[i][0])
        {
            case '{': stack.Push(args[i][0]); break;
            case '[': stack.Push(args[i][0]); break;
            case '(': stack.Push(args[i][0]); break;

            case '}': 
                if(stack.IsEmpty())
                {
                    isInvalid = true;
                    break;

                }
                else if(stack.GetTop() == '{')
                {
                    stack.Pop();
                    break;
                }
                else
                {
                    isInvalid = true;
                    break;
                }
            case ']':
                if(stack.IsEmpty())
                {
                    isInvalid = true;
                    break;

                }
                else if(stack.GetTop() == '[')
                {
                    stack.Pop();
                    break;
                }
                else
                {
                    isInvalid = true;
                    break;
                }
            case ')': 
                if(stack.IsEmpty())
                {
                    isInvalid = true;
                    break;

                }
                else if(stack.GetTop() == '(')
                {
                    stack.Pop();
                    break;
                }
                else
                {
                    isInvalid = true;
                    break;
                }
        }

    }

    if(stack.count != 0)
    { 
        isInvalid = true;
    }

    return encode((int) !isInvalid, i);

}
