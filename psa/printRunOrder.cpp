//打印安全性检查执行序列

#include<iostream>
#include "global.h"
using namespace std;

void printRunOrder(int result)
{
    if(result==PROGRESS){
        cout<<"资源分配表："<<endl;
        cout<<" process\\Resources"<<" Work(A B C)"<<"Need(A B C)"
            <<"Allocation(A B C)"<<"Work+Allocation(A B C)"<<"Finish"<<endl;

        for(int i=0;i<PROGRESS;i++){
            cout<<"    P["<<sign[i]<<"]\t";

            for(int j=0;j<REC_NUM;j++){
                cout<<work[sign[i]][j]<<" ";
            }
            cout<<"\t"<<"\t";

            for(int j=0;j<REC_NUM;j++){
                cout<<Need[sign[i]][j]<<" ";
            }
            cout<<"\t"<<"\t";

            for(int j=0;j<REC_NUM;j++){
                cout<<Allocation[sign[i]][j]<<" ";
            }
            cout<<"\t"<<"\t";

            for(int j=0;j<REC_NUM;j++){
                cout<<workAll[sign[i]][j]<<" ";
            }
            cout<<"\t"<<"\t";

            cout<<"true"<<endl;
        }
        cout<<endl;
        cout<<"找到安全序列{ P["<<sign[0]<<"]";
        for(int m=1;m<PROGRESS;m++){
            cout<<" , P["<<sign[m]<<"]";
        }
        cout<<"}"<<endl;
    }

}
