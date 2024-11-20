#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>
# include <cmath>
# include <regex>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& obj);
    public:
        ScalarConverter& operator=(const ScalarConverter& obj);
		~ScalarConverter();

        static void convert(std::string str);
};

int    valid(std::string str);

#endif