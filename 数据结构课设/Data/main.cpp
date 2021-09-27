#include"BaseDefine.h"
#include "ApplyLinkList.h"
#include "ApplyStack.h"
#include"ApplyQueue.h"
#include "ApplyBiTree.h"
#include "ApplyMgrap.h"
void ShowMainMenu() {
		printf("\n");
		printf("*******************算法与数据结构******************\n");
		printf("* 1  单链表的基本操作及应用                       *\n");
		printf("* 2  栈的基本操作及应用                           *\n");
		printf("* 3  队列的基本操作及应用                         *\n");
		printf("* 4  二叉树的基本操作及应用                       *\n");
		printf("* 5  图的基本操作及应用                           *\n");
		printf("* 6  退出                                         *\n");
		printf("***************************************************\n");
	}
void applyLinkList()
{
	int num = 0;
	PhoneList P;
	Create(P);
	int e=0, n=0;
	printf("***************************************************\n");
	printf("*  通讯录设计                                    *\n");
	printf("***************************************************\n");
	do
	{
		printf("\n");
		printf("*********************\n");
		printf("* 1 添加联系人      *\n");
		printf("* 2 查找联系人      *\n");
		printf("* 3 删除联系人      *\n");
		printf("* 4 更改联系人号码  *\n");
		printf("* 5 输出通讯录      *\n");
		printf("* 6 退出            *\n");
		printf("*********************\n");
		printf("请选择：");
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
	printf("* 表达式求值                                      *\n");
	printf("***************************************************\n");
		char exp[100]; //定义一个字符数组用于存储表达式
		int result;
		printf("请输入表达式:");
		getchar();
		gets_s(exp); //换成scanf（“%s”，exp）；也可以
		result = evaluateExpression(exp);
		printf("\n");
		printf("%s%d\n", exp, result);
}
void applyQueue()
{
	    printf("广度优先遍历\n");
		Queue queues;
		int x1, x2, y1, y2;
		InitQueue(&queues);
		Display();
		printf("******************************\n");
		printf("请输入入口和出口\n");
		cin >> x1 >> y1 >> x2 >> y2;
		if (Walk(&queues, x1, y1, x2, y2) == 0)
		{
			printf("路径不存在\n");
		}

}
void applyBiTree()
{
	printf("哈夫曼编码\n");
		HuffmanTree HT;
		HuffmanCode HC;
		int* w;
		int i, n;      // the number of elements; 
		int wei;    // the weight of a element; 
		int m;

		printf("输入节点个数:");
		scanf_s("%d", &n);
		w = (int*)malloc((n + 1) * sizeof(int));
		for (i = 1; i <= n; i++)
		{
			printf("输入第%d:", i);
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
		printf("**************单链表的基本操作及应用***************\n");
		printf("* 1  创建                                         *\n");
		printf("* 2  插入                                         *\n");
		printf("* 3  删除                                         *\n");
		printf("* 4  查找                                         *\n");
		printf("* 5  应用                                         *\n");
		printf("* 6  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf_s("%d", &n);
		LinkList L;
		ElemType e = 0;
		int i = 0;
		switch (n) {
		case 1:
			printf("--------创建单链表---------");
			; printf("\n请输入单链表的长度");
			cin >> i;
			CreatList_L(L, i);
			printf("输出创建的单链表\n");
			DisplayList_L(L);
			break;
		case 2:
			printf("--------插入元素-------\n");
			printf("请输入插入的位置、值");
			cin >> i >> e;
			InsetList_L(L, i, e);
			printf("输出插入后的单链表\n");
			DisplayList_L(L);
			break;
		case 3:
			printf("--------删除元素-------\n");
			printf("请输入删除元素的位置");
			cin >> i;
			DeleteList_L(L, i, e);
			printf("输出删除后的单链表\n");
			DisplayList_L(L);
			break;
		case 4:
			printf("--------查找元素-------");
			printf("请输入查找的元素");
			cin >> e;
			LocateElem_L(L, e, Compare);
			break;
		case 5:
			printf("--------应用---------\n");
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
		printf("****************栈的基本操作及应用*****************\n");
		printf("* 1  进栈                                         *\n");
		printf("* 2  出栈                                         *\n");
		printf("* 3  取栈顶元素                                   *\n");
		printf("* 4  应用                                         *\n");
		printf("* 5  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("--------进栈-------\n");
			printf("请输入进栈的元素");
			cin >> e;
			InitStack_Sq(S);
			Push_Sq(S, e);
			break;
		case 2:
			printf("--------出栈-------\n");
			Push_Sq(S, e);
			cout << e << endl;
			break;
		case 3:
			printf("--------取栈顶元素-------\n");
			GetTop_Sq(S, e);
			cout << e << endl;
			break;
		case 4:
			printf("--------应用-------\n");
			printf("表达式求值\n");
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
		printf("*************队列的基本操作及应用**************\n");
		printf("* 1  入列                                     *\n");
		printf("* 2  出列                                     *\n");
		printf("* 3  取队头元素                               *\n");
		printf("* 4  取队尾元素                               *\n");
		printf("* 5  应用                                     *\n");
		printf("* 6  退出                                     *\n");
		printf("***********************************************\n");
		printf("请选择：");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("---------入列-------\n");
			printf("请输入入列的元素");
			cin >> e;
			EnQueue_Sq(Q, e);
			break;
		case 2:
			printf("---------出列-------\n");
			EnQueue_Sq(Q, e);
			printf("出列的元素为%d\n", e);
			break;
		case 3:
			printf("---------取队头元素-------\n");
			GetTopElem(Q, e);
			printf("获取队头的元素为%d\n", e);
			break;
		case 4:
			printf("---------取队尾元素-------\n");
			GetRearElem(Q, e);
			printf("获取队尾的元素为%d\n", e);
			break;
		case 5:
			printf("---------应用-------\n");
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
		printf("**************二叉树的基本操作及应用***************\n");
		printf("* 1  创建                                         *\n");
		printf("* 2  遍历（先/中/后）                             *\n");
		printf("* 3  求结点个数                                   *\n");
		printf("* 4  求树的深度                                   *\n");
		printf("* 5  查找双亲                                     *\n");
		printf("* 6  查找兄弟（左/右）                            *\n");
		printf("* 7  查找孩子（左/右）                            *\n");
		printf("* 8  应用                                         *\n");
		printf("* 9  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("---------创建--------\n");
			printf("开始构造二叉树\n");
			CreatBiTree(T);
			break;
		case 2:
			printf("---------遍历（先/中/后）-------");
			printf("\n前序遍历二叉链表\n");
			PreorderTraverse(T, PrintElemType);
			printf("\n中序遍历二叉链表\n");
			MidorderTraverse(T, PrintElemType);
			printf("\n后序遍历二叉链表\n");
			PostorderTraverse(T, PrintElemType);
			break;
		case 3:
			printf("---------求结点个数-------\n");
			SumPoint(T, i);
			printf("结点的个数%d\n", i);
			break;
		case 4:
			printf("---------求树的深度-------\n");
			printf("树的深度为%d\n", BiTreeDepth(T));
			break;
		case 5:
			printf("---------查找双亲-------\n");
			printf("请输入查找的元素\n");
			cin >> e;
			findfather(T, e, x);
			x = 0;
			break;
		case 6:
			printf("---------查找兄弟（左/右）-------\n");
			printf("请输入查找的元素\n");
			cin >> e;
			FindBrother(T, e, x);
			break;
		case 7:
			printf("---------查找孩子（左/右）-------\n");
			printf("请输入查找的元素\n");
			cin >> e;
			FindChild(T, e);
			break;
		case 8:
			printf("---------应用-------\n");
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
		printf("****************图的基本操作及应用*****************\n");
		printf("* 1  创建（邻接矩阵）                             *\n");
		printf("* 2  遍历（深度/广度）                            *\n");
		printf("* 3  定位                                         *\n");
		printf("* 4  找第一个邻接点                               *\n");
		printf("* 5  找下一个邻接点                               *\n");
		printf("* 6  插入（点/边）                                *\n");
		printf("* 7  删除（点/边）                                *\n");
		printf("* 8  应用                                         *\n");
		printf("* 9  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("---------创建（邻接矩阵）-------\n");
			CreateGraph(G);
			DisplayAdjMatrix(G);
			break;
		case 2:
			printf("---------遍历（深度/广度）-------\n");
			printf("\n深度优先遍历:\n");
			DFStraverse(G);
			printf("\n广度优先遍历:\n");
			BFSTraverse(G);
			break;
		case 3:
			printf("---------定位-------\n");
			printf("请输入要定位的顶点\n");
			char c;
			cin >> c;
			GetPosition(G,c);
			break;
		case 4:
			printf("---------找第一个邻接点-------\n");
			printf("请输入要查找的顶点\n");
			char c1;
			cin >> c1;
			Findfirst(G, c1);
			break;
		case 5:
			printf("---------找下一个邻接点-------\n");
			printf("请输入要查找的顶点\n");
			char c2;
			cin >> c2;
			Findnext(G,c2);
				break;
		case 6:
			printf("---------插入（点/边）-------\n");
			printf("请输入要插入的顶点\n");
			char c3;
			cin >> c3;
			InsertPoint( G,c3);
			printf("输出插入后的邻接矩阵\n");
			DisplayAdjMatrix(G);
			  printf("请输入要插入的边\n");
			 InsertBorder(G);
			 printf("输出插入后的邻接矩阵\n");
			 DisplayAdjMatrix(G);
			break;
		case 7:
			printf("---------删除（点/边）-------\n");
			printf("请输入要删除的顶点\n");
			char c4;
			cin >> c4;
			DeletePoint(G,c4);
            printf("输出删除后的邻接矩阵\n");
			DisplayAdjMatrix(G);
			printf("请输入要删除的顶点\n");
			DeleteBorder(G);
			printf("输出删除后的邻接矩阵\n");
			DisplayAdjMatrix(G);
			break;
		case 8:
			printf("---------应用-------\n");
				AovGraph ag;
				printf("创建一个AOV网的邻接表\n");
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
