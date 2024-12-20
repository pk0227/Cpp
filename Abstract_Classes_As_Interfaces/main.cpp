
//#include <iostream>
#include "person.hpp"
#include "doctor.hpp"
#include <memory>

int main()
{
    
    person p("Ram", 24, "Ayodhya");
    std::cout << p;
    std::cout << "-------------------------------------------------------------" << std::endl;
    /*
    doctor d("Mr. Doc", 32, "Neurosurgeon", "US"); 
    std::cout << d;
    */
    std::unique_ptr<person> p1 = std::make_unique<doctor>("Mr. Doc", 32, "Neurosurgeon", "US");
    std::cout << *p1;
    std::cout << "-------------------------------------------------------------" << std::endl;

    return 0;
}