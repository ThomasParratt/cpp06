#include "Serializer.hpp"

int main(void)
{
    int num = 42;
    int *ptr_to_num = &num;

    std::cout << ptr_to_num << std::endl;

    Data    *data = new Data(ptr_to_num);

    uintptr_t ptr_value = Serializer::serialize(data);

    std::cout << ptr_value << std::endl;
    std::cout << std::showbase << std::hex << ptr_value << std::endl;
}