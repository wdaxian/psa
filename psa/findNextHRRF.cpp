//Ѱ�Ҹ���Ӧ�Ƚ���

#include "node.h"
#include "global.h"

int findNextHRRF(int pre)
{
    //����Ȩ=���ȴ�ʱ��+Ҫ�����ʱ�䣩/Ҫ�����ʱ��
    int current=1,i,j;

    for(i=1;i<=num;i++){
        if(!jobs[i].visited){
            jobs[i].wait_time=jobs[pre].finish_time-jobs[i].reach_time; //�ȴ�ʱ��=��һ�����̵����ʱ��-����ʱ��
            jobs[i].excellent=(float)(jobs[i].wait_time+jobs[i].need_time)/jobs[i].need_time;

        }
    }

    for(i=1;i<=num;i++){
        if(!jobs[i].visited){
            current=i;      //�ҵ���һ����û��ɵ���ҵ
            break;
        }
    }

    for(j=i;j<=num;j++){    //�ͺ������ҵ�Ƚ�
        if(!jobs[i].visited){
            if(jobs[current].reach_time<jobs[pre].finish_time){ //�����������һ���������֮ǰ����
                if(jobs[j].excellent>jobs[current].excellent){
                    current=j;  //�ҳ�����ʱ������һ���������֮ǰ������Ȩ�ߵĽ���
                }
            }
            else{   //�������������һ���������֮�󵽴�
                if(jobs[j].reach_time<jobs[current].reach_time){
                    current=j;  //�ҳ��Ƚ��絽���һ��
                }
                else if(jobs[j].reach_time==jobs[current].reach_time&&
                        jobs[j].excellent>jobs[current].excellent)  //���ͬʱ����ҳ���Ӧ�ȸߵ�
                    current=j;
            }
        }
    }

    return current;
}
