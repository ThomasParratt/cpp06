#include "Serializer.hpp"

int main(void)
{
    Data    *data = new Data(42);

    uintptr_t ptr_as_int = Serializer::serialize(data);
    std::cout << ptr_as_int << std::endl;
}