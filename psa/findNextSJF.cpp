//Ѱ�Ҷ���ҵ����

#include "node.h"
#include "global.h"



int findNextSJF(job jobs[100],int length,int time)
{
    int i,p,q;  //p���Ѿ�������ӵ���������ʱ��Ľ��̵��±�
                //q��û�е���Ľ�����ӵ�����絽��ʱ��Ľ��̵��±�
    int minNeedTime,minReachTime,minTime;

    p=q=-1;
    minTime=minNeedTime=minReachTime=inf;

    for(i=1;i<=length;i++){
        if(!jobs[i].visited){
            //��һ�����
            if(jobs[i].reach_time<=time&&jobs[i].need_time<=minNeedTime){
                p=i;
                minNeedTime=jobs[i].need_time;
            }
            //�ڶ������
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
    //p=-1ʱ��������lastTimeʱ�̻�û���̵����ʱѡ����һ�����絽��Ľ���q
    return q;

}
