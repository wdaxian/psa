//最短剩余时间优先算法
#include<iostream>
#include<algorithm>
#include "node.h"
#include "global.h"
#include "printResult.h"
#include "initial_jobs_again.h"
using namespace std;

int runhead[5]; //就绪队列

void move()
{
    for(int i=1;i<=num;i++)
	{
		if(jobs[i].need_time==time)
		{
			runhead[runcount]=i;
			runcount++;
		}
	}
}


void SRTF(){
    cout<<"STRF"<<endl;

    int TOTALTIME=0;
    int time=0;//记录当前时间
    int runcount=0; //就绪队列中进程数量
    int minRt;//就绪序列中最短剩余时间进程的剩余时间
    int index;
    for(int j=1;j<=num;j++)
	{

		TOTALTIME+=jobs[j].need_time;
	}
    while(time<=TOTALTIME)
	{
		move();
	    if(runcount==0)    //就绪队列中没有进程
			time++;
		else
		{
			for(int j=1;j<=runcount;j++)//找出就绪队列中进程剩余时间为0，则将其移出就绪队列，并记录其完成时间等相关信息
			{
				 if(jobs[runhead[j]].rt==0)
				 {
					jobs[runhead[j]].endTime=time;
					jobs[runhead[j]].need_time=time-jobs[runhead[j]].reach_time;
					jobs[runhead[j]].excellent=(float)jobs[runhead[j]].tr_time/jobs[runhead[j]].need_time;
					jobs[runhead[j]].visited=true;
					for(int i=j;i<runcount-1;i++)
					{
						runhead[i]=runhead[i+1];
					}
					runcount--;
				 }
			}
			minRt=jobs[runhead[1]].rt;
			index=runhead[1];
			for(int i=2;i<=runcount;i++)//找出就绪队列中的最短剩余时间的进程
			 {
				 if(jobs[runhead[i]].rt<minRt)
				 {
						 minRt=jobs[runhead[i]].rt;
						 index=runhead[i];
				 }
			}
		    if(jobs[index].rt==jobs[index].need_time)
		        jobs[index].start_time=time;
			time++;
			jobs[index].rt--;
		}
	}



    printResult();
    cout<<endl;
    initial_jobs_again();
}
