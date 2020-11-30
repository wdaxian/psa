#include <iostream>
#include "Show.h"
#include "initial_jobs.h"
#include "read_Jobdata.h"
using namespace std;

int main()
{
    initial_jobs();
    read_Jobdata();
    Show();

    return 0;
}
