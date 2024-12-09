#ifndef STREAM_INSERT_INTERFACE_HPP
#define STREAM_INSERT_INTERFACE_HPP

#include <iostream>

class streamInsertInterface
{
  public:
    friend std::ostream& operator<<(std::ostream& out, const streamInsertInterface& obj);
    
    virtual void stream_insert(std::ostream& out) const = 0;
    
};

#endif //STREAM_INSERT_INTERFACE_HPP