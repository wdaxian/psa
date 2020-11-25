//读取数据文件

#include<fstream>
#include<iostream>
#include "node.h"
#include "global.h"
#include "initial_jobs.h"
using namespace std;

void read_Jobdata()
{

    FILE *f;
    f=fopen("./test.txt","r");
    if(f==NULL){
        cout<<"fail to open the file"<<endl;
        exit(0);
    }
    char buffer[100];
    cout<<"start reading ..."<<endl;
    //fgets(buffer,MAX_LINE,f);
                            /*char *fgets (char *string,int size,FILE *stream)
                            * string 为一个字符数组，用来保存读取到的字符
                            * size 为要读取的字符的个数
                            * stream 为文件流指针*/
    num=0;
    num++;

//    while(!feof(f)){
//                    /*int feof(FILE *stream)
//                    * 测试给定流stream的文件结束标识符*/
//        cout<<jobs[num].number<<" "<<jobs[num].reach_time<<" "<<jobs[num].need_time<<" "<<jobs[num].privilege<<endl;
//        num++;
//    }
//    num--;

    cout<<"read data success!"<<endl;
    cout<<"the number of jobs is:"<<num<<endl;
    for(int j=1;j<=num;j++){
        cout<<jobs[j].number<<"\t"<<jobs[j].reach_time<<"\t"<<jobs[j].need_time<<"\t"<<jobs[j].privilege<<endl;
    }
    fclose(f);

}
