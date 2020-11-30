//ΩÁ√Êœ‘ æ

#include <iostream>
#include "node.h"
#include "global.h"
#include "FCFS.h"
#include "SJF.h"
#include "HRRF.h"
#include "FPF.h"
#include "SRT.h"
#include "LLF.h"
#include "Banker_Algorithm.h"
using namespace std;

void Show()
{
    int n;
    while(1){
        cout<<"Process scheduling algorithm menu:"<<endl;
        cout<<"1    FCFS    "<<endl;
        cout<<"2    SJF     "<<endl;
        cout<<"3    HRRF    "<<endl;
        cout<<"4    FPF     "<<endl;
        cout<<"5    SRT     "<<endl;
        cout<<"6    LLF     "<<endl;
        cout<<"7    Banker's Algorithm      "<<endl;
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
            break;
        case 6:
            LLF();
            break;
        case 7:
            Banker_Algorithm();
            break;
        case 0:
            exit(0);
            break;
        }
    }

}
