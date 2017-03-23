#include<iostream>


class Matrix{
double **matrixPointer;
    int rows, collumns;
    friend std::ostream& operator<<(std::ostream& out, Matrix& m);// get matrix
    friend std::istream& operator>>(std::istream& out, Matrix& m);// print matrix
public:
    double getCell(const int,const int);
    void setCell(const int,const int,const double);
    Matrix(const int,const int);
    ~Matrix();//celan memory, delete pointers
    void resize(const int&,const int&);
    void resize();
    int getRows();
    int getCollumns();
    
};
