#include"BaseDefine.h"
#include "ApplyLinkList.h"
#include "ApplyStack.h"
#include"ApplyQueue.h"
#include "ApplyBiTree.h"
#include "ApplyMgrap.h"
void ShowMainMenu() {
		printf("\n");
		printf("*******************�㷨�����ݽṹ******************\n");
		printf("* 1  ������Ļ���������Ӧ��                       *\n");
		printf("* 2  ջ�Ļ���������Ӧ��                           *\n");
		printf("* 3  ���еĻ���������Ӧ��                         *\n");
		printf("* 4  �������Ļ���������Ӧ��                       *\n");
		printf("* 5  ͼ�Ļ���������Ӧ��                           *\n");
		printf("* 6  �˳�                                         *\n");
		printf("***************************************************\n");
	}
void applyLinkList()
{
	int num = 0;
	PhoneList P;
	Create(P);
	int e=0, n=0;
	printf("***************************************************\n");
	printf("*  ͨѶ¼���                                    *\n");
	printf("***************************************************\n");
	do
	{
		printf("\n");
		printf("*********************\n");
		printf("* 1 �����ϵ��      *\n");
		printf("* 2 ������ϵ��      *\n");
		printf("* 3 ɾ����ϵ��      *\n");
		printf("* 4 ������ϵ�˺���  *\n");
		printf("* 5 ���ͨѶ¼      *\n");
		printf("* 6 �˳�            *\n");
		printf("*********************\n");
		printf("��ѡ��");
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			CreatPhoneNode(P);
			break;
		case 2:SerachPeople(P);
			break;
		case 3:DeletePeople(P);
			break;
		case 4:Changenumber(P);
			break;
		case 5:
			ShowPhoneNode(P);
			break;
		case 6:
			break;
		}

	} while (n!= 6);
}
void applyStack()
{
	printf("***************************************************\n");
	printf("* ���ʽ��ֵ                                      *\n");
	printf("***************************************************\n");
		char exp[100]; //����һ���ַ��������ڴ洢���ʽ
		int result;
		printf("��������ʽ:");
		getchar();
		gets_s(exp); //����scanf����%s����exp����Ҳ����
		result = evaluateExpression(exp);
		printf("\n");
		printf("%s%d\n", exp, result);
}
void applyQueue()
{
	    printf("������ȱ���\n");
		Queue queues;
		int x1, x2, y1, y2;
		InitQueue(&queues);
		Display();
		printf("******************************\n");
		printf("��������ںͳ���\n");
		cin >> x1 >> y1 >> x2 >> y2;
		if (Walk(&queues, x1, y1, x2, y2) == 0)
		{
			printf("·��������\n");
		}

}
void applyBiTree()
{
	printf("����������\n");
		HuffmanTree HT;
		HuffmanCode HC;
		int* w;
		int i, n;      // the number of elements; 
		int wei;    // the weight of a element; 
		int m;

		printf("����ڵ����:");
		scanf_s("%d", &n);
		w = (int*)malloc((n + 1) * sizeof(int));
		for (i = 1; i <= n; i++)
		{
			printf("�����%d:", i);
			fflush(stdin);
			scanf_s("%d", &wei);
			w[i] = wei;
		}

		CrtHuffmanTree(&HT, w, n);
		m = 2 * n - 1;
		outputHuffman(HT, m);
		printf("\n");
		CrtHuffmanCode(&HT, &HC, n);
}
void SwitchLinkList() {
	int n = 0;
	int num = 0;
	do {
		printf("\n");
		printf("**************������Ļ���������Ӧ��***************\n");
		printf("* 1  ����                                         *\n");
		printf("* 2  ����                                         *\n");
		printf("* 3  ɾ��                                         *\n");
		printf("* 4  ����                                         *\n");
		printf("* 5  Ӧ��                                         *\n");
		printf("* 6  �˳�                                         *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf_s("%d", &n);
		LinkList L;
		ElemType e = 0;
		int i = 0;
		switch (n) {
		case 1:
			printf("--------����������---------");
			; printf("\n�����뵥����ĳ���");
			cin >> i;
			CreatList_L(L, i);
			printf("��������ĵ�����\n");
			DisplayList_L(L);
			break;
		case 2:
			printf("--------����Ԫ��-------\n");
			printf("����������λ�á�ֵ");
			cin >> i >> e;
			InsetList_L(L, i, e);
			printf("��������ĵ�����\n");
			DisplayList_L(L);
			break;
		case 3:
			printf("--------ɾ��Ԫ��-------\n");
			printf("������ɾ��Ԫ�ص�λ��");
			cin >> i;
			DeleteList_L(L, i, e);
			printf("���ɾ����ĵ�����\n");
			DisplayList_L(L);
			break;
		case 4:
			printf("--------����Ԫ��-------");
			printf("��������ҵ�Ԫ��");
			cin >> e;
			LocateElem_L(L, e, Compare);
			break;
		case 5:
			printf("--------Ӧ��---------\n");
			applyLinkList();
			break;
		case 6: break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 6);
}
void SwitchStack() {
	int n;
	SqStack S;
	ElemType e = 0;
	do {
		printf("\n");
		printf("****************ջ�Ļ���������Ӧ��*****************\n");
		printf("* 1  ��ջ                                         *\n");
		printf("* 2  ��ջ                                         *\n");
		printf("* 3  ȡջ��Ԫ��                                   *\n");
		printf("* 4  Ӧ��                                         *\n");
		printf("* 5  �˳�                                         *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("--------��ջ-------\n");
			printf("�������ջ��Ԫ��");
			cin >> e;
			InitStack_Sq(S);
			Push_Sq(S, e);
			break;
		case 2:
			printf("--------��ջ-------\n");
			Push_Sq(S, e);
			cout << e << endl;
			break;
		case 3:
			printf("--------ȡջ��Ԫ��-------\n");
			GetTop_Sq(S, e);
			cout << e << endl;
			break;
		case 4:
			printf("--------Ӧ��-------\n");
			printf("���ʽ��ֵ\n");
			applyStack();
			break;
		case 5:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 5);
}
void SwitchQueue() {
	int n;
	SqQueue Q;
	ElemType e = 0;
	InitQueue_Sq(Q);
	do {
		printf("\n");
		printf("*************���еĻ���������Ӧ��**************\n");
		printf("* 1  ����                                     *\n");
		printf("* 2  ����                                     *\n");
		printf("* 3  ȡ��ͷԪ��                               *\n");
		printf("* 4  ȡ��βԪ��                               *\n");
		printf("* 5  Ӧ��                                     *\n");
		printf("* 6  �˳�                                     *\n");
		printf("***********************************************\n");
		printf("��ѡ��");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("---------����-------\n");
			printf("���������е�Ԫ��");
			cin >> e;
			EnQueue_Sq(Q, e);
			break;
		case 2:
			printf("---------����-------\n");
			EnQueue_Sq(Q, e);
			printf("���е�Ԫ��Ϊ%d\n", e);
			break;
		case 3:
			printf("---------ȡ��ͷԪ��-------\n");
			GetTopElem(Q, e);
			printf("��ȡ��ͷ��Ԫ��Ϊ%d\n", e);
			break;
		case 4:
			printf("---------ȡ��βԪ��-------\n");
			GetRearElem(Q, e);
			printf("��ȡ��β��Ԫ��Ϊ%d\n", e);
			break;
		case 5:
			printf("---------Ӧ��-------\n");
			applyQueue();
			break;
		case 6:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 6);
}
void SwitchBiTree() {
	int n;
	BiTree T = NULL;
	int i = 0;
	int x = 0;
	TElemType e = 0;
	do {
		printf("\n");
		printf("**************�������Ļ���������Ӧ��***************\n");
		printf("* 1  ����                                         *\n");
		printf("* 2  ��������/��/��                             *\n");
		printf("* 3  �������                                   *\n");
		printf("* 4  ���������                                   *\n");
		printf("* 5  ����˫��                                     *\n");
		printf("* 6  �����ֵܣ���/�ң�                            *\n");
		printf("* 7  ���Һ��ӣ���/�ң�                            *\n");
		printf("* 8  Ӧ��                                         *\n");
		printf("* 9  �˳�                                         *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("---------����--------\n");
			printf("��ʼ���������\n");
			CreatBiTree(T);
			break;
		case 2:
			printf("---------��������/��/��-------");
			printf("\nǰ�������������\n");
			PreorderTraverse(T, PrintElemType);
			printf("\n���������������\n");
			MidorderTraverse(T, PrintElemType);
			printf("\n���������������\n");
			PostorderTraverse(T, PrintElemType);
			break;
		case 3:
			printf("---------�������-------\n");
			SumPoint(T, i);
			printf("���ĸ���%d\n", i);
			break;
		case 4:
			printf("---------���������-------\n");
			printf("�������Ϊ%d\n", BiTreeDepth(T));
			break;
		case 5:
			printf("---------����˫��-------\n");
			printf("��������ҵ�Ԫ��\n");
			cin >> e;
			findfather(T, e, x);
			x = 0;
			break;
		case 6:
			printf("---------�����ֵܣ���/�ң�-------\n");
			printf("��������ҵ�Ԫ��\n");
			cin >> e;
			FindBrother(T, e, x);
			break;
		case 7:
			printf("---------���Һ��ӣ���/�ң�-------\n");
			printf("��������ҵ�Ԫ��\n");
			cin >> e;
			FindChild(T, e);
			break;
		case 8:
			printf("---------Ӧ��-------\n");
			applyBiTree();
			break;
		case 9:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 9);
}
void SwitchMgrap()
{
	int n;
	MGraph G;
	int v = 0;
	do {
		printf("\n");
		printf("****************ͼ�Ļ���������Ӧ��*****************\n");
		printf("* 1  �������ڽӾ���                             *\n");
		printf("* 2  ���������/��ȣ�                            *\n");
		printf("* 3  ��λ                                         *\n");
		printf("* 4  �ҵ�һ���ڽӵ�                               *\n");
		printf("* 5  ����һ���ڽӵ�                               *\n");
		printf("* 6  ���루��/�ߣ�                                *\n");
		printf("* 7  ɾ������/�ߣ�                                *\n");
		printf("* 8  Ӧ��                                         *\n");
		printf("* 9  �˳�                                         *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("---------�������ڽӾ���-------\n");
			CreateGraph(G);
			DisplayAdjMatrix(G);
			break;
		case 2:
			printf("---------���������/��ȣ�-------\n");
			printf("\n������ȱ���:\n");
			DFStraverse(G);
			printf("\n������ȱ���:\n");
			BFSTraverse(G);
			break;
		case 3:
			printf("---------��λ-------\n");
			printf("������Ҫ��λ�Ķ���\n");
			char c;
			cin >> c;
			GetPosition(G,c);
			break;
		case 4:
			printf("---------�ҵ�һ���ڽӵ�-------\n");
			printf("������Ҫ���ҵĶ���\n");
			char c1;
			cin >> c1;
			Findfirst(G, c1);
			break;
		case 5:
			printf("---------����һ���ڽӵ�-------\n");
			printf("������Ҫ���ҵĶ���\n");
			char c2;
			cin >> c2;
			Findnext(G,c2);
				break;
		case 6:
			printf("---------���루��/�ߣ�-------\n");
			printf("������Ҫ����Ķ���\n");
			char c3;
			cin >> c3;
			InsertPoint( G,c3);
			printf("����������ڽӾ���\n");
			DisplayAdjMatrix(G);
			  printf("������Ҫ����ı�\n");
			 InsertBorder(G);
			 printf("����������ڽӾ���\n");
			 DisplayAdjMatrix(G);
			break;
		case 7:
			printf("---------ɾ������/�ߣ�-------\n");
			printf("������Ҫɾ���Ķ���\n");
			char c4;
			cin >> c4;
			DeletePoint(G,c4);
            printf("���ɾ������ڽӾ���\n");
			DisplayAdjMatrix(G);
			printf("������Ҫɾ���Ķ���\n");
			DeleteBorder(G);
			printf("���ɾ������ڽӾ���\n");
			DisplayAdjMatrix(G);
			break;
		case 8:
			printf("---------Ӧ��-------\n");
				AovGraph ag;
				printf("����һ��AOV�����ڽӱ�\n");
				creataov(&ag);
				TopSort(ag);
		      break;
		case 9:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 9);
}	
int main()
{
   int ch = 0;
		do {
		ShowMainMenu();
		cin >> ch;
		switch (ch)
		{    
		case 1:SwitchLinkList(); break;
		case 2:SwitchStack(); break;
		case 3:SwitchQueue(); break;
		case 4 :SwitchBiTree(); break;
		case 5:SwitchMgrap(); break;
		default:printf("ERROR!"); break;
		}
	    } while (ch !=6);
	}
