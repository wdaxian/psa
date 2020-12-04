//最短剩余时间优先进程调度算法

#include<iostream>
#include "node.h"
#include "global.h"
#include "findNextSRT.h"
#include "printResult.h"
#include "initial_jobs_again.h";
using namespace std;

void SRT()
{
    cout<<"SRT"<<endl;

    int totalTime;
    time=0;//记录当前时间
    runcount=0;
    int i,j;

    for(int i=1;i<=num;i++){
        totalTime+=jobs[i].need_time;
    }



    for(i=0;i<num;i++){
        ready[i]=i+1;
    }

    int minRemainTime;//记录就绪队列中最短剩余时间进程的剩余时间
    int index;//记录就绪队列中最短剩余时间进程的下标

    while(time<=totalTime){
        findNextSRT(time);
        if(runcount==0){//就绪队列中没有进程
            time++;
        }
        else{
            for(i=1;i<=runcount;i++){
                //找出就绪队列中进程剩余时间为0，则将其移出就绪队列，并记录其完成时间等相关信息
                if(jobs[ready[i]].residual_time==0){
                    jobs[ready[i]].finish_time=time;
                    jobs[ready[i]].tr_time=time-jobs[ready[i]].reach_time;

                    for(j=i;j<runcount-1;j++){
                        ready[j]=ready[j+1];
                    }

                    runcount--;
                }
            }

            minRemainTime=jobs[ready[1]].residual_time;
            index=ready[1];

            for(i=1;i<runcount;i++){//找出就绪队列中的最短剩余时间的进程
                if(jobs[ready[i]].residual_time<minRemainTime){
                    minRemainTime=jobs[ready[i]].residual_time;
                    index=ready[i];
                }
            }

            if(jobs[index].residual_time==jobs[index].need_time){
                jobs[index].start_time=time;
            }

            time++;
            jobs[index].residual_time--;



        }
    }

    printResult();
    initial_jobs_again();
    cout<<endl;

}
