#include "BaseDefine.h"
typedef int boole;
boole visited[MAXQSIZE]; //���ʱ�־����
Status CreateGraph(MGraph& G)
{
	G.kind = UDG;
	cout << "�����붥������������\n";
	cin >> G.vexnum >> G.arcnum;
	cout << "�����붥��\n";
	for (int i = 0; i < G.vexnum; ++i)
		cin >> G.vexs[i];//���춥������
	//��ʼ���ڽӾ���
	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = { 0,NULL };
	//�����ڽӾ���
	printf("����һ������ͼ\n");
	for (int k = 0; k<G.arcnum; k++)
	{
		int i, j;
		VRType w;
		printf("�������(vi,vj)�ϵ��±�i,j��Ȩw��\n");
		cin >> i >> j >> w;
		G.arcs[i][j].adj = w;
		G.arcs[j][i].adj = w;
	}
	return OK;
}

void DisplayAdjMatrix(MGraph& G)
{
	cout << "���ͼ���ڽӾ���\n";
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
	printf("���Ϊ%d�Ķ���Ϊ%c\n", numb, G.vexs[numb - 1]);
	for (int j = 0; j < G.vexnum; j++)
	{
		degree += G.arcs[numb - 1][j].adj;
	}
	printf("***********************\n");
	printf("���Ϊ%d�Ķ���Ķ���Ϊ%d", numb, degree);
	return OK;
}
//������ȱ���
void DFS(MGraph& G, int i)
{
	int j;
	visited[i] = 1; //���ʹ��Ľ����Ϊ1
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
		visited[i] = 0; //��ʼ���������Ϊ0
	}
	for (int i = 0; i < G.arcnum; i++)
	{
		if (visited[i]!=1)
		{
			DFS(G, i);
		}
	}
}


void InitQueue(LinkQueue &q) //���г�ʼ��
{
	//����ͷ��㣬���׶�β��ָ��ͷ���
	Qptr firstnode = (Qptr)malloc(sizeof(Qnode));
	q.front = q.rear = firstnode;
	if (!q.front)
	{
		exit(0);
	}
	q.front->next = NULL;
}
//�����
void PushQueue(LinkQueue q,int e)
{
	//�ڶ�β����Ԫ��
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
//������
void DetQueue(LinkQueue  q, int & e)
{
	//�������ڶ��׽���
	if (q.front == q.rear)
	{
		printf("��������Ԫ�أ�\n");
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
//�����Ƿ�Ϊ��
int QueueEmpty(LinkQueue  q)
{
	if (q.front == q.rear)
		return 0;
	else
		return 1;
}
//������ȱ���
void BFSTraverse(MGraph& G)
{
	int  k=0;
	LinkQueue A;
	InitQueue(A);
	for (int i = 0; i < G.vexnum; i++)
	{
		visited[i] = 0; //��ʼ���������
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
			printf("����%c��ͼ�е�λ��%d\n", C, i);
			printf("�������ڵĵ��ڽӵ���\n");
			for (j = 0; j < G.vexnum; j++)
			{
				if (G.arcs[i][j].adj == 1)
					printf("\t�ڽӵ�:%c\n", G.vexs[j]);
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
			printf("�������ڵĵ��ڽӵ���\n");
			for (j = 0; j < G.vexnum; j++)
			{
				if (G.arcs[i][j].adj == 1)
					printf("\t�ڽӵ�:%c\n", G.vexs[j]);
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
					printf("��������һ���ڽӵ���\n");
					for (x = j; x <=G.vexnum; x++)
					{
						if (G.arcs[j][x].adj == 1&&G.vexs[x]!=C)
							printf("\t�ڽӵ�:%c\n", G.vexs[x]);
						if (x == G.vexnum)
							printf("�ý��û����һ���ڽӵ�\n");
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
	printf("���������Ķ������������ı�\n");
		//��ʼ���������ڽӾ���
		for (int i = 0; i < G.vexnum; i++)
				G.arcs[G.vexnum-1][i] = { 0,NULL };
		//�ع����ڽӾ���
		for (int k = 0; k < G.vexnum; k++)
		{
			int j;
			VRType w;
			printf("�������v%d,vj�±�j��Ȩw��\n",G.vexnum);
			cin >>j >> w;
			int x = G.vexnum - 1;
			G.arcs[x][j].adj = w;
			G.arcs[j][x].adj = w;
		}
		

}

void InsertBorder(MGraph& G)
{
	int i = 0;
	printf("���������ߵ���Ŀ\n");
	cin >> i;
	G.arcnum += i;
	for (int k = 0; k <i ; k++)
	{
		int i, j;
		VRType w;
		printf("�������(vi,vj)�ϵ��±�i,j��Ȩw��\n");
		cin >> i >> j >> w;
		G.arcs[i][j].adj = w;
		G.arcs[j][i].adj = w;
	}
}

void DeletePoint(MGraph& G, char C)
{
	int i;
	//G.vexnum--;
	//�ҵ����ɾ���Ķ���
	for (i = 0; i < G.vexnum; i++)
	{
		if (G.vexs[i] == C)
			for (int j = i; j < G.vexnum - 1; j++)
			{
				G.vexs[j] = G.vexs[j + 1];
			}
	}
	//ɾ���뱻ɾ�������йصı߲�ȡ�����µ��ڽӾ���
	//����һ���µ��ڽӾ���
	AdjMatrix  newarcs;//�ڽӾ���
	//��ʼ���������ڽӾ���
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

	G.vexnum--;//��������һ
	//�ڽӾ���ת��
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
	printf("������ɾ���ߵ���Ŀ\n");
	cin >> i;
	G.arcnum = G.arcnum - i;
	for (int k = 0; k < i; k++)
	{
		int i, j;
		printf("������ɾ����(vi,vj)�ϵ��±�i,j\n");
		cin >> i >> j;
		G.arcs[i][j].adj = 0;
		G.arcs[j][i].adj = 0;
	}
}

