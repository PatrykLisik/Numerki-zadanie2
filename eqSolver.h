

class EqSolver //gaus-seidel
{
    double del,ep;// delta epsilon
    int ni,ci;//number of interations, current iterarion
    int *solutionPointer;
    Matrix* m; //demand Matrix.h
     
    double delta(); // in lecture algorithm wos said to be hard eq 
    inline bool isStop();
public:
    bool cove;// is covergence or not
    EqSolver();
    EqSolver(double, Matrix*) ;//epsilon, matrix pointer
    EqSolver(int,Matrix* );//number of iteration matrix pointer
    ~EqSolver();
    void gaussSeidelMethod();
    void setStop(double); //epsilon
    void setStop(int);//iteration 
    void getMatrix(Matrix* );
    bool isCovergence();//zbierzność
};
