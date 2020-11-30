#include <iostream>
#include "node.h" //定义作业信息结构
#include "initial_jobs.h" //初始化所有作业信息
#include "read_Jobdata.h"
#include "FCFS.h"
#include "SJF.h"
#include "HRRF.h"
#include "FPF.h"
#include "SRT.h"
using namespace std;

int main()
{
    int n;
    initial_jobs();
    read_Jobdata();
    while(1){
        cout<<"Process scheduling algorithm menu:"<<endl;
        cout<<"1    FCFS    "<<endl;
        cout<<"2    SJF     "<<endl;
        cout<<"3    HRRF    "<<endl;
        cout<<"4    FPF     "<<endl;
        cout<<"5    SRT     "<<endl;

        cout<<"0    exit     "<<endl;
        cout<<endl;
        cout<<"input number to choose:";
        cin>>n;
        cout<<endl;
        switch(n){
        case 1:
            FCFS();
            break;
        case 2:
            SJF();
            break;
        case 3:
            HRRF();
            break;
        case 4:
            FPF();
            break;
        case 5:
            SRT();
        case 0:
            exit(0);
            break;
        }
    }

    return 0;
}
