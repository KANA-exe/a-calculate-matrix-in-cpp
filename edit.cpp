#include<iostream>
#include<string>
#include"matrix_cal.h"

using namespace std;

main()
{
    //import basic information of matrix
    int qua;//qua:quantity of matrix
    
    cout <<"input the matrix quantity.(input a number)";//input quantity of matrix
    cin >>qua;

    int li;
    int lj; 
    cout <<"input the largest matrix.(if it's a*b,input a b.)";//input largest matrix of size of matrix
    cin >>li >>lj;

    //declare matrix of array and matrix index of array
    double mtx[qua][li][lj]={};
    int i[qua]={};
    int j[qua]={};
    string ch[qua]={};//name of matrix

    //input matrix
    for(int in=0;in<qua;in++){
        cout <<"input the martix name.";//input matrix name
        cin >> ch[in];

        cout <<"input the lines and row.";//input line and row
        cin >> j[in] >>i[in];

        for(int s=0;s<i[in];s++){//input the metrix
            cout <<"input the " <<s <<"-th row.(extra input will be ignored)";
            for(int x=0;x<j[in];x++){
                cin >>mtx[in][s][x];
            }
        }
    }

    bool d=true;
    while(d){//check and modify
        cout <<"please check all matrix." <<endl;//output all of matrix
        for(int s=0;s<qua;s++){
                //create temporary pointer
                double* tem[i[s]]={};
                for(int a=0;a<i[s];a++){
                    tem[a]=mtx[s][a];
                }

                //output matrix
                cout <<ch[s] <<"=" <<endl;
                expt_mtx(tem,i[s],j[s]);
                cout <<endl;

                //free memory
                for(int t;t<i[s];t++){
                    delete [] tem[t];
                }
            }
        
        
        
        string ans;

        //check matrix
        cout <<"Do these matrices contain errors?(input Yes/No)";
        cin >>ans;

        //determine whether modification is needed
        if(ans=="No"){//not need
            string a;
            cout <<"sure?(input Yes/No)(cannot be modified later)";//last check no to modify
            if(a=="Yes"){
                d=false;
                break;
            }
            else if(a=="No"){

            }
            else{//invalid input
                cout <<"error:the input is invalid"
            }
        }
        else if(ans=="Yes"){//need
                
            bool o=true;
            while(o){
                    
                string answ;
                cout <<"input name of matrix that need to modify(if don't need,type /end)";//input name of matrix that need to modify
                cin >>answ;
                
                if(answ=="/end"){//determine whether it is over
                    o=false;
                        break;
                }
                else{
                    int se;
                    bool p=true;
                    while(p){
                        bool n=true;

                        for(int ser=0;ser<qua;ser++){//search matrix
                            if(ch[ser]==answ){//found
                                se=ser;
                            }
                            else{//not found
                                cout <<"error:not found the matrix";
                                n=false;
                            }
                        }
                        while (n)
                        {
                            string an;
                            cout <<"input element you want to modify(input name/element.if don't need,type /end)";
                            cin >>an;
                            if(an=="/end"){//end modify
                                n=false;
                                p=false;
                                break;
                            }
                            else if(an=="name"){//modify name
                            string naw;
                            cout <<"input new name";
                            cin >>naw;
                            }
                            else if (an=="element"){//modify element
                                int ans;
                                cout <<"input the row that need to modify";
                                cin >>ans;

                                double ac;
                                cout <<"input the new row";

                                for(int t;t<i[se];t++){
                                    cin >>ac;
                                    mtx[se][ans][t]=ac;
                                }
                            }
                            else{//invalid input
                                cout <<"error:the input is invalid";
                            }
                        }
                    }
                }
            }
        }
        else{//invalid input
            cout <<"error:input is invalid";
        }
    }
    
    cout <<"**********input finish***********";
    
    return 0;
}
