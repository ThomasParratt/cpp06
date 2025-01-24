#include "Serializer.hpp"

int main(void)
{
    Data    *dataPtr = new Data;

    std::cout << "dataPtr = " << dataPtr << std::endl;

    uintptr_t ptrValue = Serializer::serialize(dataPtr);

    //std::cout << "ptr_value in decimal = " << ptrValue << std::endl;
    //std::cout << std::showbase << std::hex << "ptr_value in hexadecimal = " << ptrValue << std::endl;

    Data    *newDataPtr = Serializer::deserialize(ptrValue);

    std::cout << "newDataPtr = " << newDataPtr << std::endl;

    delete dataPtr;
}
