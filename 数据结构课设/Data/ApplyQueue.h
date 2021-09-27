#pragma once

#include <stdio.h>

#define SIZE      1024

typedef struct     //表示一个格子的位置信息
{
    int x;     //横坐标
    int y;     //纵坐标
    int pre;   //前一个格子再在队列里面存放的位置（下标）
} Box;

//顺序队列存放路径的信息
typedef struct
{
    Box data[SIZE];
    int front;
    int rear;
}Queue;

int InitQueue(Queue* q);//初始化顺序队列
int push(Queue* q, Box b);//进队操作
int EmptyQueue(Queue* q);//判断队列是否为空
int pop(Queue* q, Box* b);//出队操作（只是操作对头指针，元素实际还保留在队列中）
void ShowPath(Queue* q, int front);//打印路径
int Walk(Queue* q, int x1, int y1, int x2, int y2);
void Display();


