#include<iostream>
using namespace std;

//export
void expt_mtx(double** a,int i,int j){
    for(int h=0;h<i;h++){
        for(int t=0;t<j;t++){
            cout << a[h][t] <<" ";
        }
        cout <<endl;
    }
}

//addition(a+b)
void add_mtx(double** a,double** b,int i,int j,double** anf){
    for(int s=0;s<i;s++){
         anf[s] = new double[j];
        for(int k=0;k<j;k++){
            anf[s][k]=a[s][k]+b[s][k];
        }
    }
}

//Subtraction(a-b)
void sub_mtx(double** a,double** b,int i,int j,double** anf){
    for(int s=0;s<i;s++){
         anf[s] = new double[j];
        for(int k=0;k<j;k++){
            anf[s][k]=a[s][k]-b[s][k];
        }
    }
}

//multiplication(double*matrix)
void mul_int_mtx(double** a,double c,int i,int j,double** anf){
    for(int s=0;s<i;s++){
         anf[s] = new double[j];
        for(int k=0;k<j;k++){
            anf[s][k]=a[s][k]*c;
        }
    }
}

//multiplication(matrix*matrix)
void mul_mtx_mtx(double** a,double** b,int ia,int ja,int ib,int jb,double** anf){
    //Matrix multiplication conditional judgment
    if (ja!=ib){
        cout <<"error:These two matrices cannot be multiplied";
    }

    //Matrix multiplication runs
    double t;
    for(int s=0;s<ia;s++){
        anf[s] = new double[jb];
        for(int k=0;k<jb;k++){
            t=0;
            for(int l=0;l<ja;l++){
                t=t+(a[s][l]*b[l][k]);
            }
            anf[s][k]=t;
        }
    }
}

//calculate 2*2 determain
double det_mtx(double** a,int i,int j){
    if(i!=j||i!=2||i!=2){
        cout << "error:the matrix cannot calculate second order determainate";
        exit;
    }

    return (a[1][1]*a[0][0])-(a[0][1]*a[1][0]);
}

//inverse matrix
void inv_mtx(double** a,int i,int j,double** ans1){
    if(i!=j||i!=2||i!=2){
        cout << "error:the matrix cannot calculate second order determainate";
        exit;
    }

    for(int k=0;k<j;k++){
            ans1[k] = new double[j];
        }

    ans1[0][0]=a[1][1];
    ans1[0][1]=-1*a[0][1];
    ans1[1][0]=-1*a[1][0];
    ans1[1][1]=a[0][0];

    double c=1/det_mtx(a,i,i);

    for(int k=0;k<i;k++){
        for(int l=0;l<j;l++){
            ans1[k][l]=ans1[k][l]*c;
        }
    }

