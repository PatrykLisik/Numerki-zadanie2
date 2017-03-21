#include <fstream>
#include <iostream>
#include <string>
class Menu
{
    std::ostream* output;
    std::istream* input;
    void printBreak();
public:
        std::ostream* getOstrem(string);
        std::istream* getIstrem(string);
        template <class T> T getT(string);
       menu(std::ostream* ,std::istream*,double,double,int,bool);
       
       
};
