#pragma once
#include"stdio.h"
#include"stdlib.h"
#define M 20
typedef char vertextype;
typedef struct node  //�߽�����Ͷ���
{
	int adjvex;
	struct node* next;
}EdgeNode;
typedef struct   //��������ȵ�ͷ��㶨��
{
	EdgeNode* firstedge;
	vertextype vertex;
	int id;   //����������
}VertexNode;
typedef struct   //AOV�����ڽӱ�ṹ
{
	VertexNode adjlist[M];
	int n, e;   //ͼ�Ķ����������
}AovGraph;
void creataov(AovGraph* g);  //����AOV�����ڽӱ� 
void TopSort(AovGraph g);  //AOV���������� 

