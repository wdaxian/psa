//��ȡ�����ļ�

#include<fstream>
#include<iostream>
#include<fstream>
#include<vector>
#include "node.h"
#include "global.h"
#include "initial_jobs.h"
using namespace std;

void read_Jobdata()
{

    ifstream file;
    vector<int> p;//
    int number;
    char bf[100];

    file.open("test.txt");//���ļ�
    file.getline(bf,100);//��ȡ��һ�� �����
    while(!file.eof()){
        file>>number;//��ȡһ������
        p.push_back(number);//��������
        //cout<<number<<endl;
    }
    //for(int i=0;i<=p.size()-1;++i){cout<<p[i]<<" ";}
    //��vector���뵽jobs��
    int p_size=p.size();
    for(int i=0;i<p_size;i+=4){
        jobs[i/4+1].number=p[i];
        jobs[i/4+1].reach_time=p[i+1];
        jobs[i/4+1].need_time=p[i+2];
        jobs[i/4+1].privilege=p[i+3];
        //cout<<p[i];
    }




}
