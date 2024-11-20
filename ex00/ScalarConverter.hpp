#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>
# include <cmath>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& obj);

        // bool    identifyInf();
        // bool    identifyNan();
        // bool    identifyC();
        // bool    identifyI();
        // bool    identifyF();
        // bool    identifyD();

        // void    validate(std::string str);

        // void    printInf();
        // void    printNan();
        // void    printC();
        // void    printI();
        // void    printF();
        // void    printD();
    public:
        ScalarConverter& operator=(const ScalarConverter& obj);
		~ScalarConverter();

        static void convert(std::string str);
};



#endif