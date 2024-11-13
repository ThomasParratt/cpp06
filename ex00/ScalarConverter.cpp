#include "ScalarConverter.hpp"
#include <cmath>
#include <limits>

void ScalarConverter::convert(std::string str)
{
    std::cout << "Max int: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "Max float: " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "Max double: " << std::numeric_limits<double>::max() << std::endl;

    std::cout << "Min int: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "Min float: " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "Min double: " << std::numeric_limits<double>::min() << std::endl << std::endl;

    char    valuec = 0;
    int     valuei = 0;
    float   valuef = 0;
    double  valued = 0;

    bool    i = false;
    bool    f = false;
    bool    d = false;
    bool    special = false;

    // need to have a check for if string is a mixture of chars and ints, or all chars // MORE THAN ONE CHAR or ONE CHAR NOT AT END
    // nan
    // inf
    // need to handle overflow (out of range exceptions)
    
    if (str == "-inff" || str == "+inff" || str == "+inf" || str == "-inf")
    {
        special = true;
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        std::cout << "float: " << str << std::endl;  // need to sort out these two lines and do nan
        std::cout << "double: " << str << std::endl;
    }


    // GET TYPES
    if (str.find('.') != std::string::npos)
    {
        if (str.find('f') == str.length() - 1)
        {
            std::cout << "literal type is float" << std::endl;
            f = true;
            valuef = std::stof(str);
        }
        else
        {
            std::cout << "literal type is double (if it doesn't contain chars)" << std::endl;
            d = true;
            valued = std::stod(str);
        }
    }
    else
    {
        try
        {
            valuei = std::stoi(str);
            i = true;
            std::cout << "literal type is int" << std::endl;
        }
        catch (const std::invalid_argument& e) // CAST AND PRINT CHARS
        {
            valuec = str[0];
            if (str.length() == 1)
                std::cout << "char: '" << valuec << "'" << std::endl;
            else
            {
                if (special == false)
                    std::cout << "Error: Cannot convert a string of characters" << std::endl;
                exit (1);
            }
            std::cout << "literal type is char" << std::endl;
            std::cout << "int: " << static_cast<int>(valuec) << std::endl;
            std::cout << "float: " << static_cast<float>(valuec) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(valuec) << ".0" << std::endl;
        }
        catch (const std::out_of_range& e)
        {
            std::cout << "Error: Integer is out of range" << std::endl;
        }
    }

    // CAST AND PRINT INTS, FLOATS AND DOUBLES
    if (i)
    {
        if (std::isprint(valuei))
            std::cout << "char: '" << static_cast<char>(valuei) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << valuei << std::endl;
        std::cout << "float: " << static_cast<float>(valuei) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(valuei) << ".0" << std::endl;
    }
    if (f)
    {
        if (valuef == std::floor(valuef) && std::isprint(valuef))
            std::cout << "char: '" << static_cast<char>(valuef) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(valuef) << std::endl;
        if (valuef == std::floor(valuef))
            std::cout << "float: " << valuef << ".0f" << std::endl;
        else
            std::cout << "float: " << valuef << "f" << std::endl;
        if (valuef == std::floor(valuef))
            std::cout << "double: " << static_cast<double>(valuef) << ".0" << std::endl;
        else
            std::cout << "double: " << static_cast<double>(valuef) << std::endl;
    }
    if (d)
    {
        if (valued == std::floor(valuef) && std::isprint(valued))
            std::cout << "char: '" << static_cast<char>(valued) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(valued) << std::endl;
        if (valued == std::floor(valued))
            std::cout << "float: " << static_cast<float>(valued) << ".0f" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(valued) << "f" << std::endl;
        if (valued == std::floor(valued))
            std::cout << "double: " << valued << ".0" << std::endl;
        else
            std::cout << "double: " << valued << std::endl;
    }
}