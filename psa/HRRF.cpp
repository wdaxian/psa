//高响应比优先进程调度算法

#include<iostream>
#include "node.h"
#include "global.h"
#include "findNextHRRF.h"
#include "printResult.h"
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
        if(i==1){
            jobs[index].start_time=jobs[index].reach_time;
            jobs[index].finish_time=jobs[index].start_time+jobs[index].need_time;
            jobs[index].tr_time=jobs[index].need_time;
            jobs[index].wtr_time=1.00;
        }
        else{
            if(jobs[index].reach_time>jobs[pre].finish_time){
                jobs[index].start_time=jobs[index].reach_time;
            }
            else{
                jobs[index].start_time=jobs[pre].finish_time;
            }
            jobs[index].finish_time=jobs[index].start_time+jobs[index].need_time;
            jobs[index].tr_time=jobs[index].finish_time-jobs[index].reach_time;
            jobs[index].wtr_time=(double)jobs[index].tr_time/jobs[index].need_time;
        }
        jobs[index].visited=true;
        pre=index;
    }
    printResult();
    cout<<endl;
    initial_jobs_again();
}
