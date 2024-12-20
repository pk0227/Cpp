#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
//#include <string_view>
#include <typeinfo>
#include "streamInsertInterface.hpp"


class person : public streamInsertInterface
{
    public:
        std::string m_name{"unknown"};
        person();
        //person(std::string_view name, int age, std::string_view address);
        person(const std::string name, int age, const std::string address);
        virtual ~person();
        //friend std::ostream& operator<<(std::ostream& out, const person& obj);
        

    protected:
        int m_age{0};
        std::string getAddress() const;
        virtual void stream_insert(std::ostream& out) const override;
        
    private:
        std::string m_address{"unknown"};
        
};

#endif //PERSON_HPP