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

// bool    identifyInf();
// bool    identifyNan();
// bool    identifyC();
// bool    identifyI();
// bool    identifyF();
// bool    identifyD();

// void    validate();

// void    printInf();
// void    printNan();
// void    printC();
// void    printI();
// void    printF();
// void    printD();

int    valid(std::string str)
{
    int e_count = 0;
    int minus_count = 0;
    int f_count = 0;
    int point_count = 0;

    if (str != "-inff" || str != "+inff" || str != "+inf" || str != "-inf" || str != "nan" || str != "nanf")
    {
        if (str.length() != 1)
        {
            size_t i = 0;

            while (str[i])
            {
                char c = str[i];
                if (!std::isdigit(c) && c != 'e' && c != '.' && c != 'f' && c != '-')
                    return(0);
                if (c == 'e') // can't be at beginning or end or before f
                {
                    e_count++;
                    if (e_count > 1 || str[0] == 'e' || str[str.length() - 1] == 'e' || (str[str.length() - 1] == 'f' && str[str.length() - 2] == 'e'))
                        return(0);
                }
                if (c == '-') // must be at beginning
                {
                    minus_count++;
                    if (minus_count > 1 || i > 0)
                        return(0);
                }
                if (c == 'f') // f can only be in the last character of the string
                {
                    f_count++;
                    if (f_count > 2 || i < str.length() - 1)
                        return(0);
                }
                if (c == '.') // point can't be at beginning. Can be at end if after number
                {
                    point_count++;
                    if (point_count > 1 || (i == str.length() - 1 && !std::isdigit(str[i - 1])))
                        return(0);
                }
            // f without dot should also be invalid unless it has an e // HANDLE THIS!!
            // if there is a point and an e that should be invalid // AND THIS!!
            // AND SPECIAL STRINGS SHOULD BE VALID!! 
                i++;
            }
        }
    }
    return (1);
}

void ScalarConverter::convert(std::string str)
{
    // char    valueC = 0;
    // int     valueI = 0;
    // float   valueF = 0;
    // double  valueD = 0;

    // // bool    inf = false;
    // // bool    nan = false;
    // bool    c = false;
    // bool    i = false;
    // bool    f = false;
    // bool    d = false;

    if (!valid(str))
    {
        std::cout << "Error: Invalid input" << std::endl;
        exit(1);
    }
}


// void ScalarConverter::convert(std::string str)
// {
//     char    valueC = 0;
//     int     valueI = 0;
//     float   valueF = 0;
//     double  valueD = 0;

//     bool    i = false;
//     bool    f = false;
//     bool    d = false;
//     bool    special = false;
    
//     if (str == "-inff" || str == "+inff" || str == "+inf" || str == "-inf")
//     {
//         special = true;
//         std::cout << "char: impossible" << std::endl;
//         std::cout << "int: impossible" << std::endl;

//         if (str[str.length() - 1] == 'f' && str[str.length() - 2] == 'f')
//             std::cout << "float: " << str << std::endl;
//         else
//             std::cout << "float: " << str + "f" << std::endl;

//         if (str[str.length() - 1] == 'f' && str[str.length() - 2] == 'f')
//             std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
//         else
//             std::cout << "double: " << str << std::endl;
//     }
//     if (str == "nan" || str == "nanf")
//     {
//         special = true;
//         std::cout << "char: impossible" << std::endl;
//         std::cout << "int: impossible" << std::endl;

//         if (str[str.length() - 1] == 'f') 
//             std::cout << "float: " << str << std::endl;
//         else
//             std::cout << "float: " << str + "f" << std::endl;

//         if (str[str.length() - 1] == 'f')
//             std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
//         else
//             std::cout << "double: " << str << std::endl;
//     }

//     if (special == false && str.length() != 1)
//     {
//         for (char c : str)
//             {
//                 if (!std::isdigit(c) && c != 'e' && c != '.' && c != 'f' && str[0] != '-')
//                 {
//                     std::cout << "Error 1: Invalid input string" << std::endl;
//                     exit(1);
//                 }
//             }
//     }

