#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    std::cout << std::fixed << std::setprecision(1);
    if (argc == 2)
    {
        std::string arg = argv[1];
        ScalarConverter::convert(arg);
    }
    else
        std::cout << "Usage: ./convert <string to convert>" << std::endl;
}

