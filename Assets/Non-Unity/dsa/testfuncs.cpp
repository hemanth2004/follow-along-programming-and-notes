#include <iostream>
#include <math.h>

using namespace std;

bool IsNumber(string s);
int main()
{
    cout << IsNumber("123+");
}
bool IsNumber(string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(!(s[i] >= '0' && s[i] <= '9'))
            return false;
    }
    return true;
}  