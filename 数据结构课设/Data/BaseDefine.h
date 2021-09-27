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
#define STACK_INIT_SIZE  100//初始化分配的存储空间
#define STACKINCREMNET  10//储存空间分配增量
#define MAXQSIZE  1000//循环链表的最大长度
#define INFINITY   INT_MAX//最大值无穷大
#define MAX_VERTEX_NUM  20//最大顶点数;
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
}LNode, * LinkList;//规定设置成带有头结点的单链表，头结点的数据域存储单链表的长度

Status CreatList_L(LinkList& L, int i);//构造单链表，参数i为单链表的长度
Status InsetList_L(LinkList& L, int i, ElemType& e);//在单链表中插入一个元素
Status DeleteList_L(LinkList& L, int i, ElemType& e);//删除单链表中的元素，i为删除的位置
Status LocateElem_L(LinkList& L, ElemType& e, Status(*Compare)(ElemType e1, ElemType e2));
Status MergeList_L(LinkList& La, LinkList& Lb, LinkList& Lc);//合并两个单链表
Status DeleteMidList_L(LinkList& L, ElemType e1, ElemType e2);
void DisplayList_L(LinkList L);//打印单链表
Status Compare(ElemType e1, ElemType e2);

//栈的定义
typedef struct {
	ElemType* base;//栈底指针
	ElemType* top;//栈顶指针
	int stacksize;//当前分配的长度
}SqStack;//顺序栈
Status InitStack_Sq(SqStack& S);
Status Push_Sq(SqStack& S, ElemType& e);
Status GetTop_Sq(SqStack& S, ElemType& e);//获取栈顶元素
Status Pop_Sq(SqStack& S, ElemType& e);//删除栈顶元素
//循环队列

typedef struct {
	ElemType* base;
	int front;
	int rear;
}SqQueue;
Status InitQueue_Sq(SqQueue& Q);//初始化队列
Status EnQueue_Sq(SqQueue& Q, ElemType e);
Status DeQueue_Sq(SqQueue& Q, ElemType& e);
Status GetTopElem(SqQueue& Q, ElemType& e);
Status GetRearElem(SqQueue& Q, ElemType& e);
Status QueueLength_Sq(SqQueue*& Q);
Status DisplayQueue_Sq(SqQueue Q);
Status QueueEmpty_Sq(SqQueue& Q);

//二叉树
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* rchild, * lchild;//左右孩子指针
}BiTNode, * BiTree;
Status CreatBiTree(BiTree& T);//构造一个二叉链表
Status PreorderTraverse(BiTree T, Status(*vist)(TElemType e));//先序遍历二叉链表
Status MidorderTraverse(BiTree T, Status(*vist)(TElemType e));//中序遍历二叉链表
Status PostorderTraverse(BiTree T, Status(*vist)(TElemType e));//后序遍历二叉链表
Status SumPoint(BiTree T, ElemType& e);//求结点的数目
Status BiTreeDepth(BiTree T);//求树的深度
void Find_Father(BiTree T, ElemType data, int& flag);
void findfather(BiTree T, ElemType data, int flag);
void FindBrother(BiTree T, ElemType data, int flag);
void FindChild(BiTree T, ElemType data);
int PrintElemType(TElemType e);
int Compare(TElemType& e1, TElemType& e2);

//图
typedef struct ArcCell {
	VertexType  adj;//顶点关系类型，无权图用0或1表示是否相邻
	InfoType* infor;//该弧相关的信息的指针
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//邻接矩阵
typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];//顶点向量
	AdjMatrix  arcs;//邻接矩阵
	int   vexnum, arcnum;//图当前的顶点数和弧数G
	GraphKind  kind;//图的种类标志
}MGraph;
Status CreateGraph(MGraph& G);
void DisplayAdjMatrix(MGraph& G);
Status  Degreel(MGraph& G, int numb);//无向图中序号为numb的顶点的度数
void DFS(MGraph& G, int i);
void DFStraverse(MGraph &G);


//队列结构
typedef struct Qnode
{
	char data;
	struct Qnode* next;
}Qnode, * Qptr;     //定义节点

typedef struct LINKQUEUE
{
	Qptr front;
	Qptr rear;
}LinkQueue;       //定义队首、队尾指针

//广度优先遍历—用一个队列实现
void InitQueue(LinkQueue &q);
//入队列
void PushQueue(LinkQueue q,int e);
//出队列
void DetQueue(LinkQueue q, int  &e);

//检验是否为空
int QueueEmpty(LinkQueue q);

//广度优先遍历
void BFSTraverse(MGraph& G);
//定位
void GetPosition(MGraph& G, char C);
void Findfirst(MGraph& G, char C);
void Findnext(MGraph& G, char C);
void InsertPoint(MGraph& G,char C);
void InsertBorder(MGraph& G);
void DeletePoint(MGraph& G, char C);
void DeleteBorder(MGraph& G);