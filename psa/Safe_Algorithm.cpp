//��ȫ���㷨

#include "global.h"

int Safe_Algorithm(int Available[5],int Need[5][3],int Allocation[5][3])
{
    int i=0,j=0,m=0,n=0;
    int Work[REC_NUM];
    int Finish[PROGRESS]={0,0,0,0,0};
    for(int r=0;r<REC_NUM;r++){//��������Դ��Ŀ������������Work
        Work[r]=Available[r];
    }
    while(i<PROGRESS){
        if(Finish[i]==0){//���������ͷ���Դ������ͷ��ʼɨ����̼���
            while(j<REC_NUM&&Need[i][j]<=Work[j]){
                j++;
            }
            if(j==REC_NUM){
                for(int k=0;k<REC_NUM;k++){
                    work[i][k]=Work[k];
                    Work[k]=Work[k]+Allocation[i][k];
                    workAll[i][k]=Work[k];
                }
                Finish[i]=1;
                sign[m]=i;//���氲ȫ����
                i=-1;
                m++;
            }
        }
        j=0;
        i++;
    }

    for(int p=0;p<PROGRESS;p++){
        if(Finish[p]==1){
            n++;    //��¼'true'����
        }
    }

    return n;   //����'true'����

}
