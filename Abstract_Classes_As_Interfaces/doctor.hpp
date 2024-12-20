#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include <iostream>
//#include <string_view>
#include <typeinfo>
#include "person.hpp"


class doctor : public person
{
    public:
        std::string m_specialization{"unknown"};
        doctor();
        //doctor(std::string_view name, int age, std::string_view address);
        doctor(const std::string name, int age, const std::string specialization, const std::string address);
        virtual ~doctor();
        //friend std::ostream& operator<<(std::ostream& out, const person& obj);
        
    protected:
        virtual void stream_insert(std::ostream& out) const override;    
        
};

#endif //DOCTOR_HPP