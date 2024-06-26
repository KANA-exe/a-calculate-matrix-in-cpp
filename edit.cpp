#include<iostream>
#include"matrix_cal.h"

using namespace std;

void inv_mtx(double** a,int i,int j,double** ans){
    if(i!=j||i!=2||i!=2){
        cout << "error:the matrix cannot calculate second order determainate";
        exit;
    }

    double s[2][2]={{a[1][1],a[0][1]},{a[1][0],a[0][0]}};
    double c=1/det_mtx(a,i,j);
    double h=0;
    s[0][1]=s[0][1]*-1;
    s[1][0]=s[1][0]*-1;

    for(int d=0;d<2;d++){
        for(int l=0;l<2;l++){
            
        }
    }
}

main()
{
    //import journey 
    int i=2;
    int j=3;

    //create matrix a and pointer ad_a
    double a[i][j]={{3,1},{1,0}};
    
    double* ad_a[i]={};
    for(int t=0;t<i;t++){
        ad_a[t]=a[t];
    }

    //ceate matrix c and pointer ad_c
    double c[j][i]={{2,-1},{3,2},{5,3}};
    
    double* ad_c[j]={};
    for(int t=0;t<j;t++){
        ad_c[t]=c[t];
    }

    double sf=10;
    
    //ceate a matrix for answer
    double* ans[i]={};

    //calculate and export
    inv_mtx(ad_a,i,i,ans);
    expt_mtx(ans,i,i);

    // free dynamically allocated memory
    for (int t=0;t<i;t++) {
        delete[] ans[t];
    }
    
    
    return 0;
}
