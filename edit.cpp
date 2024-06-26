#include<iostream>
#include"matrix_cal.h"

using namespace std;

main()
{
    //import journey 
    int i=2;
    int j=3;

    //create matrix a and pointer ad_a
    double a[i][j]={{3,1,-2},{1,0,4}};
    
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
    mul_mtx_mtx(ad_a,ad_c,i,j,j,i,ans);
    expt_mtx(ans,i,i);

    // free dynamically allocated memory
    for (int t=0;t<i;t++) {
        delete[] ans[t];
    }
    
    
    return 0;
}