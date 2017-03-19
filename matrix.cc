#include "matrix.h" 

Matrix::Matrix(const int r,const int c)
{
    rows=r;
    collumns=c;
    solutionPointer= new double[c];
    matrixPointer= new double*[r];
    for(int i=0;i<r;i++)
        matrixPointer[i]=new double[c];

}
std::ostream& Matrix::operator<< (std::ostream&a)
{
    for(int i=0;i<collumns;i++)
    a<<solutionPointer[i];
    return a;
}
 std::istream& Matrix::operator>> (std::istream&in)
 {
     for(int i=0;i<rows;i++)
         for(int j=0;j<collumns;j++)
             in>>matrixPointer[i][j];
         
         return in;
 }
