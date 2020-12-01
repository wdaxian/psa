//定义全局变量

#include "node.h"

int num=4;
int time=0;
int totalTime=0;
job jobs[100];
int ready[100];
int runcount=0;
int order[100];

int PROGRESS=5;
int REC_NUM=3;

int Available[5];
int sign[5];
int work[5][3];
int workAll[5][3];
int Max[5][3];
int Allocation[5][3];
int Need[5][3];

//int Available[PROGRESS];
//int sign[PROGRESS];
//int work[PROGRESS][REC_NUM];
//int workAll[PROGRESS][REC_NUM];
//int Max[PROGRESS][REC_NUM];
//int Allocation[PROGRESS][REC_NUM];
//int Need[PROGRESS][REC_NUM];
