//寻找短作业进程

#include "node.h"
#include "global.h"

#define inf 0x3f3f3f

int findNextSJF(job j[100],int length,int time)
{
    int i,p,q;  //p是已经到达且拥有最短运行时间的进程的下标
                //q是没有到达的进程中拥有最早到达时间的进程的下标
    int minNeedTime,minReachTime,minTime;

    p=q=-1;
    minTime=minNeedTime=minReachTime=inf;

    for(i=1;i<length;i++){
        if(!j[i].visited){
            //
        }
    }

}
