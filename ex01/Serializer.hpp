#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Data.hpp"

class Serializer
{
    private:
        Serializer();
        // Serializer();
        // Serializer(const Serializer& obj);
        // ~Serializer();
        // Serializer&  operator=(const Serializer& obj);
    public:
        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);
};

#endif