//高响应比优先进程调度算法

#include<iostream>
#include "node.h"
#include "global.h"
#include "findNextHRRF.h"
#include "initial_jobs_again.h"
using namespace std;

void HRRF()
{
    cout<<"HRRF"<<endl;
    int i;
    int pre=1;
    jobs[1].finish_time=0;

    for(i=1;i<=num;i++){
        int index=findNextHRRF(pre);
        cout<<index<<"job work is running"<<endl;
        cout<<"arrival time: "<<jobs[index].reach_time<<endl;
        cout<<"service time: "<<jobs[index].need_time<<endl;

        if(i==1){
            jobs[index].start_time=jobs[index].reach_time;
            jobs[index].finish_time=jobs[index].start_time+jobs[index].need_time;
            jobs[index].tr_time=jobs[index].need_time;
            jobs[index].wtr_time=1.00;
            jobs[index].wait_time=0;
        }
        else{
            if(jobs[index].reach_time>jobs[pre].finish_time){
                jobs[index].wait_time=0;
                jobs[index].start_time=jobs[index].reach_time;
            }
            else{
                jobs[index].start_time=jobs[pre].finish_time;
                jobs[index].wait_time=jobs[pre].finish_time-jobs[index].reach_time;
            }
            jobs[index].finish_time=jobs[index].start_time+jobs[index].need_time;
            jobs[index].tr_time=jobs[index].finish_time-jobs[index].reach_time;
            jobs[index].wtr_time=(double)jobs[index].tr_time/jobs[index].need_time;
        }
        jobs[index].visited=true;
        pre=index;
        cout<<"waiting time: "<<jobs[index].wait_time<<endl;
        cout<<"turnaround time: "<<jobs[index].tr_time<<endl;
        cout<<"weighted turnaround time: "<<jobs[index].wtr_time<<endl;

        cout<<"finished running"<<endl;
        cout<<"----------------"<<endl;
    }
    cout<<"-----All jobs are scheduled-----"<<endl;
    cout<<endl;
    initial_jobs_again();
}
