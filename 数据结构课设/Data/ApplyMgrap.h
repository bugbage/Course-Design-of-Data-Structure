#pragma once
#include"stdio.h"
#include"stdlib.h"
#define M 20
typedef char vertextype;
typedef struct node  //边结点类型定义
{
	int adjvex;
	struct node* next;
}EdgeNode;
typedef struct   //带顶点入度的头结点定义
{
	EdgeNode* firstedge;
	vertextype vertex;
	int id;   //顶点的入度域
}VertexNode;
typedef struct   //AOV网的邻接表结构
{
	VertexNode adjlist[M];
	int n, e;   //图的顶点数与边数
}AovGraph;
void creataov(AovGraph* g);  //建立AOV网的邻接表 
void TopSort(AovGraph g);  //AOV网拓扑排序 

