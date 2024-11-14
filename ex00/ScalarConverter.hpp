#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

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

#endif