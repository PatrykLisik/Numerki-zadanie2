#include"matrix.h"
#include"eqSolver.h"
#define null 0

void EqSolver::setStop(int it)//intertion
{
    ni=it;
    ep=0;// delta=0 means that iteration mehod has been choosen
}
void EqSolver::setStop(double it)//intertion
{
    ep=it;
    ni=0;// iteration counter=0 means that epsion mehod has been choosen
}
inline bool EqSolver::isStop() // true when loop should stop
{
    return ep*(ep<=del)+ni*(ci<ni); // no-if optymalization
}

void  EqSolver::getMatrix(Matrix* a=null)
{
    if(!a)
    {
        std::cout<<"matrix has been entered / macierz została wprowadzona \n";
        m=a; 
        if(!solutionPointer)
            delete [] solutionPointer;
        solutionPointer=new double[a->getCollumns()];
    }
    
}
EqSolver::EqSolver()
{
    del=0.0;ep=0.0;
    ni=0;ci=0;
    solutionPointer=null;
    m=null;
}
EqSolver::EqSolver(double a,Matrix* b=null)
{
    setStop(a);
    getMatrix(b);
}
EqSolver::EqSolver(int a,Matrix* b=null)
{
    setStop(a);
    getMatrix(b);
}
/*void Matrix::gaussSeidelMethod()
 {
     
     for(int i=0;i<c;i++)
         solutionPointer[i]=0;
     for(int l=0;isStop();l++)
     {
         for(int i=0;i<collumns;i++)
         {
             //no-if optymaliaztion
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
