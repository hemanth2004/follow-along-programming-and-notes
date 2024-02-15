#include <iostream>
#include "stack_ll.h"
#include "exp_utility.h"
#include <vector>

#pragma once

using namespace std;

vector<string> InfixToPostfix(vector<string> args, int n)
{
    vector<string> result;
    Stack s;

    for(int i = 0; i < n; i++)
    {
        if(IsNumber(args[i]))
        {
            result.push_back(args[i]);
        }
        else if(IsOperator(args[i][0]))
        {
            while(!s.IsEmpty() && !IsOpeningParanthesis(s.GetTop()) && HasHigherPrecedence(s.GetTop(), args[i][0]))
            {
                string conv(1, (char) s.GetTop());
                result.push_back(conv);
                s.Pop();
            }
            s.Push(args[i][0]);
        }
        else if (IsOpeningParanthesis(args[i][0]))
        {
            s.Push(args[i][0]);
        }
        else if(IsClosingParanthesis(args[i][0]))
        {
            while(!s.IsEmpty() && !IsOpeningParanthesis(s.GetTop()))
            {
                string conv(1, (char) s.GetTop());
                result.push_back(conv);
                s.Pop();
            }
            s.Pop();
        }
    }
    while(!s.IsEmpty())
    {
        string conv(1, (char) s.GetTop());
        result.push_back(conv);
        s.Pop();
    }

    return result;
}


