#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>

class Base
{
    private:
        Base * generate(void)
        {
            // Seed the random number generator
            //srand(static_cast<unsigned>(time(0)));

            int random_number = (rand() % 3) + 1;

            switch (random_number)
            {
                case 1:
                    return ()
                    break ;
            }
        }
    public:
        virtual ~Base() {};
};

#endif