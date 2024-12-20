#include "doctor.hpp"

doctor::doctor() : person(), m_specialization{"default"}
{
    std::cout << "doctor::doctor() default constructor called." << std::endl;
}


doctor::doctor(const std::string name, int age, const std::string specialization, const std::string address) : person(name, age, address),
m_specialization{specialization}
{
    std::cout << "doctor::doctor() parameterized  constructor called." << std::endl;
}

doctor::~doctor()
{
    std::cout << "doctor::~doctor() destructor called." << std::endl;
}

void doctor::stream_insert(std::ostream& out) const
{
    out << "[ " << typeid(*this).name() << " ] => [ name : " << this->m_name << ", age : " << this->m_age << ", address : " << this->getAddress() << 
    ", specialization : " << this->m_specialization << " ]." << std::endl;   
}