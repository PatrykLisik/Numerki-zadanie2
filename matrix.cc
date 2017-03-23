#include "matrix.h" 
#include <iostream>

Matrix::Matrix(const int r,const int c)
{
  double** tempMatrixPointer=new double*[r];
     for(int j=0;j<r;j++)
         tempMatrixPointer[j]=new double[c];
     
     
     for(int i=0;i<rows;i++)
         for(int j=0;j<collumns;j++)
             matrixPointer[i][j]=0;
     
     matrixPointer= tempMatrixPointer;
     rows=r;
     collumns=c;

}

double Matrix::getCell(const int x, const int y) {return matrixPointer[x][y];}

void Matrix::setCell(const int x, const int y, const double var){matrixPointer[x][y]=var;}

int Matrix::getRows(){return rows;}
int Matrix::getCollumns(){return collumns;}

std::ostream& operator << (std::ostream& a, Matrix& m)
{
    //setprecision parameter should be added amd later output can be mor fancy 
    for(int i=0;i<m.rows;i++)
   {     a<<"|";
         for(int j=0;j<m.collumns;j++)
             a<<m.getCell(i,j)<<" ";//burwa czm to tego tego nie widzi
         a<<"|\n";
   }

}
std::istream& operator>> (std::istream& in, Matrix& m)
 {
     for(int i=0;i<m.rows;i++)
     {
         for(int j=0;j<m.collumns;j++)
         {
             double temp;
             in>>temp;
             m.setCell(i,j,temp);
         }
             
     } 
         return in;
 }
 Matrix::~Matrix()
 {
      //dealocating memory burwa
   
    for(int i=0;i<rows;i++)
        delete [] matrixPointer[i];
    delete [] matrixPointer; 
    std:: cout<<"DEstructor matrix delted \n";
 }
void Matrix::resize(const int& r,const int& c)
 {
     double** tempMatrixPointer=new double*[r];
     for(int j=0;j<r;j++)
         tempMatrixPointer[j]=new double[c];
     
   
     //std::cout<<"rewrite \n";
      for(int i=0;i<r;i++)
         for(int j=0;j<c;j++)
             tempMatrixPointer[i][j]=matrixPointer[i][j];
  
         //std::cout<<"del old Matrix() \n";
         for(int i=0;i<rows;i++)
        delete [] matrixPointer[i];
    delete [] matrixPointer;
             
     matrixPointer= tempMatrixPointer;
     rows=r;
     collumns=c;
 }
 void Matrix::resize(){resize(rows+1;column+1);}
 /*
 inline bool isStop(double delta, double epsilon, int iteration, int iend, bool isIteration){
    if(isIteration)
        return iteration<=iend;
    else
        //cout << delta << ' ' << epsilon << '\n';
        return delta>epsilon;
}*/

/* void Matrix::gaussSeidelMethod();
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
 }*/
