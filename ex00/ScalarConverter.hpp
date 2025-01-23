#pragma once

# include <iostream>
# include <limits>
# include <cmath>

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