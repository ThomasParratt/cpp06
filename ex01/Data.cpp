#include "Data.hpp"

Data::Data()
{

}

Data::Data(int value)
{
    this->value = value;
}

int Data::getValue()
{
    return (this->value);
}