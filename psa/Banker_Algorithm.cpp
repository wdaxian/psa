//���м��㷨

#include<iostream>
#include "global.h"
#include "Safe_Algorithm.h"
using namespace std;

int Banker_Algorithm(int i,int Request[5][3])
{
    for(int m=0;m<REC_NUM;m++){
        if(Request[i][m]>Need[i][m]){
            cout<<"������Դ�����������������ֵ��"<<endl;
        }
        else if(Request[i][m]>Available[m]){
            cout<<"���㹻��Դ��P["<<i<<"]��ȴ���"<<endl;
        }
    }

    //����Ϊ���̷�����Դ
    for(int j=0;j<REC_NUM;j++){
        Available[j]=Available[j]-Request[i][j];
        Allocation[i][j]=Allocation[i][j]+Request[i][j];
        Need[i][j]=Need[i][j]-Request[i][j];
    }

    //ִ�а�ȫ���㷨
    int n=Safe_Algorithm(Available,Need,Allocation);
    cout<<endl;
    if(n==PROGRESS){//��5��'true'����1����ʾ��ʱ�̰�ȫ
        cout<<"��ʱ���ǰ�ȫ״̬�����Է�����Դ��P["<<i<<"]"<<endl;
    }
    else{
        cout<<"��ʱ�̲��ǰ�ȫ״̬�����ɷ�����Դ"<<endl;
    }

    return n;

}
