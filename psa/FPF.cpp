//�������Ȩ���Ƚ��̵����㷨

#include<iostream>
#include "node.h"
#include "global.h"
#include "findNextFPF.h"
#include "printResult.h"
#include "initial_jobs_again.h"
using namespace std;

void FPF()
{
    cout<<"FPF"<<endl;
    int i;
    int finish=inf; //��ǰ���ʱ��

    for(i=1;i<=num;i++){
        finish=min(finish,jobs[i].reach_time);
    }

    for(i=1;i<=num;i++){
        int index=findNextFPF(jobs,num,finish);
        if(jobs[index].reach_time<=finish){
            jobs[index].start_time=finish;
        }
        else{
            jobs[index].start_time=jobs[index].reach_time;
        }
        jobs[index].finish_time=jobs[index].start_time+jobs[index].need_time;
        jobs[index].tr_time=jobs[index].finish_time-jobs[index].reach_time;
        jobs[index].wtr_time=(double)jobs[index].tr_time/jobs[index].need_time;
        jobs[index].visited=true;
        finish=jobs[index].finish_time;
    }
    printResult();
    cout<<endl;
    initial_jobs_again();

}
