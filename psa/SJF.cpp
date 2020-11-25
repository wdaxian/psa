//短作业优先进程调度算法

#include<iostream>
#include<algorithm>
#include "node.h"
#include "global.h"
#include "findNextSJF.h"
#include "initial_jobs_again.h"
using namespace std;
//你就这
void SJF()
{
    int i,j;
    int finish=inf; //完成时间
    for(i=1;i<=num;i++){
        finish=min(finish,jobs[i].reach_time);
    }

    for(i=1;i<=num;i++){
        int index=findNextSJF(jobs,num,finish);
        cout<<index<<"job work is running"<<endl;
        cout<<"arrival time: "<<jobs[index].reach_time<<endl;
        cout<<"service time: "<<jobs[index].need_time<<endl;

        if(jobs[index].reach_time<=finish){
            jobs[index].wait_time=finish-jobs[index].reach_time;
            jobs[index].start_time=finish;
        }
        else{
            jobs[index].start_time=jobs[index].reach_time;
            jobs[index].wait_time=0;
        }
        jobs[index].finish_time=jobs[index].start_time+jobs[index].need_time;
        jobs[index].tr_time=jobs[index].finish_time-jobs[index].reach_time;
        jobs[index].wtr_time=(double)jobs[index].tr_time/jobs[index].need_time;
        jobs[index].visited=true;
        finish=jobs[index].finish_time;
        cout<<"waiting time: "<<jobs[index].wait_time<<endl;
        cout<<"turnaround time: "<<jobs[index].tr_time<<endl;
        cout<<"weighted turnaround time: "<<jobs[index].wtr_time<<endl;

        cout<<"finished running"<<endl;
        cout<<"----------------"<<endl;
    }
    cout<<"-----All jobs are scheduled-----"<<endl;
    initial_jobs_again();


}
