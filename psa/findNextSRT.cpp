//寻找最短剩余时间作业

#include "node.h"
#include "global.h"

void findNextSRT()
{
    //将当前time时刻到达的进程加入就绪队列
    for(int i=1;i<=num;i++){
        if(jobs[i].reach_time==time)
        {
            ready[runcount+1]=i;
            runcount++;
        }
    }

}
