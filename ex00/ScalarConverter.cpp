#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

static int    valid(std::string str)
{
    int     point_count = 0;
    size_t  i = 0;

    if (str != "-inff" && str != "+inff" && str != "+inf" && str != "-inf" && str != "nan" && str != "nanf")
    {
        if (str.length() != 1)
        {
            while (str[i])
            {
                char c = str[i];
                if (!std::isdigit(c) && c != '.' && c != 'f' && c != '-')
                    return (0);
                else if (c == '-' && i > 0) // must be at beginning
                    return (0);
                else if (c == 'f' && i < str.length() - 1) // f must be at the end
                    return (0);
                else if (c == '.') // point can be at end if after number, can't be at beginning
                {
                    point_count++;
                    if (point_count > 1 || (i == str.length() - 1 && !std::isdigit(str[i - 1])) || i == 0)
                        return (0);
                } 
                i++;
            }
        }
    }
    return (1);
}

void ScalarConverter::convert(std::string str)
{
    char    valueC = 0;
    int     valueI = 0;
    float   valueF = 0;
    double  valueD = 0;

    bool    i = false;
    bool    f = false;
    bool    d = false;

    if (!valid(str))
    {
        std::cout << "Error: Invalid input" << std::endl;
        exit(1);
    }

    // GET TYPES
    if (str.length() == 1)
    {
        try
        {
            valueI = std::stoi(str);
            std::cout << "literal type is int" << std::endl;
            i = true;
        }
        catch (const std::invalid_argument& e)
        {
            valueC = str[0];
            std::cout << "literal type is char" << std::endl;
            std::cout << "char: '" << valueC << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(valueC) << std::endl;
            std::cout << "float: " << static_cast<float>(valueC) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(valueC) << std::endl;
        }
    }
    else if (str.find('.') != std::string::npos || 
        str == "-inff" || str == "+inff" || str == "+inf" || str == "-inf" || str == "nan" || str == "nanf")
    {
        if (str[str.length() - 1] == 'f') // Handle floats
        {
            try
            {
                valueF = std::stof(str);
                std::cout << "literal type is float" << std::endl;
                f = true;
            }
            catch (const std::out_of_range& e)
            {
                std::cout << "Error: Invalid float input (Out of range)" << std::endl;
            }
        }
        else // Handle doubles
        {
            try
            {
                valueD = std::stod(str);
                std::cout << "literal type is double" << std::endl;
                d = true;
            }
            catch (const std::out_of_range& e)
            {
                std::cout << "Error: Double is out of range" << std::endl;
            }
        }
    }
    else if (str[str.length() - 1] == 'f') // No decimal point, but ends with 'f'
    {
        try
        {
            valueF = std::stof(str);
            std::cout << "literal type is float" << std::endl;
            f = true;
        }
        catch (const std::exception& e)
        {
            std::cout << "Error: Invalid float input" << std::endl;
        }
    }
    else // No decimal point. Possible integer, double or char
    {
        try
        {
            valueI = std::stoi(str);
            std::cout << "literal type is int" << std::endl;
            i = true;
        }
        catch (const std::out_of_range& e)
        {
            std::cout << "Error: Integer is out of range" << std::endl;
            try
            {
                valueD = std::stod(str);
                std::cout << "literal type is double" << std::endl;
                d = true;
            }
            catch (const std::out_of_range& e)
            {
                std::cout << "Error: Double is out of range" << std::endl;
            }
        }
    }


    // CAST AND PRINT INTS, FLOATS AND DOUBLES
    if (i)
    {
        if (valueI >= 32 && valueI <= 126)
            std::cout << "char: '" << static_cast<char>(valueI) << "'" << std::endl;
        else if (valueI >= 0 && valueI <= 255)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        std::cout << "int: " << valueI << std::endl;
        std::cout << "float: " << static_cast<float>(valueI) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(valueI) << std::endl;
    }
    if (f)
    {
        if (valueF >= 32 && valueF <= 126) 
            std::cout << "char: '" << static_cast<char>(valueF) << "'" << std::endl;
        else if (valueF >= 0 && valueF <= 255)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;

        if (valueF > static_cast<float>(std::numeric_limits<int>::max()) || valueF < static_cast<float>(std::numeric_limits<int>::min()) || str == "nanf")
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(valueF) << std::endl;

        std::cout << "float: " << valueF << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(valueF) << std::endl;
    }
    if (d)
    {
        if (valueD >= 32 && valueD <= 126)
            std::cout << "char: '" << static_cast<char>(valueD) << "'" << std::endl;
        else if (valueD >= 0 && valueD <= 255)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
            
            
        if (valueD > std::numeric_limits<int>::max() || valueD < std::numeric_limits<int>::min() || str == "nan")
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(valueD) << std::endl;

        std::cout << "float: " << static_cast<float>(valueD) << "f" << std::endl;
        std::cout << "double: " << valueD << std::endl; 
    }
}
