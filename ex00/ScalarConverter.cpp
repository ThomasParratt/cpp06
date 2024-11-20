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

int    valid(std::string str)
{
    int e_count = 0;
    int minus_count = 0;
    int f_count = 0;
    int point_count = 0;
    size_t i = 0;

    if (str != "-inff" && str != "+inff" && str != "+inf" && str != "-inf" && str != "nan" && str != "nanf")
    {
        if (str.length() != 1)
        {
            while (str[i])
            {
                char c = str[i];
                if (!std::isdigit(c) && c != 'e' && c != '.' && c != 'f' && c != '-')
                    return (0);
                else if (c == 'e') // can't be at beginning or end or immediately before f
                {
                    e_count++;
                    if (e_count > 1 || str[0] == 'e' || str[str.length() - 1] == 'e' || (str[str.length() - 1] == 'f' && str[str.length() - 2] == 'e'))
                        return  (0);
                }
                else if (c == '-') // must be at beginning unless immediately after e
                {
                    minus_count++;
                    if (minus_count > 1 || (i > 0 && str[i - 1] != 'e'))
                        return (0);
                }
                else if (c == 'f') // f can only be in the last character of the string
                {
                    f_count++;
                    if (f_count > 2 || i < str.length() - 1)
                        return (0);
                }
                else if (c == '.') // point can be at end if after number
                {
                    point_count++;
                    if (point_count > 1 || (i == str.length() - 1 && !std::isdigit(str[i - 1])))
                        return (0);
                } 
                i++;
            }
        }
        if (str.find('f') != std::string::npos && str.find('.') == std::string::npos && str.find('e') == std::string::npos) // contains f and no point and no e
            return (0);
        if (str.find('.') != std::string::npos && str.find('e') != std::string::npos) // contains a point and an e
        {
            if (str.find('.') > str.find('e')) // point can be before e
                return (0);
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
    bool    special = false;

    if (!valid(str))
    {
        std::cout << "Error: Invalid input" << std::endl;
        exit(1);
    }

    // GET TYPES
    if (str.find('.') != std::string::npos || str.find('e') != std::string::npos 
        || str == "-inff" || str == "+inff" || str == "+inf" || str == "-inf" || str == "nan" || str == "nanf")
    {
        if (str[str.length() - 1] == 'f' && str != "+inf" && str != "-inf")
        {
            if (str == "+inff" || str == "-inff" || str == "nanf")
                special = true;
            try
            {
                valueF = std::stof(str);
                std::cout << "literal type is float" << std::endl;
                f = true;
            }
            catch (const std::out_of_range& e)
            {
                std::cout << "Error: Float is out of range" << std::endl;
            }
        }
        else if (str[str.length() - 1] == '.' || std::isdigit(str[str.length() - 1]) || str == "+inf" || str == "-inf" || str == "nan")
        {
            if (str == "+inf" || str == "-inf" || str == "nan")
                special = true;
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
    else
    {
        try
        {
            valueI = std::stoi(str);
            std::cout << "literal type is int" << std::endl;
            i = true;
        }
        catch (const std::invalid_argument& e) // CAST AND PRINT CHARS
        {
            valueC = str[0];
            if (str.length() == 1)
                std::cout << "char: '" << valueC << "'" << std::endl;
            std::cout << "literal type is char" << std::endl;
            std::cout << "int: " << static_cast<int>(valueC) << std::endl;
            std::cout << "float: " << static_cast<float>(valueC) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(valueC) << ".0" << std::endl;
        }
        catch (const std::out_of_range& e)
        {
            std::cout << "Error: Integer is out of range" << std::endl;
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
        std::cout << "float: " << static_cast<float>(valueI) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(valueI) << ".0" << std::endl;
    }
    if (f)
    {
        if (valueF == std::floor(valueF) && valueF >= 32 && valueF <= 126)
            std::cout << "char: '" << static_cast<char>(valueF) << "'" << std::endl;
        else if (valueF == std::floor(valueF) && valueF >= 0 && valueF <= 255)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;

        if (valueF > static_cast<float>(std::numeric_limits<int>::max()) || valueF < static_cast<float>(std::numeric_limits<int>::min()) || str == "nanf")
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(valueF) << std::endl;


        if ((valueF == std::floor(valueF) && str.find('e') != std::string::npos) && !special)
            std::cout << "float: " << valueF << ".0f" << std::endl;
        else
            std::cout << "float: " << valueF << "f" << std::endl;
        if ((valueF == std::floor(valueF) && str.find('e') != std::string::npos) && !special)
            std::cout << "double: " << static_cast<double>(valueF) << ".0" << std::endl;
        else
            std::cout << "double: " << static_cast<double>(valueF) << std::endl;
    }
    if (d)
    {
        if (valueD == std::floor(valueD) && valueD >= 32 && valueD <= 126)
            std::cout << "char: '" << static_cast<char>(valueD) << "'" << std::endl;
        else if (valueD == std::floor(valueF) && valueD >= 0 && valueD <= 255)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
            
            
        if (valueD > std::numeric_limits<int>::max() || valueD < std::numeric_limits<int>::min() || str == "nan")
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(valueD) << std::endl;


        if ((valueD == std::floor(valueD) && str.find('e') != std::string::npos) && !special)
            std::cout << "float: " << static_cast<float>(valueD) << ".0f" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(valueD) << "f" << std::endl;
        if ((valueD == std::floor(valueD) && str.find('e') != std::string::npos) && !special)
            std::cout << "double: " << valueD << ".0" << std::endl;
        else
            std::cout << "double: " << valueD << std::endl;
    }
}
