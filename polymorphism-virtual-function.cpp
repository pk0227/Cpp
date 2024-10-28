#include <iostream>

class Animal
{
    public:
        virtual void speak()
        {
            std::cout << "Speaking..." << std::endl;
        }
};

class Dog : public Animal
{
    public:
        void speak() override
        {
            std::cout << "Bow... Bow..." << std::endl;
        }
};

int main(int argc, char **argv)
{
    std::cout << "Static Object" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    Dog d1;
    d1.speak();
    std::cout << std::endl;
    
    std::cout << "Static Object through pointer" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    Animal *ptr = &d1;
    ptr->speak();
    std::cout << std::endl;

    std::cout << "Static Object through reference" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    Animal &ref = d1;
    ref.speak();
    std::cout << std::endl;


    std::cout << "--------------------------------------" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "Dynamic Object through pointer" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    ptr = new Dog;
    ptr->speak();
    std::cout << std::endl;

    std::cout << "Dynamic Object through reference" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    Animal* &ref1{ptr};
    //Animal &ref1{&ptr};
    ref1->speak();
    std::cout << std::endl;

    delete ptr;
    return 0;
}