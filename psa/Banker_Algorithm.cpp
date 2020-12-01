//银行家算法

#include<iostream>
#include "global.h"
#include "Safe_Algorithm.h"
using namespace std;

int Banker_Algorithm(int i,int Request[5][3])
{
    for(int m=0;m<REC_NUM;m++){
        if(Request[i][m]>Need[i][m]){
            cout<<"所需资源数超出其宣布的最大值！"<<endl;
        }
        else if(Request[i][m]>Available[m]){
            cout<<"无足够资源，P["<<i<<"]需等待！"<<endl;
        }
    }

    //尝试为进程分配资源
    for(int j=0;j<REC_NUM;j++){
        Available[j]=Available[j]-Request[i][j];
        Allocation[i][j]=Allocation[i][j]+Request[i][j];
        Need[i][j]=Need[i][j]-Request[i][j];
    }

    //执行安全性算法
    int n=Safe_Algorithm(Available,Need,Allocation);
    cout<<endl;
    if(n==PROGRESS){//有5个'true'返回1，表示此时刻安全
        cout<<"此时刻是安全状态，可以分配资源给P["<<i<<"]"<<endl;
    }
    else{
        cout<<"此时刻不是安全状态，不可分配资源"<<endl;
    }

    return n;

}
