#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

//������ҵ��Ϣ�ṹ

typedef struct node{
    int number;         //��ҵ��

    int reach_time;     //��ҵ�ִ�ʱ��

    int need_time;      //��ҵ��ִ��ʱ��

    int privilege;      //��ҵ����Ȩ

    float excellent;    //��Ӧ��

    int start_time;     //��ҵ��ʼʱ��

    int wait_time;      //�ȴ�ʱ��

    int tr_time;        //��תʱ��

    double wtr_time;    //��Ȩ��תʱ��

    int run_time;       //��ҵ�ۼ���ִ��ʱ��

    bool visited;       //��ҵ�Ƿ񱻷��ʹ�

    int finish_time;    //��ҵ���ʱ��

    bool reached;       //��ҵ�ִ�ʱ��

    int residual_time;  //ʣ�����ʱ��

}job;



#endif // NODE_H_INCLUDED
