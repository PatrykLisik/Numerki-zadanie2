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
    a<<"["solutionPointer[i]<<" ] ";
    return a;
}
 std::istream& Matrix::operator>> (std::istream&in)
 {
     for(int i=0;i<rows;i++)
         for(int j=0;j<collumns;j++)
             in>>matrixPointer[i][j];
         
         return in;
 }
 
 inline bool isStop(double delta, double epsilon, int iteration, int iend, bool isIteration){
    if(isIteration)
        return iteration<=iend;
    else
        //cout << delta << ' ' << epsilon << '\n';
        return delta>epsilon;
}

 void Matrix::gaussSeidelMethod();
 {
     for(int i=0;i<c;i++)
         solutionPointer[i]=0;
     for(int l=0;isStop();l++)
     {
         for(int i=0;i<collumns;i++)
         {
             //no if optymaliaztion
             temp=matrixPointer[i][i];
             matrixPointer[i][i]=0;
             matrixPointer[i][collumns-1]*=-1;
             
             for(intj=0;j<rows;j++)
             {
                 solutionPointer[i]-=matrixPointer[i][j];
             }
             solutionPointer[i]/=temp;
             
             //orginal values come back to to matrix
             matrixPointer[i][collumns-1]*=-1;
             matrixPointer[i][i]=temp;
         }
     }
 }
