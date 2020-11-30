//�����ȷ�����̵����㷨

#include<iostream>
#include<algorithm>
#include "node.h"
#include "global.h"
#include "printResult.h"
#include "initial_jobs_again.h"
using namespace std;

void FCFS()
{
    cout<<"FCFS"<<endl;
    int i;

    for(i=1;i<=num;i++){
        order[i]=jobs[i].reach_time;
        ready[i]=i;
    }

    sort(order,order+num);
    sort(ready,ready+num);

    for(i=1;i<=num;i++){
        if(i==1){
            jobs[ready[i]].finish_time=jobs[ready[i]].reach_time+jobs[ready[i]].need_time;
        }
        else{
            //�����һ����ҵ�����ʱ�������һ����ҵ�ĵ���ʱ�䣬����һ����ҵ�Ŀ�ʼʱ�����һ����ҵ�����ʱ�俪ʼ
            if(jobs[ready[i-1]].finish_time>jobs[ready[i]].reach_time){
                jobs[ready[i]].start_time=jobs[ready[i-1]].finish_time;
                jobs[ready[i]].finish_time=jobs[ready[i-1]].finish_time+jobs[ready[i]].need_time;
            }
            else{
                jobs[ready[i]].finish_time=jobs[ready[i]].reach_time+jobs[ready[i]].need_time;
            }

        }
        jobs[ready[i]].tr_time=jobs[ready[i]].finish_time-jobs[ready[i]].reach_time;
        jobs[ready[i]].wtr_time=double(jobs[ready[i]].tr_time)/jobs[ready[i]].need_time;

    }
    printResult();
    cout<<endl;
    initial_jobs_again();

}
