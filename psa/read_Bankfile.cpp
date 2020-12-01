//读取文件数据打印，然后将数据存入到相应矩阵中

#include<iostream>
#include<fstream>
#include "global.h"
using namespace std;

void read_Bankfile()
{
    //读取完整文件并打印
    ifstream inFile1("Alldata.txt",ios::in);//创建文件流对象
    if(!inFile1){//判断对象inFile1打开文件成功与否
        cerr<<"File open error!"<<endl;     //使用错误流对象输出错误信息
    }
    else{
        char c;
        while((c=inFile1.get())!=EOF){      //按字符读取文件内容，到达末尾停止
                                            //EOF，判断是否到达文件末尾
            cout<<c;
        }
        cout<<endl;
        inFile1.close();
    }

    //读取只有数字的文件并存入矩阵中
    ifstream inFile2("data.txt",ios::in);
    if(!inFile2){
        cerr<<"File open error!"<<endl;
    }
    else{
        int data;
        //读取数字并存入矩阵
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
