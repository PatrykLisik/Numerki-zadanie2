#include<iostream>


class Matrix{
double **matrixPointer;
    double *solutionPointer;
    int rows, collumns;
    stop s;
public:
    std::ostream& operator<< (std::ostream&);// print solution
    std::istream& operator>> (std::istream&);// get matrix
    Matrix(const int,const int);
    //~matrix();//celan memory, delete pointers
    bool isConvergence(); //check if exapmle is solveable
    void gaussSeidelMethod(); // fill solution table with solution
};
