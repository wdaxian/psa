//寻找高响应比进程

#include "node.h"
#include "global.h"

int findNextHRRF(int pre)
{
    //优先权=（等待时间+要求服务时间）/要求服务时间
    int current=1,i,j;

    for(i=1;i<=num;i++){
        if(!jobs[i].visited){
            jobs[i].wait_time=jobs[pre].finish_time-jobs[i].reach_time; //等待时间=上一个进程的完成时间-到达时间
            jobs[i].excellent=(float)(jobs[i].wait_time+jobs[i].need_time)/jobs[i].need_time;

        }
    }

    for(i=1;i<=num;i++){
        if(!jobs[i].visited){
            current=i;      //找到第一个还没完成的作业
            break;
        }
    }

    for(j=i;j<=num;j++){    //和后面的作业比较
        if(!jobs[i].visited){
            if(jobs[current].reach_time<jobs[pre].finish_time){ //如果进程在上一个进程完成之前到达
                if(jobs[j].excellent>jobs[current].excellent){
                    current=j;  //找出到达时间在上一个进程完成之前，优先权高的进程
                }
            }
            else{   //如果进程是在上一个进程完成之后到达
                if(jobs[j].reach_time<jobs[current].reach_time){
                    current=j;  //找出比较早到达的一个
                }
                else if(jobs[j].reach_time==jobs[current].reach_time&&
                        jobs[j].excellent>jobs[current].excellent)  //如果同时到达，找出响应比高的
                    current=j;
            }
        }
    }

    return current;
}
