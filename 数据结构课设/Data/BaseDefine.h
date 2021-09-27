#pragma once
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

#include <cstdlib>
#include<malloc.h>
#include <string.h>
#include <stack>
using namespace std;
#define Maxsize 30
#define INFINITY 99999
using namespace std;
#define OK 1
#define ERROR  0
#define STACK_INIT_SIZE  100//��ʼ������Ĵ洢�ռ�
#define STACKINCREMNET  10//����ռ��������
#define MAXQSIZE  1000//ѭ���������󳤶�
#define INFINITY   INT_MAX//���ֵ�����
#define MAX_VERTEX_NUM  20//��󶥵���;
typedef char VertexType;
typedef int VRType;
typedef char  InfoType;
typedef enum { DG, DN, UDG, UDN } GraphKind;
typedef int ElemType;
typedef int Status;
typedef char TElemType;


typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;//�涨���óɴ���ͷ���ĵ�����ͷ����������洢������ĳ���

Status CreatList_L(LinkList& L, int i);//���쵥��������iΪ������ĳ���
Status InsetList_L(LinkList& L, int i, ElemType& e);//�ڵ������в���һ��Ԫ��
Status DeleteList_L(LinkList& L, int i, ElemType& e);//ɾ���������е�Ԫ�أ�iΪɾ����λ��
Status LocateElem_L(LinkList& L, ElemType& e, Status(*Compare)(ElemType e1, ElemType e2));
Status MergeList_L(LinkList& La, LinkList& Lb, LinkList& Lc);//�ϲ�����������
Status DeleteMidList_L(LinkList& L, ElemType e1, ElemType e2);
void DisplayList_L(LinkList L);//��ӡ������
Status Compare(ElemType e1, ElemType e2);

//ջ�Ķ���
typedef struct {
	ElemType* base;//ջ��ָ��
	ElemType* top;//ջ��ָ��
	int stacksize;//��ǰ����ĳ���
}SqStack;//˳��ջ
Status InitStack_Sq(SqStack& S);
Status Push_Sq(SqStack& S, ElemType& e);
Status GetTop_Sq(SqStack& S, ElemType& e);//��ȡջ��Ԫ��
Status Pop_Sq(SqStack& S, ElemType& e);//ɾ��ջ��Ԫ��
//ѭ������

typedef struct {
	ElemType* base;
	int front;
	int rear;
}SqQueue;
Status InitQueue_Sq(SqQueue& Q);//��ʼ������
Status EnQueue_Sq(SqQueue& Q, ElemType e);
Status DeQueue_Sq(SqQueue& Q, ElemType& e);
Status GetTopElem(SqQueue& Q, ElemType& e);
Status GetRearElem(SqQueue& Q, ElemType& e);
Status QueueLength_Sq(SqQueue*& Q);
Status DisplayQueue_Sq(SqQueue Q);
Status QueueEmpty_Sq(SqQueue& Q);

//������
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* rchild, * lchild;//���Һ���ָ��
}BiTNode, * BiTree;
Status CreatBiTree(BiTree& T);//����һ����������
Status PreorderTraverse(BiTree T, Status(*vist)(TElemType e));//���������������
Status MidorderTraverse(BiTree T, Status(*vist)(TElemType e));//���������������
Status PostorderTraverse(BiTree T, Status(*vist)(TElemType e));//���������������
Status SumPoint(BiTree T, ElemType& e);//�������Ŀ
Status BiTreeDepth(BiTree T);//���������
void Find_Father(BiTree T, ElemType data, int& flag);
void findfather(BiTree T, ElemType data, int flag);
void FindBrother(BiTree T, ElemType data, int flag);
void FindChild(BiTree T, ElemType data);
int PrintElemType(TElemType e);
int Compare(TElemType& e1, TElemType& e2);

//ͼ
typedef struct ArcCell {
	VertexType  adj;//�����ϵ���ͣ���Ȩͼ��0��1��ʾ�Ƿ�����
	InfoType* infor;//�û���ص���Ϣ��ָ��
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�ڽӾ���
typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];//��������
	AdjMatrix  arcs;//�ڽӾ���
	int   vexnum, arcnum;//ͼ��ǰ�Ķ������ͻ���G
	GraphKind  kind;//ͼ�������־
}MGraph;
Status CreateGraph(MGraph& G);
void DisplayAdjMatrix(MGraph& G);
Status  Degreel(MGraph& G, int numb);//����ͼ�����Ϊnumb�Ķ���Ķ���
void DFS(MGraph& G, int i);
void DFStraverse(MGraph &G);


//���нṹ
typedef struct Qnode
{
	char data;
	struct Qnode* next;
}Qnode, * Qptr;     //����ڵ�

typedef struct LINKQUEUE
{
	Qptr front;
	Qptr rear;
}LinkQueue;       //������ס���βָ��

//������ȱ�������һ������ʵ��
void InitQueue(LinkQueue &q);
//�����
void PushQueue(LinkQueue q,int e);
//������
void DetQueue(LinkQueue q, int  &e);

//�����Ƿ�Ϊ��
int QueueEmpty(LinkQueue q);

//������ȱ���
void BFSTraverse(MGraph& G);
//��λ
void GetPosition(MGraph& G, char C);
void Findfirst(MGraph& G, char C);
void Findnext(MGraph& G, char C);
void InsertPoint(MGraph& G,char C);
void InsertBorder(MGraph& G);
void DeletePoint(MGraph& G, char C);
void DeleteBorder(MGraph& G);