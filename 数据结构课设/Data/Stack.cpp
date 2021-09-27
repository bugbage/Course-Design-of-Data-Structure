#include"BaseDefine.h"
Status InitStack_Sq(SqStack& S)
{
    S.base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (!S.base)return ERROR;
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status Push_Sq(SqStack& S, ElemType& e)
{
    //�ж�ջ�Ƿ���
    if (S.top - S.base >= S.stacksize)//���ӷ���ռ�
    {
        ElemType* newbase;
        newbase = (ElemType*)realloc(S.base, (STACK_INIT_SIZE + STACKINCREMNET) * sizeof(ElemType));
        if (!newbase)exit(OVERFLOW);
        S.base = newbase;
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMNET;
    }
    *S.top++ = e;
    return OK;
}

Status GetTop_Sq(SqStack& S, ElemType& e)
{
    //�ж�ջ�Ƿ�Ϊ��
    if (S.top == S.base)return ERROR;
    e = *(S.top - 1);
    return e;
}

Status Pop_Sq(SqStack& S, ElemType& e)
{
    //�ж�ջ�Ƿ�Ϊ��
    if (S.top == S.base)return ERROR;
    e = *--S.top;
    return OK;
}