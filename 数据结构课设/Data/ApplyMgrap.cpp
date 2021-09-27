#include"ApplyMgrap.h"
void creataov(AovGraph* g)   //����AOV�����ڽӱ� 
{
	int i, j, k;
	EdgeNode* s;
	printf("����ͼ�Ķ������������");
	scanf("%d%d", &g->n, &g->e);
	printf("���붥�㼰��������\n");
	for (i = 0; i < g->n; i++)
	{
		scanf("%ls%d", &g->adjlist[i].vertex, &g->adjlist[i].id);
		g->adjlist[i].firstedge = NULL;
	}
	printf("���������\n");
	for (k = 0; k < g->e; k++)
	{
		scanf("%d%d", &i, &j);
		s = (EdgeNode*)malloc(sizeof(EdgeNode));
		s->adjvex = j;
		s->next = g->adjlist[i].firstedge;
		g->adjlist[i].firstedge = s;
	}
}
void TopSort(AovGraph g)  //AOV���������� 
{
	int i, j, v, flag[M], queue[M], rear, front;
	EdgeNode* p;
	front = rear = 0;  //��ʼ���ն���
	for (i = 0; i < g.n; i++)
		flag[i] = 0;    //��ʼ�����ʱ��
	for (i = 0; i < g.n; i++)    //���Ϊ0�Ľ�����
	{
		if (g.adjlist[i].id == 0 && flag[i] == 0)
		{
			queue[rear++] = i;
			flag[i] = 1;
		}
	}
	printf("���AOV�����������У�");
	while (front < rear)  //���в�Ϊ�� 
	{
		v = queue[front++];   //����Ԫ���� 
		printf("%c ", g.adjlist[v].vertex);
		p = g.adjlist[v].firstedge;
		while (p)   //������v�ڽӵĶ������ȼ�1 
		{
			j = p->adjvex;
			if (--g.adjlist[j].id == 0 && flag[j] == 0)  //���Ϊ0����� 
			{
				queue[rear++] = j;
				flag[j] = 1;
			}
			p = p->next;
		}
	}
}


