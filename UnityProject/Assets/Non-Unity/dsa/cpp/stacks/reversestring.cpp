#include "stack_ll.h"
#include <iostream>

using namespace std;

int main()
{
    Stack stringstack;

    string in;
    cout << "Enter input to reverse:" << endl;
    cin >> in;

    if(in == "")
    {
        cout << "Empty string" << endl;
        return 0;
    }
    cout << in.length();
    for(int i = 0; i < in.length(); i++)
    {
        stringstack.Push((int) in[i]);
    }
    stringstack.Print();

    string reversed;
    int count = stringstack.count;
    for(int i = 1; i <= count; i++)
    {
        reversed += ((char) stringstack.GetTop());
        stringstack.Pop();
    }
    stringstack.Print();

    cout << "Reversed String: " << endl << reversed;
}