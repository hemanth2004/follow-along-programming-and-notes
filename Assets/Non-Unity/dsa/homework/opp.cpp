#include <iostream>
using namespace std;

class Base {
public:
    void print() {
        cout << "Base Function" << endl;
    }
};

class Derived : public Base {
public:
    void print() {
        cout << "Derived Function" << endl;
        Base::print(); 
    }
};

int main() {
    
    Derived derived1;
    derived1.print(); 

    Base* basePtr = &derived1;
    basePtr->print(); 

    derived1.Base::print(); 

    return 0;
}
