//Ѱ�Ҹ�����Ȩ����

#include "node.h"
#include "global.h"

int findNextFPF(job jobs[100],int length,int time)
{
    //����ֵԽС����ʾ����ȨԽ��
    int i,p,q;
    //p���Ѿ�������ӵ���������Ȩ�Ľ��̵��±�
    //q��û�е���Ľ�����ӵ�����絽��ʱ��Ľ��̵��±�
    int minReachTime,minPrivilegel;
    p=q=-1;
    minPrivilegel=minReachTime=inf;

    for(i=1;i<=length;i++){
        if(!jobs[i].visited){
            //��һ�����
            if(jobs[i].reach_time<=time&&jobs[i].privilege<=minPrivilegel){
                if(jobs[i].privilege==jobs[p].privilege){   //�������Ȩһ����������ִ�ʱ��
                    if(jobs[i].reach_time<jobs[p].reach_time){
                        p=i;
                    }
                }
                else{
                    p=i;
                    minPrivilegel=jobs[i].privilege;
                }
            }
            //�ڶ������
            else if(jobs[i].reach_time>time&&jobs[i].reach_time<=minReachTime){
                q=i;
                minReachTime=jobs[i].reach_time;
            }
        }
    }
    if(p!=-1){
        return p;
    }
    //pΪ-1ʱ��������timeʱ�̻�û���̵����ʱѡ����һ�����絽��Ľ���q
    return q;

}
