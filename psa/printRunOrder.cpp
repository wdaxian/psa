//��ӡ��ȫ�Լ��ִ������

#include<iostream>
#include "global.h"
using namespace std;

void printRunOrder(int result)
{
    if(result==PROGRESS){
        cout<<"��Դ�����"<<endl;
        cout<<" process\\Resources"<<" Work(A B C)"<<"Need(A B C)"
            <<"Allocation(A B C)"<<"Work+Allocation(A B C)"<<"Finish"<<endl;

        for(int i=0;i<PROGRESS;i++){
            cout<<"    P["<<sign[i]<<"]\t";

            for(int j=0;j<REC_NUM;j++){
                cout<<work[sign[i]][j]<<" ";
            }
            cout<<"\t"<<"\t";

            for(int j=0;j<REC_NUM;j++){
                cout<<Need[sign[i]][j]<<" ";
            }
            cout<<"\t"<<"\t";

            for(int j=0;j<REC_NUM;j++){
                cout<<Allocation[sign[i]][j]<<" ";
            }
            cout<<"\t"<<"\t";

            for(int j=0;j<REC_NUM;j++){
                cout<<workAll[sign[i]][j]<<" ";
            }
            cout<<"\t"<<"\t";

            cout<<"true"<<endl;
        }
        cout<<endl;
        cout<<"�ҵ���ȫ����{ P["<<sign[0]<<"]";
        for(int m=1;m<PROGRESS;m++){
            cout<<" , P["<<sign[m]<<"]";
        }
        cout<<"}"<<endl;
    }

}
