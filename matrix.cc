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

double Matrix::getCell(const int x, const int y)
{  
    if(y<collumns and x<rows) 
    return matrixPointer[x][y];
    else {
        std::cerr<<"invalid acces  \n rows: "<<rows<<" \n x:"<<x<<"\n collumns:"<<collumns<<"\n y:"<<y<<"\n";
        exit(1);
        } 
    }

void Matrix::setCell(const int x, const int y, const double var){
    if(x<rows and y<collumns)
    matrixPointer[x][y]=var;
    else
        std::cerr<<"invalid value  \n rows: "<<rows<<" \n x:"<<x<<"\n collumns:"<<collumns<<"\n y:"<<y<<"\n";
}

int Matrix::getRows(){return rows;}
int Matrix::getCollumns(){return collumns;}

std::ostream& operator << (std::ostream& a, Matrix& m)
{
    //setprecision parameter should be added and output can be more fancy 
    for(int i=0;i<m.getRows();i++)
   {     a<<"|";
         for(int j=0;j<m.getCollumns();j++)
             a<<m.getCell(i,j)<<" ";
         a<<"|\n";
   }
return a;
}
std::istream& operator>>(std::istream& in, Matrix& m){
     for(int i=0;i<m.rows;i++)
         for(int j=0;j<m.collumns;j++)
         {
             double temp;
             in>>temp;
             m.setCell(i,j,temp);
         }
         return in;
 }
 Matrix::~Matrix()
 {
      //dealocating memory 
//   std:: cout<<"DEstructor matrix delted \n";
    for(int i=0;i<rows;i++)
        delete [] matrixPointer[i];
    delete [] matrixPointer; 
 }
void Matrix::resize(const int& r,const int& c)
 {
     double** tempMatrixPointer=new double*[r];
     for(int j=0;j<r;j++)
         tempMatrixPointer[j]=new double[c];
   
     //std::cout<<"rewrite \n";
      for(int i=0;i<rows;i++)
         for(int j=0;j<collumns;j++)
             tempMatrixPointer[i][j]=matrixPointer[i][j];
  
         //std::cout<<"del old Matrix() \n";
         for(int i=0;i<rows;i++)
        delete [] matrixPointer[i];
    delete [] matrixPointer;
             
     matrixPointer= tempMatrixPointer;
     rows=r;
     collumns=c;
 }
 void Matrix::resize(){resize(rows+1,collumns+1);}

 void Matrix::swapRows(int a, int b)
 {
     double *tmp;
     tmp=matrixPointer[a];
    matrixPointer[a]=matrixPointer[b];
    matrixPointer[b]=tmp;
 }
 void Matrix::sort()
 {
     for(int k=0; k<rows; k++){
        for(int i=0; i<rows; i++){
            int idx=0;
            for(int r=i+1; r<rows; r++){
                if(matrixPointer[i][i]-matrixPointer[r][i]<matrixPointer[i][r]-matrixPointer[r][r]){
                    idx=r;
                    break;
                }
            }
            if(idx>0)
                swapRows(idx, i);
        }
    }
 }
