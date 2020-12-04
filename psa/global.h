#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include "node.h"

#define inf 0x3f3f3f
extern int num;     //进程数
extern int time;    //全局时间变量
//extern int totalTime;//一共的执行时间
extern job jobs[];  //作业
extern int ready[]; //就绪队列
extern int runcount;//就绪队列中进程数量
extern int order[]; //记录排序使用哪个数值作为排序对象


extern int PROGRESS;  //进程数量
extern int REC_NUM;    //资源种类数量
extern int Available[5];//可用资源向量Available
extern int sign[5];     //记录成功的安全序列
extern int work[5][3];   //工作矩阵
extern int workAll[5][3];//可用资源矩阵
extern int Max[5][3];    //最大需求矩阵
extern int Allocation[5][3];//分配矩阵
extern int Need[5][3];    //需求矩阵

//extern int Available[PROGRESS];
//extern int sign[PROGRESS];
//extern int work[PROGRESS][REC_NUM];
//extern int workAll[PROGRESS][REC_NUM];
//extern int Max[PROGRESS][REC_NUM];
//extern int Allocation[PROGRESS][REC_NUM];
//extern int Need[PROGRESS][REC_NUM];



#endif // GLOBAL_H_INCLUDED
