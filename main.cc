#include<iostream>
#include<fstream>
#include"menu.h"
#include"matrix.h"

using namespace std;

int main()
{
    menu Menu;
    Menu.getOstrem();
    Menu.getIstrem();
    
    matrix a;
    Menu.in>>a;
    if(a.isCovergence())
        a.gaussSeideMethod();
    Menu.out<<a<<"\n";
    ////Choose int
}
