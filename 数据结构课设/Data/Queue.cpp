#include"BaseDefine.h"
Status InitQueue_Sq(SqQueue& Q)
{
    Q.base = (ElemType*)malloc(MAXQSIZE * sizeof(SqQueue));
    Q.front = Q.rear = 0;
    return OK;
}

Status EnQueue_Sq(SqQueue& Q, ElemType e)
{
    //判断队列是否满
    if ((Q.rear + 1) % MAXQSIZE == Q.front)return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
    return OK;
}

Status DeQueue_Sq(SqQueue& Q, ElemType& e)
{
    //判断队列是否为空
    if (Q.front == Q.rear)return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return OK;
}

Status GetTopElem(SqQueue& Q, ElemType& e)
{
    e = Q.base[Q.front];
    return OK;

}

Status GetRearElem(SqQueue& Q, ElemType& e)
{
    e = Q.base[Q.rear - 1];
    return OK;
}

Status QueueLength_Sq(SqQueue*& Q)
{
    return (Q->rear - Q->front) % MAXQSIZE;
}

Status DisplayQueue_Sq(SqQueue Q)
{
    ElemType e;
    while (Q.front != Q.rear)
    {
        DeQueue_Sq(Q, e);
        cout << "  " << e;
    }
    return OK;
}
Status QueueEmpty_Sq(SqQueue& Q)
{
    if (Q.front == Q.rear)
        return 1;
    else return 0;
}