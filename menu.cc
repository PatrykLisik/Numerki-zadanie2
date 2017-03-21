#include"menu.h"
#include<string>
#include<fstream>
#include <iostream>

void menu::printBreak()
{
    std::cout<<"+------------------------------------------+";
}

std::ostream* menu::getOstrem()
{
    printBreak();
    std::cout<<"Choose your out-stream \n type cout to out out to constole \n type any other string to name output file"
    std::string temp;
    std::cin>>temp;
    if(temp!="cin")
    {
        ofstream plik-out(str.c_str());
        out=&plik-out;
    } else
        out=&std::cout;
    retun out; 
}

std::istream* menu::getIstrem()
{
    printBreak();
    std::cout<<"Choose your in-stream \n type cin to in from constole \n type any other string to name intput file"
    std::string temp;
    std::cin>>temp;
    if(temp!="cout")
    {
        ifstream plik-in(str.c_str());
        in=&plik-in;
    } else
        in=&std::cin;
    retun in; 
}
menu::menu(std::ostream* o=&std::cout,std::istream*i=&std::cin)
{
    out=o;
    in=i;
}
  
menu::menu()
{
    in=getIstrem();
    out=getOstrem();
}

template <class T> T menu::getVar(std::string str);
{
    printBreak();
    cout<<str<<"\n";
    T var;
    cin>>var;
    retun var;
}
