#include<iostream>
#include<fstream>
#include"matrix.h"
#include"string"
#include<algorithm>//max
#include<math.h>//fabs
#define oo 2137148800

using namespace std;
static int il_iteracji=0;
double delta(double *cur,double prv[],int l)
{    double sol=0;
    while(l-->0)
        sol=max(sol,fabs(prv[l]-cur[l]));
    //cout<<"Delta: "<<sol<<"\n";
        return sol;}

inline bool isStop(int nOfiter,int ci, double det, double ep){return nOfiter*(ci<nOfiter)+ep*(det>ep);}

double* gaussSeidelMethod(Matrix *m,int iter, double ep)
{
   m->sort();
   double*tab=new double[m->getRows()];
   double prv[m->getRows()];
   //cout<<"det "<<delta(tab,prv,m->getRows())<<"\n";
   for(int i=0;i<m->getRows();i++) {tab[i]=0.0;prv[i]=oo;}
   
   for(int k=0;isStop(iter,k,delta(tab,prv,m->getRows()),ep);k++)
   { 
       //cout<<"det "<<delta(tab,prv,m->getRows())<<"\n";
       il_iteracji++;
       for(int l=0;(l<(m->getRows)())*k;l++) //rewriting tab to prv if k !=0
       prv[l]=tab[l];
       
   for(int i=0;i<m->getRows();i++)
   {
       double temp1=0;
       double temp=m->getCell(i,m->getCollumns()-1);
       prv[i]=tab[i];
       tab[i]=0;
       for(int j=0;j<((m->getCollumns)()-1);j++)
           temp1-=tab[j]*(m->getCell)(i,j);
       
       tab[i]=(temp+temp1)/m->getCell(i,i);
//       cout<<"wyk: "<<tab[i]<<"\n";
   }
   }
   return tab;
}
void swapRows(double **M, int a, int b){
    double *tmp;
    tmp=M[a];
    M[a]=M[b];
    M[b]=tmp;
}
bool zbieznosc(Matrix *m){

    /*//SKOPIUJ MACIERZ BEZ WYRAZÓW WOLNYCH
    int n=m->getRows();
    double **M=new double *[n];
    for(int i=0; i<n; i++){
        M[i]=new double [n];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            M[i][j]=m->getCell(i, j);
        }
    }

    //POZAMIENIAJ RZĘDY
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            int idx=0;
            for(int r=i+1; r<n; r++){
                if(M[i][i]-M[r][i]<M[i][r]-M[r][r]){
                    idx=r;
                    break;
                }
            }
            if(idx>0)
                swapRows(M, idx, i);
        }
    }*/
    m->sort();
    //SPRAWDŹ ZBIEŻNOŚĆ
    double diagonal=0, other=0; //sumy elementów
    for(int i=0; i<m->getRows(); i++){
        for(int j=0; j<m->getRows(); j++){
            if(i==j){
                diagonal+=fabs(m->getCell(i,j));
            }else{
                other+=fabs(m->getCell(i,j));
            }
        }
        if(diagonal<other) return false;
    }

    return true;
}
inline void lineBreak(){
    cout<<"+------------------------------------------------------+ \n";
}

int main()
{

    int nOfiter, nOfMatrix=0;
    	double ep;
    	//MENU GŁÓWNE
    	lineBreak();
    cout<<"Wybierz warunek stopu\n"
        <<"<i> aby wybrać ilość iteracji\n"
        <<"<e> aby wybrać wartość epsilon\n";
        lineBreak();
        char sw[3];
        cin >> *sw;
        if(*sw=='i' or *sw=='I')
        {
            lineBreak();
            cout<<"Podaj ilość iteracji\n";
            lineBreak();
            cin>>nOfiter;
            ep=0;
        }else
        {
            lineBreak();
            cout<<"Podaj wartość epsilon\n";
            cin>>ep;
            nOfiter=0;
        }
                lineBreak();
                cout<<"podaj macierz\n";
            	int a,b;
                cin>>a>>b;
		Matrix* matrix=new Matrix(a, b);
                cin>>*matrix;
            
		//SPRAWDZENIE ZBIEŻNOŚCI I OBLICZENIA
                double *tab;
            	if(zbieznosc(matrix))
                {
                    tab=gaussSeidelMethod(matrix,nOfiter,ep);
            	}else{
                	cout << "Metoda nie jest zbieżna dla danego układu równań\n Zostnie przeprowadzone 5 iteracji \n";
            		tab=gaussSeidelMethod(matrix,5,0);
                }
                cout<<"Macierz \n"<<*matrix<<"\n";
                cout<<"Wyniki: "; 
            	for(int i=0;i<a;i++)
                		cout<<"x"<<i+1<<":"<<" "<<tab[i]<<" ";
                	cout<<"  wykonano: "<<il_iteracji<<" iteracji"<<"\n"; 
            	//KONIEC
            	delete [] tab;
            	delete matrix;
        
    
   /*while(true)
   {
       int a,b;
                cin>>a>>b;
		Matrix* m=new Matrix(a, b);
    cin>>*m;
    cout<<"IN:\n"<<*m<<"\n";
    m->sort();
    cout<<"OUT: \n"<<*m<<"\n";
    }*/
    
    	return 0;
}
