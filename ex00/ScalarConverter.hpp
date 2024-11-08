#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
    private:
        ScalarConverter();
        // ScalarConverter();
        // ScalarConverter(const ScalarConverter& obj);
        // ~ScalarConverter();
        // ScalarConverter&  operator=(const ScalarConverter& obj);
    public:
        static void convert(std::string str);
};

#endif