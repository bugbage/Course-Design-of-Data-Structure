#include "BaseDefine.h"
typedef int boole;
boole visited[MAXQSIZE]; //访问标志数组
Status CreateGraph(MGraph& G)
{
	G.kind = UDG;
	cout << "请输入顶点数、弧数、\n";
	cin >> G.vexnum >> G.arcnum;
	cout << "请输入顶点\n";
	for (int i = 0; i < G.vexnum; ++i)
		cin >> G.vexs[i];//构造顶点向量
	//初始化邻接矩阵
	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = { 0,NULL };
	//构造邻接矩阵
	printf("创建一个无向图\n");
	for (int k = 0; k<G.arcnum; k++)
	{
		int i, j;
		VRType w;
		printf("请输入边(vi,vj)上的下标i,j和权w：\n");
		cin >> i >> j >> w;
		G.arcs[i][j].adj = w;
		G.arcs[j][i].adj = w;
	}
	return OK;
}

void DisplayAdjMatrix(MGraph& G)
{
	cout << "输出图的邻接矩阵\n";
	cout << "******************************\n";
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			printf("%d ", G.arcs[i][j].adj);
		}
		printf("\n");
	}
}

Status Degreel(MGraph& G, int numb)
{
	int degree = 0;
	printf("序号为%d的顶点为%c\n", numb, G.vexs[numb - 1]);
	for (int j = 0; j < G.vexnum; j++)
	{
		degree += G.arcs[numb - 1][j].adj;
	}
	printf("***********************\n");
	printf("序号为%d的顶点的度数为%d", numb, degree);
	return OK;
}
//广度优先遍历
void DFS(MGraph& G, int i)
{
	int j;
	visited[i] = 1; //访问过的结点标记为1
	printf("%c->", G.vexs[i]);
	for (j = 0; j < G.vexnum; j++)
	{
		if (G.arcs[i][j].adj ==1&&visited[j]!=1)
		{
			DFS(G, j);
		}
	}
}

void DFStraverse(MGraph& G)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		visited[i] = 0; //初始化标记数组为0
	}
	for (int i = 0; i < G.arcnum; i++)
	{
		if (visited[i]!=1)
		{
			DFS(G, i);
		}
	}
}


void InitQueue(LinkQueue &q) //队列初始化
{
	//定义头结点，队首队尾都指向头结点
	Qptr firstnode = (Qptr)malloc(sizeof(Qnode));
	q.front = q.rear = firstnode;
	if (!q.front)
	{
		exit(0);
	}
	q.front->next = NULL;
}
//入队列
void PushQueue(LinkQueue q,int e)
{
	//在队尾插入元素
	Qptr p = (Qptr)malloc(sizeof(Qnode));
	if (!p)
	{
		exit(0);
	}
	p->data = e;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;
}
//出队列
void DetQueue(LinkQueue  q, int & e)
{
	//出队列在队首进行
	if (q.front == q.rear)
	{
		printf("队列中无元素！\n");
		exit(0);
	}
	Qptr p = q.front->next;
	e = p->data;
	q.front->next = p->next;
	if (q.rear == p)
	{
		q.rear = q.front;
	}
	free(p);
}
//检验是否为空
int QueueEmpty(LinkQueue  q)
{
	if (q.front == q.rear)
		return 0;
	else
		return 1;
}
//广度优先遍历
void BFSTraverse(MGraph& G)
{
	int  k=0;
	LinkQueue A;
	InitQueue(A);
	for (int i = 0; i < G.vexnum; i++)
	{
		visited[i] = 0; //初始化标记数组
	}
	for (int i = 0; i < G.vexnum; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			printf("%c->", G.vexs[i]);
			PushQueue(A, i);
		}
		while (QueueEmpty(A))
		{
			DetQueue(A, k);
			for (int j = 0; j < G.vexnum; j++)
			{
				if (G.arcs[k][j].adj == 1 && !visited[j])
				{
					visited[j] = 1;
					printf("%c->", G.vexs[j]);
					PushQueue(A, j);
				}
			}
		}
	}
}

void GetPosition(MGraph& G, char C)
{
	int i,j;
	for (i= 0; i < G.vexnum; i++)
	{
		if (G.vexs[i] == C)
		{
			printf("顶点%c在图中的位置%d\n", C, i);
			printf("与它相邻的的邻接点有\n");
			for (j = 0; j < G.vexnum; j++)
			{
				if (G.arcs[i][j].adj == 1)
					printf("\t邻接点:%c\n", G.vexs[j]);
			}
			break;
		}
  }
}

