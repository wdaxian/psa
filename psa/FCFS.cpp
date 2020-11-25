//先来先服务进程调度算法

#include<iostream>
#include<algorithm>
#include "node.h"
#include "global.h"
#include "initial_jobs_again.h"
using namespace std;

void FCFS()
{
    int i=0;

    for(i=1;i<num;i++){
        order[i]=jobs[i].reach_time;
        ready[i]=i;
    }

    sort(order,order+num);
    sort(ready,ready+num);

    for(i=1;i<=num;i++){
        cout<<ready[i]<<"job work is running"<<endl;
        cout<<"arrival time: "<<jobs[ready[i]].reach_time<<endl;
        cout<<"service time: "<<jobs[ready[i]].need_time<<endl;


        if(i==1){
            jobs[ready[i]].finish_time=jobs[ready[i]].reach_time+jobs[ready[i]].need_time;
            jobs[ready[i]].wait_time=0;
        }
        else{
            //如果上一个作业的完成时间大于下一个作业的到达时间，则下一个作业的开始时间从上一个作业的完成时间开始
            if(jobs[ready[i-1]].finish_time>jobs[ready[i]].reach_time){
                jobs[ready[i]].finish_time=jobs[ready[i-1]].finish_time+jobs[ready[i]].need_time;
                jobs[ready[i]].wait_time=jobs[ready[i-1]].finish_time-jobs[ready[i]].reach_time;
            }
            else{
                jobs[ready[i]].finish_time=jobs[ready[i]].reach_time+jobs[ready[i]].need_time;
                jobs[ready[i]].wait_time=0;
            }

        }

        jobs[ready[i]].tr_time=jobs[ready[i]].finish_time-jobs[ready[i]].reach_time;
        jobs[ready[i]].wtr_time=double(jobs[ready[i]].tr_time)/jobs[ready[i]].need_time;
        cout<<"waiting time: "<<jobs[ready[i]].wait_time<<endl;
        cout<<"turnaround time: "<<jobs[ready[i]].tr_time<<endl;
        cout<<"weighted turnaround time: "<<jobs[ready[i]].wtr_time<<endl;

        cout<<"finished running"<<endl;
        cout<<"----------------"<<endl;

    }
    cout<<"-----All jobs are scheduled-----"<<endl;
    initial_jobs_again();

}
