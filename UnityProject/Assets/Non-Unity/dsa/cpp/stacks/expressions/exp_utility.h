#include <math.h>
#include <string>
#include "stack_ll.h"
#include <vector>
#include <algorithm>
using namespace std;

#pragma once


int encode(int x, int y) {
    return (x << 16) | y;
}

void decode(int encoded, int& x, int& y) {
    x = encoded & 0xFFFF;
    y = (encoded >> 16) & 0xFFFF;
}

bool IsOpeningParanthesis(char ch) { return ch == '('; }
bool IsClosingParanthesis(char ch) { return ch == ')'; }
bool HasHigherPrecedence(char a, char b) {
    int precedenceA, precedenceB;

    switch (a) {
        case '^':
            precedenceA = 3;
            break;
        case '*':
        case '/':
            precedenceA = 2;
            break;
        case '+':
        case '-':
            precedenceA = 1;
            break;
        default:
            precedenceA = 0; 
            break;
    }

    switch (b) {
        case '^':
            precedenceB = 3;
            break;
        case '*':
        case '/':
            precedenceB = 2;
            break;
        case '+':
        case '-':
            precedenceB = 1;
            break;
        default:
            precedenceB = 0;
            break;
    }
    return precedenceA > precedenceB;
}

bool IsOperator(char ch)
{
    return ch == '*' || ch == '-' || ch == '/' || ch == '+';
}
bool IsNumber(std::string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(!(s[i] >= '0' && s[i] <= '9'))
            return false;
    }
    return true;
} 
int Number(std::string s)
{
    int num = 0;
    for(int i = s.length() - 1, j = 0; i >= 0 ; i--, j++)
    {
        num += (((int) s[i])-((int) '0')) * pow(10, j);
    }
    return num;
}

int IsExpressionValid(vector<string> args, int n)
{
    bool valid = true;
    int i = 0;
    for(i = 0; i < n; i++)
    {
        if(IsOperator(args[i][0]) || IsOpeningParanthesis(args[i][0]) || IsClosingParanthesis(args[i][0]))
        {
            if(args[i].length() > 1)
            {
                valid = false;
                break;
            }
        }
        else if(!IsNumber(args[i]))
        {
            valid = false;
            break;
        }
    }
    
    return encode((int) valid, i);;
}


