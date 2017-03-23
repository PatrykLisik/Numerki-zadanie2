#include <fstream>
#include <iostream>
#include <string>
class Menu
{
    std::ostream* out;
    std::istream* in;
    void printBreak();
public:
        std::ostream* getOstrem();
        std::istream* getIstrem();
        template <class T> T getVar(std::string);
       menu(std::ostream* ,std::istream*): out(&std::cout), in(&std::cin);
       menu(): out(&std::cout), in(&std::cin);
       
       
};
