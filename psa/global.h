#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#define inf 0x3f3f3f
extern int num;     //进程数
extern int time;    //全局时间变量
extern int totalTime;//一共的执行时间
extern job jobs[];  //作业
extern int ready[]; //就绪队列
extern int runcount;//就绪队列中进程数量
extern int order[]; //记录排序使用哪个数值作为排序对象

#endif // GLOBAL_H_INCLUDED
