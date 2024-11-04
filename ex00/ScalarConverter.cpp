#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string str)
{
    std::cout << "int: " << std::stoi(str) << std::endl;
    std::cout << "float: " << std::stof(str) << std::endl;
    std::cout << "double: " << std::stod(str) << std::endl;
}