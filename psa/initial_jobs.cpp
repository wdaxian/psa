//初始化所有作业信息

#include "node.h"
#include "global.h"

void initial_jobs()
{

    for(int i=1;i<=num;i++){

        jobs[i].excellent=0;
        jobs[i].finish_time=0;
        jobs[i].need_time=0;
        jobs[i].number=0;
        jobs[i].privilege=0;
        jobs[i].reached=false;
        jobs[i].reach_time=0;
        jobs[i].run_time=0;
        jobs[i].start_time=0;
        jobs[i].tr_time=0;
        jobs[i].visited=false;
        jobs[i].wait_time=0;
        jobs[i].wtr_time=0;
        jobs[i].residual_time=0;

        totalTime+=jobs[i].need_time;
    }


}

