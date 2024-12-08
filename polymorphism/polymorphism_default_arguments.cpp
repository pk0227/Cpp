#include <iostream>
//#include <format>     //works for C++20 and above.
#include <string>

class Base
{
 
  public:
    virtual std::string add(int a=5, int b=5)
    {
        return std::string("In Base : " + std::to_string(a+b+1) + ".");
        //return std::string(std::format("In Base : {}.", a+b+1));      //works for C++20 and above.
    }
};

class Derived : public Base
{
  
  public:
    std::string add(int a=10, int b=10) override final
    {
        return std::string("In Derived : " + std::to_string(a+b+1) + ".");
        //return std::string(std::format("In Derived : {}.", a+b+1));   //works for C++20 and above.
    }
};

int main()
{
    Base *bptr = new Derived;
    std::cout << bptr->add() << std::endl;
    std::cout << Derived().add() << std::endl;
    return 0;
}