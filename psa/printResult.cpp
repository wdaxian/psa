//�������ӡ�������в����뵽Output.txt�ļ�

#include<iostream>
#include "node.h"
#include "global.h"
using namespace std;

void printResult()
{
    cout<<"���̺�  \t����ʱ��\t����ʱ��\t��ʼʱ��\t���ʱ��\t��תʱ��\t��Ȩ��תʱ��"<<endl;
    for(int i=1;i<=num;i++){
        cout<<jobs[i].number<<"\t\t";
        cout<<jobs[i].reach_time<<"\t\t";
        cout<<jobs[i].need_time<<"\t\t";
        cout<<jobs[i].start_time<<"\t\t";
        cout<<jobs[i].finish_time<<"\t\t";
        cout<<jobs[i].tr_time<<"\t\t";
        cout<<jobs[i].wtr_time;
        cout<<endl;

    }
}

