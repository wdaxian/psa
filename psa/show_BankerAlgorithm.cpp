//չʾ���м��㷨

#include<iostream>
#include "global.h"
#include "read_Bankfile.h"
#include "Banker_Algorithm.h"
#include "Safe_Algorithm.h"
#include "printRunOrder.h"
using namespace std;

void show_BankerAlgorithm()
{
    read_Bankfile();

    int i,n=1;
    int Request[5][3];//�����������Request

    while(n!=0){
        cout<<"������������ԴRequest[���̱��i][��Դ����]��"<<endl;
        cout<<"���� i = ";
        cin>>i;
        cout<<"������Դ����(A B C) = ";
        for(int m=0;m<REC_NUM;m++){
            cin>>Request[i][m];
        }

        //ִ�����м��㷨
        int result=Banker_Algorithm(i,Request);
        //���ÿ���жϲ�����ִ������
        cout<<endl;

        printRunOrder(result);

        cout<<endl;
        cout<<"����������n��ֵ����(��n=0�˳�)��"<<endl;
        cin>>n;
        cout<<endl;
    }


}
