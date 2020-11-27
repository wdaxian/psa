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
    int n;
    initial_jobs();
    read_Jobdata();
    while(1){
        cout<<"process scheduling algorithm menu:"<<endl;
        cout<<"1    FCFS    "<<endl;
        cout<<"2    SJF     "<<endl;
        cout<<"3    HRRF    "<<endl;



        cout<<"7    exit     "<<endl;
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
        case 7:
            exit(0);
            break;
        }
    }

    return 0;
}
