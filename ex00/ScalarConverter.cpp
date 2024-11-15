#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
    (void)obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
    (void)obj;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(std::string str)
{
    char    valuec = 0;
    int     valuei = 0;
    float   valuef = 0;
    double  valued = 0;

    bool    i = false;
    bool    f = false;
    bool    d = false;
    bool    special = false;
    
    if (str == "-inff" || str == "+inff" || str == "+inf" || str == "-inf")
    {
        special = true;
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (str[str.length() - 1] == 'f' && str[str.length() - 2] == 'f')
            std::cout << "float: " << str << std::endl;
        else
            std::cout << "float: " << str + "f" << std::endl;

        if (str[str.length() - 1] == 'f' && str[str.length() - 2] == 'f')
            std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
        else
            std::cout << "double: " << str << std::endl;
    }
    if (str == "nan" || str == "nanf")
    {
        special = true;
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (str[str.length() - 1] == 'f') 
            std::cout << "float: " << str << std::endl;
        else
            std::cout << "float: " << str + "f" << std::endl;

        if (str[str.length() - 1] == 'f')
            std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
        else
            std::cout << "double: " << str << std::endl;
    }

    if (special == false)
    {
        for (char c : str)
            {
                if (!std::isdigit(c) && c != 'e' && c != '.' && c != 'f' && str[0] != '-')
                {
                    std::cout << "Error: Cannot convert a string containing characters(1)" << std::endl;
                    exit(1);
                }
            }
    }

    // GET TYPES
    if (str.find('.') != std::string::npos || str.find('e') != std::string::npos)
    {
        if (str.find('f') == str.length() - 1)
        {
            try
            {
                valuef = std::stof(str);
                std::cout << "literal type is float" << std::endl;
                f = true;
            }
            catch (const std::out_of_range& e)
            {
                std::cout << "Error: Float is out of range" << std::endl;
            }
        }
        else if (str[str.length() - 1] == '.' || std::isdigit(str[str.length() - 1]))
        {
            try
            {
                valued = std::stod(str);
                std::cout << "literal type is double" << std::endl;
                d = true;
            }
            catch (const std::out_of_range& e)
            {
                std::cout << "Error: Double is out of range" << std::endl;
            }
        }
        else 
            std::cout << "Error: Invalid characters" << std::endl;
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
            else // is this correct? needed?
            {
                if (special == false)
                    std::cout << "Error: Cannot convert a string containing characters(2)" << std::endl;
                exit(1);
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


        if (valuef > static_cast<float>(std::numeric_limits<int>::max()) || valuef < static_cast<float>(std::numeric_limits<int>::min()))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(valuef) << std::endl;


        if (valuef == std::floor(valuef) && str.find('e') == std::string::npos)
            std::cout << "float: " << valuef << ".0f" << std::endl;
        else
            std::cout << "float: " << valuef << "f" << std::endl;
        if (valuef == std::floor(valuef) && str.find('e') == std::string::npos)
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
        
        
        if (valued > std::numeric_limits<int>::max() || valued < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(valued) << std::endl;


        if (valued == std::floor(valued) && str.find('e') == std::string::npos)
            std::cout << "float: " << static_cast<float>(valued) << ".0f" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(valued) << "f" << std::endl;
        if (valued == std::floor(valued) && str.find('e') == std::string::npos)
            std::cout << "double: " << valued << ".0" << std::endl;
        else
            std::cout << "double: " << valued << std::endl;
    }
}
