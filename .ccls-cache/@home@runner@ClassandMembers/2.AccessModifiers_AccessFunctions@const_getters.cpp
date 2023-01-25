/*

Getters should provide “read-only” access to data. Therefore, the best practice is that they should return by value or const reference (not by non-const reference). 
A getter that returns a non-const reference would allow the caller to modify the actual object being referenced, which violates the read-only nature of the getter (and violates encapsulation).

*/

#include <iostream>

class Foo
{
private:
    int m_value{ 4 };

public:
    int& getValue() { return m_value; } // returns a non-const reference
    //const int& getValue() { return m_value; }
    //             or 
    //int getValue() { return m_value; }
};

int main()
{
    Foo f;                     // f.m_value is initialized to 4
    f.getValue() = 5;          // use the non-const reference to assign value 5 to m_value
    std::cout << f.getValue() << std::endl; // prints 5

    return 0;
}