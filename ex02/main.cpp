#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p)
{
    std::cout << "Identify pointer: ";
    if (dynamic_cast<A*>(p)) // returns a nullptr on failure
        std::cout << "A type" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B type" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C type" << std::endl;
}

void identify(Base& p)
{
    std::cout << "Identify reference: ";
    try
    {
        A& a_ref = dynamic_cast<A&>(p); // throws an exception on failure
        std::cout << "A type" << std::endl;
        (void)a_ref;
    }
    catch (const std::bad_cast& e){}
    try
    {
        B& b_ref = dynamic_cast<B&>(p);
        std::cout << "B type" << std::endl;
        (void)b_ref;
    }
    catch (const std::bad_cast& e){}
    try
    {
        C& c_ref = dynamic_cast<C&>(p);
        std::cout << "C type" << std::endl;
        (void)c_ref;
    }
    catch (const std::bad_cast& e){}
}

Base * generate(void)
{
    srand(static_cast<unsigned>(time(0)));

    int random_number = (rand() % 3) + 1;

    switch (random_number)
    {
        case 1:
            std::cout << "A generated" << std::endl;
            return (new A);
        case 2:
            std::cout << "B generated" << std::endl;
            return (new B);
        case 3:
            std::cout << "C generated" << std::endl;
            return (new C);
            break ;
        default:
            return (nullptr);
    }
}

int main(void)
{
    Base *ptr = generate();
    Base& ref = *ptr;
    
    identify(ptr);
    identify(ref);

    delete ptr;
}