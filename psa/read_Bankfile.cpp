//��ȡ�ļ����ݴ�ӡ��Ȼ�����ݴ��뵽��Ӧ������

#include<iostream>
#include<fstream>
#include "global.h"
using namespace std;

void read_Bankfile()
{
    //��ȡ�����ļ�����ӡ
    ifstream inFile1("Alldata.txt",ios::in);//�����ļ�������
    if(!inFile1){//�ж϶���inFile1���ļ��ɹ����
        cerr<<"File open error!"<<endl;     //ʹ�ô������������������Ϣ
    }
    else{
        char c;
        while((c=inFile1.get())!=EOF){      //���ַ���ȡ�ļ����ݣ�����ĩβֹͣ
                                            //EOF���ж��Ƿ񵽴��ļ�ĩβ
            cout<<c;
        }
        cout<<endl;
        inFile1.close();
    }

    //��ȡֻ�����ֵ��ļ������������
    ifstream inFile2("data.txt",ios::in);
    if(!inFile2){
        cerr<<"File open error!"<<endl;
    }
    else{
        int data;
        //��ȡ���ֲ��������
        for(int j=0;j<PROGRESS;j++){
            for(int i=0;i<REC_NUM;i++){
                inFile2>>data;
                Max[j][i]=data;
            }
            for(int i=0;i<REC_NUM;i++){
                inFile2>>data;
                Allocation[j][i]=data;
            }
            for(int i=0;i<REC_NUM;i++){
                inFile2>>data;
                Need[j][i]=data;
            }
            if(j==0){
                for(int i=0;i<REC_NUM;i++){
                    inFile2>>data;
                    Available[i]=data;
                }
            }
        }
        inFile2.close();
    }
}
