#include <iostream>
#include "node.h" //������ҵ��Ϣ�ṹ
#include "initial_jobs.h" //��ʼ��������ҵ��Ϣ
#include "read_Jobdata.h"
#include "FCFS.h"
#include "SJF.h"
#include "HRRF.h"
using namespace std;

int main()
{
    initial_jobs();
    read_Jobdata();
    FCFS();
    SJF();
    HRRF();
    return 0;
}
