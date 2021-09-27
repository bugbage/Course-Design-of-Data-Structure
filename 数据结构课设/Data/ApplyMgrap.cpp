#include"ApplyMgrap.h"
void creataov(AovGraph* g)   //建立AOV网的邻接表 
{
	int i, j, k;
	EdgeNode* s;
	printf("输入图的顶点数与边数：");
	scanf("%d%d", &g->n, &g->e);
	printf("输入顶点及顶点的入度\n");
	for (i = 0; i < g->n; i++)
	{
		scanf("%ls%d", &g->adjlist[i].vertex, &g->adjlist[i].id);
		g->adjlist[i].firstedge = NULL;
	}
	printf("输入有序对\n");
	for (k = 0; k < g->e; k++)
	{
		scanf("%d%d", &i, &j);
		s = (EdgeNode*)malloc(sizeof(EdgeNode));
		s->adjvex = j;
		s->next = g->adjlist[i].firstedge;
		g->adjlist[i].firstedge = s;
	}
}
void TopSort(AovGraph g)  //AOV网拓扑排序 
{
	int i, j, v, flag[M], queue[M], rear, front;
	EdgeNode* p;
	front = rear = 0;  //初始化空队列
	for (i = 0; i < g.n; i++)
		flag[i] = 0;    //初始化访问标记
	for (i = 0; i < g.n; i++)    //入度为0的结点进队
	{
		if (g.adjlist[i].id == 0 && flag[i] == 0)
		{
			queue[rear++] = i;
			flag[i] = 1;
		}
	}
	printf("输出AOV网的拓扑序列：");
	while (front < rear)  //队列不为空 
	{
		v = queue[front++];   //队首元出队 
		printf("%c ", g.adjlist[v].vertex);
		p = g.adjlist[v].firstedge;
		while (p)   //所有与v邻接的顶点的入度减1 
		{
			j = p->adjvex;
			if (--g.adjlist[j].id == 0 && flag[j] == 0)  //入度为0则进队 
			{
				queue[rear++] = j;
				flag[j] = 1;
			}
			p = p->next;
		}
	}
}


