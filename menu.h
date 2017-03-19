#include<string.h>
class menu
{
    void printBreak();
public:
    std::ostream out;
    std::istream in;
    int getInt(string); // get description, gave value
    std::ostream getOstream();
    std::istream getIstream();
    menu(std::ostream, std::istream); //constructor
    ~menu(); // to do close file
    
};
