#include "Serializer.hpp"

uintptr_t    Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr->getValue()));
}

/*static Data*        deserialize(uintptr_t raw)
{
    
}*/