#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* HuffmanCode;/*动态分配数组，存储哈夫曼编码*/

typedef struct
{
	unsigned int weight; /* 用来存放各个结点的权值*/
	unsigned int parent, LChild, RChild; /*指向双亲、孩子结点的指针*/
}HTNode, * HuffmanTree;   /*动态分配数组，存储哈夫曼树*/

void select(HuffmanTree* ht, int n, int* s1, int* s2);
void CrtHuffmanTree(HuffmanTree* ht, int* w, int n);
void outputHuffman(HuffmanTree HT, int m);
void CrtHuffmanCode(HuffmanTree* ht, HuffmanCode* hc, int n);/*从叶子结点到根，逆向求每个叶子结点对应的哈夫曼编码*/
