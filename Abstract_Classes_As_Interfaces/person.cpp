#include "person.hpp"

std::string person::getAddress() const
{
    return m_address;
}

person::person() : m_name{"default"}, m_age{0}, m_address{"default"}
{
    std::cout << "person::person() default constructor called." << std::endl;
}

//person::person(std::string_view name, int age, std::string_view address) : m_name{name}, m_age{age}, m_address{address}
person::person(const std::string name, int age, const std::string address) : m_name{name}, m_age{age}, m_address{address}
{
    std::cout << "person::person(...) parameterized constructor called." << std::endl;
}

person::~person()
{
    std::cout << "person::~person() destructor called." << std::endl;
}

/*
std::ostream& operator<<(std::ostream& out, const person& obj)
{
    out << "[ " << typeid(obj).name() << " ] => [ name : " << obj.m_name << ", age : " << obj.m_age << ", address : " << obj.m_address << " ]." << std::endl; 
    return out;
}
*/

void person::stream_insert(std::ostream& out) const
{
    out << "[ " << typeid(*this).name() << " ] => [ name : " << this->m_name << ", age : " << this->m_age << ", address : " << this->m_address << " ]." << std::endl;   
}