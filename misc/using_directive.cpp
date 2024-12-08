#include <iostream>

class base
{
    //public:
    protected:
        base()
        {
            std::cout << "cons--base called." << std::endl;
        }
        void greet()
        {
            std::cout << "Hi All." << std::endl;
        }
};

class derived : protected base
{
    public:
        using base::greet;
        derived()
        {
            std::cout << "cons--derived called." << std::endl;
        }
};

int main(int argc, char **argv)
{
    //base b1;
    //std::cout << "==================" << std::endl;
    derived d1;
    d1.greet();
    std::cout << "==================" << std::endl;
    return 0;
}