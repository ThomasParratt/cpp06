#pragma once

# include <iostream>
# include <limits>
# include <cmath>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& obj) = delete;
        ScalarConverter& operator=(const ScalarConverter& obj) = delete;
		~ScalarConverter();
    public:

        static void convert(std::string str);
};