//读取数据文件

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

    file.open("test.txt");//打开文件
    file.getline(bf,100);//读取第一行 不输出
    while(!file.eof()){
        file>>number;//读取一个数字
        p.push_back(number);//读入数组
        //cout<<number<<endl;
    }
    //for(int i=0;i<=p.size()-1;++i){cout<<p[i]<<" ";}
    //将vector输入到jobs中
    int p_size=p.size();
    for(int i=0;i<p_size;i+=4){
        jobs[i/4+1].number=p[i];
        jobs[i/4+1].reach_time=p[i+1];
        jobs[i/4+1].need_time=p[i+2];
        jobs[i/4+1].privilege=p[i+3];
        //cout<<p[i];
    }
    //cout<<endl;
    //cout<<jobs[2].number;


}