//     // GET TYPES
//     if (str.find('.') != std::string::npos || str.find('e') != std::string::npos)
//     {
//         if (str.find('f') == str.length() - 1)
//         {
//             try
//             {
//                 valueF = std::stof(str);
//                 std::cout << "literal type is float" << std::endl;
//                 f = true;
//             }
//             catch (const std::out_of_range& e)
//             {
//                 std::cout << "Error: Float is out of range" << std::endl;
//             }
//         }
//         else if (str[str.length() - 1] == '.' || std::isdigit(str[str.length() - 1]))
//         {
//             try
//             {
//                 valueD = std::stod(str);
//                 std::cout << "literal type is double" << std::endl;
//                 d = true;
//             }
//             catch (const std::out_of_range& e)
//             {
//                 std::cout << "Error: Double is out of range" << std::endl;
//             }
//         }
//         else 
//             std::cout << "Error: Invalid characters" << std::endl;
//     }
//     else
//     {
//         try
//         {
//             valueI = std::stoi(str);
//             std::cout << "literal type is int" << std::endl;
//             i = true;
//         }
//         catch (const std::invalid_argument& e) // CAST AND PRINT CHARS
//         {
//             valueC = str[0];
//             if (str.length() == 1)
//                 std::cout << "char: '" << valueC << "'" << std::endl;
//             else
//             {
//                 if (special == false)
//                     std::cout << "Error 2: Invalid input string" << std::endl;
//                 exit(1);
//             }
//             std::cout << "literal type is char" << std::endl;
//             std::cout << "int: " << static_cast<int>(valueC) << std::endl;
//             std::cout << "float: " << static_cast<float>(valueC) << ".0f" << std::endl;
//             std::cout << "double: " << static_cast<double>(valueC) << ".0" << std::endl;
//         }
//         catch (const std::out_of_range& e)
//         {
//             std::cout << "Error: Integer is out of range" << std::endl;
//         }
//     }

//     // CAST AND PRINT INTS, FLOATS AND DOUBLES
//     if (i)
//     {
//         if (std::isprint(valueI))
//             std::cout << "char: '" << static_cast<char>(valueI) << "'" << std::endl;
//         else
//             std::cout << "char: Non displayable" << std::endl;
//         std::cout << "int: " << valueI << std::endl;
//         std::cout << "float: " << static_cast<float>(valueI) << ".0f" << std::endl;
//         std::cout << "double: " << static_cast<double>(valueI) << ".0" << std::endl;
//     }
//     if (f)
//     {
//         if (valueF == std::floor(valueF) && valueF >= 32 && valueF <= 126)
//             std::cout << "char: '" << static_cast<char>(valueF) << "'" << std::endl;
//         else
//             std::cout << "char: Non displayable" << std::endl;


//         if (valueF > static_cast<float>(std::numeric_limits<int>::max()) || valueF < static_cast<float>(std::numeric_limits<int>::min()))
//             std::cout << "int: impossible" << std::endl;
//         else
//             std::cout << "int: " << static_cast<int>(valueF) << std::endl;


//         if (valueF == std::floor(valueF) && str.find('e') == std::string::npos)
//             std::cout << "float: " << valueF << ".0f" << std::endl;
//         else
//             std::cout << "float: " << valueF << "f" << std::endl;
//         if (valueF == std::floor(valueF) && str.find('e') == std::string::npos)
//             std::cout << "double: " << static_cast<double>(valueF) << ".0" << std::endl;
//         else
//             std::cout << "double: " << static_cast<double>(valueF) << std::endl;
//     }
//     if (d)
//     {
//         if (valueD == std::floor(valueF) && std::isprint(valueD))
//             std::cout << "char: '" << static_cast<char>(valueD) << "'" << std::endl;
//         else
//             std::cout << "char: Non displayable" << std::endl;
        
        
//         if (valueD > std::numeric_limits<int>::max() || valueD < std::numeric_limits<int>::min())
//             std::cout << "int: impossible" << std::endl;
//         else
//             std::cout << "int: " << static_cast<int>(valueD) << std::endl;


//         if (valueD == std::floor(valueD) && str.find('e') == std::string::npos)
//             std::cout << "float: " << static_cast<float>(valueD) << ".0f" << std::endl;
//         else
//             std::cout << "float: " << static_cast<float>(valueD) << "f" << std::endl;
//         if (valueD == std::floor(valueD) && str.find('e') == std::string::npos)
//             std::cout << "double: " << valueD << ".0" << std::endl;
//         else
//             std::cout << "double: " << valueD << std::endl;
//     }
// }
