#include "ScalarConverter.hpp"
#include <cmath>

void ScalarConverter::convert(std::string str)
{

    // need to have a check for if string is a mixture of chars and ints

    if (str.find('.') != std::string::npos)
    {
        if (str.find('f') == str.length() - 1) // literal type is float
            std::cout << "literal type is float" << std::endl;
        else
            std::cout << "literal type is double (if it doesn't contain chars)" << std::endl;
    }
    // else if (str.length() == 1 && std::isprint(str[0])) // this doesn't work
    //     std::cout << "literal type is char" << std::endl;
    else
        std::cout << "literal type is int or char" << std::endl; 

    // if (std::stod(str) == true && )
    //     double  value = std::stod(str);
    // else if ()


    // int     value = std::stoi(str);
    // float   value = std::stof(str);
    // double  value = std::stod(str);

    // if (value == std::floor(value) && std::isprint(value))
    // {
    //     std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    // }
    // else
    // {
    //     std::cout << "char: Non displayable" << std::endl;
    // }

    // std::cout << "int: " << static_cast<int>(value) << std::endl;

    // if (value == std::floor(value))
    // {
    //     std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    //     std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
    // }
    // else
    // {
    //     std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    //     std::cout << "double: " << static_cast<double>(value) << std::endl;
    // }
}