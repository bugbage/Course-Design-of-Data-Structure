#pragma once

#include <stdio.h>

#define SIZE      1024

typedef struct     //��ʾһ�����ӵ�λ����Ϣ
{
    int x;     //������
    int y;     //������
    int pre;   //ǰһ���������ڶ��������ŵ�λ�ã��±꣩
} Box;

//˳����д��·������Ϣ
typedef struct
{
    Box data[SIZE];
    int front;
    int rear;
}Queue;

int InitQueue(Queue* q);//��ʼ��˳�����
int push(Queue* q, Box b);//���Ӳ���
int EmptyQueue(Queue* q);//�ж϶����Ƿ�Ϊ��
int pop(Queue* q, Box* b);//���Ӳ�����ֻ�ǲ�����ͷָ�룬Ԫ��ʵ�ʻ������ڶ����У�
void ShowPath(Queue* q, int front);//��ӡ·��
int Walk(Queue* q, int x1, int y1, int x2, int y2);
void Display();


