#include"ApplyQueue.h"
int maps[6][6] = {
    {0, 0, 0, 1, 1, 1},
    {1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0},
    {1, 1, 0, 0, 0, 0},
    {1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 0, 1},
};
//��ʼ��˳�����
int InitQueue(Queue* q)
{
    q->front = q->rear = -1;
    return 1;
}

//���Ӳ���
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

//�ж϶����Ƿ�Ϊ��
int EmptyQueue(Queue* q)
{
    return (q->front == q->rear) ? 1 : 0;
}

//���Ӳ�����ֻ�ǲ�����ͷָ�룬Ԫ��ʵ�ʻ������ڶ����У�
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

//��ӡ·��
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

//��ڣ�0��0�� ���ڣ�5��4��
int Walk(Queue* q, int x1, int y1, int x2, int y2)
{
   
    Box now;
    int i, j, i0, j0;

    now.x = x1;
    now.y = y1;
    now.pre = -1;
    push(q, now);            //�����Ϣ���
    maps[x1][y1] = -1;

    while (EmptyQueue(q) != 1)
    {
        pop(q, &now);

        i = now.x;
        j = now.y;

        if (i == x2 && j == y2)       //����
        {
            ShowPath(q, q->front);
            return 1;
        }

        int dir;
        for (dir = 0; dir < 4; dir++)   //ѭ���ĴΣ������ĸ�����  ��  ��  ��  ��
        {
            switch (dir)
            {
            case 0:            //������
                i0 = i - 1;
                j0 = j;
                break;
            case 1:            //������
                i0 = i;
                j0 = j + 1;
                break;
            case 2:           //������
                i0 = i + 1;
                j0 = j;
                break;
            case 3:           //������
                i0 = i;
                j0 = j - 1;
                break;
            }
            //�жϸõ��Ƿ����
            if (i0 >= 0 && j0 >= 0 && i0 <= 5 && j0 <= 5 && maps[i0][j0] == 0)   //���ӿ�����
            {
                now.x = i0;
                now.y = j0;
                now.pre = q->front;

                push(q, now);
                maps[i0][j0] = -1;     //�õ��Ѿ��߹�
            }
        }
    }

    return 0;
}

void Display()
{
    printf("��ӡ�Թ�ͼ\n");
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("\t%d", maps[i][j]);
        }
        printf("\n");
    }
}
