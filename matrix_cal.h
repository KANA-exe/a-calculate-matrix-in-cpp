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