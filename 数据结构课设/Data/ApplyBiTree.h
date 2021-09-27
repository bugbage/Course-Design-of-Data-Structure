#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* HuffmanCode;/*��̬�������飬�洢����������*/

typedef struct
{
	unsigned int weight; /* ������Ÿ�������Ȩֵ*/
	unsigned int parent, LChild, RChild; /*ָ��˫�ס����ӽ���ָ��*/
}HTNode, * HuffmanTree;   /*��̬�������飬�洢��������*/

void select(HuffmanTree* ht, int n, int* s1, int* s2);
void CrtHuffmanTree(HuffmanTree* ht, int* w, int n);
void outputHuffman(HuffmanTree HT, int m);
void CrtHuffmanCode(HuffmanTree* ht, HuffmanCode* hc, int n);/*��Ҷ�ӽ�㵽����������ÿ��Ҷ�ӽ���Ӧ�Ĺ���������*/
