#pragma once

# include <iostream>
# include <cstdint>
# include "Data.hpp"

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer& obj);
    public:
        Serializer& operator=(const Serializer& obj);
		~Serializer();

        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);
};