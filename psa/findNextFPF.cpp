//寻找高优先权进程

#include "node.h"
#include "global.h"

int findNextFPF(job jobs[100],int length,int time)
{
    //优先值越小，表示优先权越高
    int i,p,q;
    //p是已经到达且拥有最高优先权的进程的下标
    //q是没有到达的进程中拥有最早到达时间的进程的下标
    int minReachTime,minPrivilegel;
    p=q=-1;
    minPrivilegel=minReachTime=inf;

    for(i=1;i<=length;i++){
        if(!jobs[i].visited){
            //第一种情况
            if(jobs[i].reach_time<=time&&jobs[i].privilege<=minPrivilegel){
                if(jobs[i].privilege==jobs[p].privilege){   //如果优先权一样，则按最早抵达时间
                    if(jobs[i].reach_time<jobs[p].reach_time){
                        p=i;
                    }
                }
                else{
                    p=i;
                    minPrivilegel=jobs[i].privilege;
                }
            }
            //第二种情况
            else if(jobs[i].reach_time>time&&jobs[i].reach_time<=minReachTime){
                q=i;
                minReachTime=jobs[i].reach_time;
            }
        }
    }
    if(p!=-1){
        return p;
    }
    //p为-1时，代表在time时刻还没进程到达，此时选择下一个最早到达的进程q
    return q;

}
