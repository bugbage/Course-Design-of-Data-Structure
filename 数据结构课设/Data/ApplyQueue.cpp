#include"ApplyQueue.h"
int maps[6][6] = {
    {0, 0, 0, 1, 1, 1},
    {1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0},
    {1, 1, 0, 0, 0, 0},
    {1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 0, 1},
};
//初始化顺序队列
int InitQueue(Queue* q)
{
    q->front = q->rear = -1;
    return 1;
}

//进队操作
int push(Queue* q, Box b)
{
    if (q->rear == SIZE - 1)
    {
        return 0;
    }
    (q->rear)++;
    q->data[q->rear] = b;

    return 1;
}

//判断队列是否为空
int EmptyQueue(Queue* q)
{
    return (q->front == q->rear) ? 1 : 0;
}

//出队操作（只是操作对头指针，元素实际还保留在队列中）
int pop(Queue* q, Box* b)
{
    if (q->front == q->rear)
    {
        return 0;
    }
    (q->front)++;
    *b = q->data[q->front];

    return 1;
}

//打印路径
void ShowPath(Queue* q, int front)
{
    int p = front, tmp;
    while (p != 0)
    {
        tmp = q->data[p].pre;
        q->data[p].pre = -1;
        p = tmp;
    }

    int i;
    for (i = 0; i <= q->rear; i++)
    {
        if (q->data[i].pre == -1)
        {
            printf("(%d, %d)->", q->data[i].x, q->data[i].y);
        }
    }
    printf("\n");
}

//入口（0，0） 出口（5，4）
int Walk(Queue* q, int x1, int y1, int x2, int y2)
{
   
    Box now;
    int i, j, i0, j0;

    now.x = x1;
    now.y = y1;
    now.pre = -1;
    push(q, now);            //入口信息入队
    maps[x1][y1] = -1;

    while (EmptyQueue(q) != 1)
    {
        pop(q, &now);

        i = now.x;
        j = now.y;

        if (i == x2 && j == y2)       //出口
        {
            ShowPath(q, q->front);
            return 1;
        }

        int dir;
        for (dir = 0; dir < 4; dir++)   //循环四次，遍历四个方向  上  右  下  左
        {
            switch (dir)
            {
            case 0:            //方向上
                i0 = i - 1;
                j0 = j;
                break;
            case 1:            //方向又
                i0 = i;
                j0 = j + 1;
                break;
            case 2:           //方向下
                i0 = i + 1;
                j0 = j;
                break;
            case 3:           //方向左
                i0 = i;
                j0 = j - 1;
                break;
            }
            //判断该点是否可走
            if (i0 >= 0 && j0 >= 0 && i0 <= 5 && j0 <= 5 && maps[i0][j0] == 0)   //格子可以走
            {
                now.x = i0;
                now.y = j0;
                now.pre = q->front;

                push(q, now);
                maps[i0][j0] = -1;     //该点已经走过
            }
        }
    }

    return 0;
}

void Display()
{
    printf("打印迷宫图\n");
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("\t%d", maps[i][j]);
        }
        printf("\n");
    }
}
