#include "streamInsertInterface.hpp"

std::ostream& operator<<(std::ostream& out, const streamInsertInterface& obj)
{
    obj.stream_insert(out);
    return out;
}