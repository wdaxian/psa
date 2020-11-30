//将结果打印到命令行并输入到Output.txt文件

#include<iostream>
#include "node.h"
#include "global.h"
using namespace std;

void printResult()
{
    cout<<"进程号  \t到达时间\t服务时间\t开始时间\t完成时间\t周转时间\t带权周转时间"<<endl;
    for(int i=1;i<=num;i++){
        cout<<jobs[i].number<<"\t\t";
        cout<<jobs[i].reach_time<<"\t\t";
        cout<<jobs[i].need_time<<"\t\t";
        cout<<jobs[i].start_time<<"\t\t";
        cout<<jobs[i].finish_time<<"\t\t";
        cout<<jobs[i].tr_time<<"\t\t";
        cout<<jobs[i].wtr_time;
        cout<<endl;

    }
}