void Findfirst(MGraph& G, char C)
{
	int i, j;
	for (i = 0; i < G.vexnum; i++)
	{
		if (G.vexs[i] == C)
		{
			printf("与它相邻的的邻接点有\n");
			for (j = 0; j < G.vexnum; j++)
			{
				if (G.arcs[i][j].adj == 1)
					printf("\t邻接点:%c\n", G.vexs[j]);
			}
			break;
		}
	}
}

void Findnext(MGraph& G, char C)
{

	int i, j;
	int x, y;
	for (i = 0; i < G.vexnum; i++)
	{
		if (G.vexs[i] == C)
		{
			for (j = 0; j < G.vexnum; j++)
			{
				if (G.arcs[i][j].adj == 1)
				{
					printf("与它的下一个邻接点有\n");
					for (x = j; x <=G.vexnum; x++)
					{
						if (G.arcs[j][x].adj == 1&&G.vexs[x]!=C)
							printf("\t邻接点:%c\n", G.vexs[x]);
						if (x == G.vexnum)
							printf("该结点没有下一个邻接点\n");
					}

				}
			}
			break;
		}
	}
}

void InsertPoint(MGraph&G, char C)
{
	G.vexnum+=1;
	G.vexs[G.vexnum-1]=C;
	printf("请输入插入的顶点和其他顶点的边\n");
		//初始化插入后的邻接矩阵
		for (int i = 0; i < G.vexnum; i++)
				G.arcs[G.vexnum-1][i] = { 0,NULL };
		//重构造邻接矩阵
		for (int k = 0; k < G.vexnum; k++)
		{
			int j;
			VRType w;
			printf("请输入边v%d,vj下标j和权w：\n",G.vexnum);
			cin >>j >> w;
			int x = G.vexnum - 1;
			G.arcs[x][j].adj = w;
			G.arcs[j][x].adj = w;
		}
		

}

void InsertBorder(MGraph& G)
{
	int i = 0;
	printf("请输入插入边的数目\n");
	cin >> i;
	G.arcnum += i;
	for (int k = 0; k <i ; k++)
	{
		int i, j;
		VRType w;
		printf("请输入边(vi,vj)上的下标i,j和权w：\n");
		cin >> i >> j >> w;
		G.arcs[i][j].adj = w;
		G.arcs[j][i].adj = w;
	}
}

void DeletePoint(MGraph& G, char C)
{
	int i;
	//G.vexnum--;
	//找到这个删除的顶点
	for (i = 0; i < G.vexnum; i++)
	{
		if (G.vexs[i] == C)
			for (int j = i; j < G.vexnum - 1; j++)
			{
				G.vexs[j] = G.vexs[j + 1];
			}
	}
	//删除与被删除顶点有关的边采取构造新的邻接矩阵
	//定义一个新的邻接矩阵
	AdjMatrix  newarcs;//邻接矩阵
	//初始化插入后的邻接矩阵
	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			newarcs[i][j] = { 0,NULL };
			VRType w;
	for (int j = 0; j < G.vexnum - 1; j++)
	{
		for (int m = 0; m < G.vexnum - 1; m++)
		{
			if (j!=i&&m!=i)
			{
				newarcs[j][m] = G.arcs[j][m];
			}
			else if (j != i && m == i && m + 1 < G.vexnum)
			{
				newarcs[j][m] = G.arcs[j][m + 1];
			}
			else if (j == i && m != i&&j+1<G.vexnum)
			{
				newarcs[j][m] = G.arcs[j+1][m];
			}
			else if (j == i && m == i && j+1<G.vexnum && m+1< G.vexnum)
			{
				newarcs[j][m] = G.arcs[j + 1][m+1];
			}

		}
		
	}

	G.vexnum--;//顶点数减一
	//邻接矩阵转换
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j] = newarcs[i][j];
		}
	}
	
}

void DeleteBorder(MGraph& G)
{
	int i = 0;
	printf("请输入删除边的数目\n");
	cin >> i;
	G.arcnum = G.arcnum - i;
	for (int k = 0; k < i; k++)
	{
		int i, j;
		printf("请输入删除边(vi,vj)上的下标i,j\n");
		cin >> i >> j;
		G.arcs[i][j].adj = 0;
		G.arcs[j][i].adj = 0;
	}
}

