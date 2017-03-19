#include<iostream>

class matrix{
    double **matrixPointer;
    double *solutionPointer;
    int rows, collumns;
    std::ostream& operator<< (ostream&);// get matrix
    std::istream& operator>> (istream&);// print solution
    matrix(int,int);
    ~matrix();//celan memory delete pointers
    bool isConvergence(); //check if exapmle is solveable
    void gaussSeidelMethod(); // fill solution table with solution
};
