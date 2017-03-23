#include<iostream>
#include<fstream>
//#include"menu.h"
#include"matrix.h"
#include"eqSolver.h"//demand matrix.h

using namespace std;

int main()
{
    
    Matrix matrix(2,3);
    cin>>matrix;
     cout<<matrix<<"\n";
    matrix.resize(2,2);
    cout<<matrix;
    /*Menu.getIstrem();
    
    matrix a;
    Menu.in>>a;
    if(a.isCovergence())
        a.gaussSeideMethod();
    Menu.out<<a<<"\n";*/
    
}
