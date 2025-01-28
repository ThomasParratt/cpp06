#pragma once

# include <iostream>
# include <cstdint>
# include "Data.hpp"

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer& obj) = delete;
        Serializer& operator=(const Serializer& obj) = delete;
		~Serializer();
    public:

        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);
};