//展示银行家算法

#include<iostream>
#include "global.h"
#include "read_Bankfile.h"
#include "Banker_Algorithm.h"
#include "Safe_Algorithm.h"
#include "printRunOrder.h"
using namespace std;

void show_BankerAlgorithm()
{
    read_Bankfile();

    int i,n=1;
    int Request[5][3];//定义请求矩阵Request

    while(n!=0){
        cout<<"请输入请求资源Request[进程标号i][资源类型]："<<endl;
        cout<<"进程 i = ";
        cin>>i;
        cout<<"各类资源数量(A B C) = ";
        for(int m=0;m<REC_NUM;m++){
            cin>>Request[i][m];
        }

        //执行银行家算法
        int result=Banker_Algorithm(i,Request);
        //输出每次判断产生的执行序列
        cout<<endl;

        printRunOrder(result);

        cout<<endl;
        cout<<"请输入任意n的值继续(当n=0退出)："<<endl;
        cin>>n;
        cout<<endl;
    }


}
