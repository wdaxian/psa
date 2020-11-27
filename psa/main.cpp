#include <iostream>
#include "node.h" //定义作业信息结构
#include "initial_jobs.h" //初始化所有作业信息
#include "read_Jobdata.h"
#include "FCFS.h"
#include "SJF.h"
using namespace std;

int main()
{
    initial_jobs();
    read_Jobdata();
    FCFS();
    SJF();
    return 0;
}
