#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
    private:
        int *value;
    public:
        Data();
        Data(int *value);
        // Data(const Data& obj);
        // ~Data();
        // Data&  operator=(const Data& obj);

        int *getValue();
};

#endif