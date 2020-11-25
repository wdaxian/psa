//寻找短作业进程

#include "node.h"
#include "global.h"



int findNextSJF(job jobs[100],int length,int time)
{
    int i,p,q;  //p是已经到达且拥有最短运行时间的进程的下标
                //q是没有到达的进程中拥有最早到达时间的进程的下标
    int minNeedTime,minReachTime,minTime;

    p=q=-1;
    minTime=minNeedTime=minReachTime=inf;

    for(i=1;i<length;i++){
        if(!jobs[i].visited){
            //第一种情况
            if(jobs[i].reach_time<=time&&jobs[i].need_time<=minNeedTime){
                p=i;
                minNeedTime=jobs[i].need_time;
            }
            //第二种情况
            else if(jobs[i].reach_time>time&&jobs[i].reach_time<=minReachTime){
                if(jobs[i].need_time<minTime){
                    q=i;
                    minReachTime=jobs[i].reach_time;
                    minTime=jobs[i].need_time;
                }
            }
        }
    }
    if(p!=-1){
        return p;
    }
    //p=-1时，代表在lastTime时刻还没进程到达，此时选择下一个最早到达的进程q
    return q;

}
