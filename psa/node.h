#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

//定义作业信息结构

typedef struct node{
    int number;         //作业号

    int reach_time;     //作业抵达时间

    int need_time;      //作业的执行时间

    int privilege;      //作业优先权

    float excellent;    //响应比

    int start_time;     //作业开始时间

    int wait_time;      //等待时间

    int tr_time;        //周转时间

    double wtr_time;    //带权周转时间

    int run_time;       //作业累计已执行时间

    bool visited;       //作业是否被访问过

    int finish_time;    //作业完成时间

    bool reached;       //作业抵达时间

}job;



#endif // NODE_H_INCLUDED
