#include <iostream>

using namespace std;

struct A // 12 byretes
{
    short a{};
    int b{};
    short c{};
};

struct B // 8 bytes
{
    int b{};
    short a{};
    short c{};
};

int main()
{
    int x = sizeof(A);
    int y = sizeof(B);

    cout << x << "  " << y;
}