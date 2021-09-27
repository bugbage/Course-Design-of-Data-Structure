#include"BaseDefine.h"
Status CreatList_L(LinkList& L, int i)
{
    L = (LinkList)malloc(sizeof(LNode));
    LinkList a0;//构造头节点
    a0 = (LinkList)malloc(sizeof(LNode));
    L->next = a0;
    a0->data = i;//头节点存储单链表的长度
    LinkList a;
    a = (LinkList)malloc(sizeof(LNode));
    a = a0;
    for (int j = 1; j <= i; j++)
    {
        LinkList p;
        p = (LinkList)malloc(sizeof(LNode));
        cin >> p->data;
        a->next = p;
        a = p;
    }
    a->next = NULL;
    return OK;
}

Status InsetList_L(LinkList& L, int i, ElemType& e)
{
    //判断i的值是否合法
    if (i<1 || i>L->next->data)
        return ERROR;
    LNode* p;
    p = (LNode*)malloc(sizeof(LNode));
    p = L->next;
    LNode* q;
    q = (LNode*)malloc(sizeof(LNode));
    (L->next->data) += 1;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    //链接结点
    q->next = p->next;
    p->next = q;
    q->data = e;
    return OK;
}

Status DeleteList_L(LinkList& L, int i, ElemType& e)
{
    //判断i的值是否合法
    if (i<1 || i>L->next->data)return ERROR;
    LinkList p;
    p = (LinkList)malloc(sizeof(LNode));
    p = L->next;
    LinkList q;
    q = (LinkList)malloc(sizeof(LNode));
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    q = p->next;
    e = q->data;
    p->next = q->next;
    (L->next->data)--;//单链表的长度减一
    free(q);
    return OK;
}

Status LocateElem_L(LinkList& L, ElemType& e, Status(*Compare)(ElemType e1, ElemType e2))
{
    LinkList p;
    int i = 1;
    p = (LinkList)malloc(sizeof(LNode));
    p = L->next;
    p = p->next;
    while (i <= L->next->data && !(*Compare)(p->data, e)) { p = p->next; i++; }
    if (i <= L->next->data)
        printf("元素%d在单链表中的位置为%d\n", e, i);
    return OK;
}

Status MergeList_L(LinkList& La, LinkList& Lb, LinkList& Lc)
{
    LinkList pa, pb, pc, a0;
    pa = (LinkList)malloc(sizeof(LNode));
    pb = (LinkList)malloc(sizeof(LNode));
    Lc = (LinkList)malloc(sizeof(LNode));
    a0 = (LinkList)malloc(sizeof(LNode));
    pa = La->next;
    pb = Lb->next;
    Lc->next = a0;
    a0->data = pa->data + pb->data;
    while (pa->next)
    {
        pa = pa->next;
        a0->next = pa;
        a0 = a0->next;
    }
    a0->next = pb->next;
    return OK;
}

Status DeleteMidList_L(LinkList& L, ElemType e1, ElemType e2)
{
    LinkList p, q;
    int e = L->next->data, j = 1;
    p = (LinkList)malloc(sizeof(LNode));
    q = (LinkList)malloc(sizeof(LNode));
    q = L->next;
    p = q->next;
    while (p && j <= e)
    {

        if (p->data > e1 && p->data < e2)
        {
            q->next = p->next;
            p = p->next;
            L->next->data--;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
    return OK;
}

void DisplayList_L(LinkList L)
{
    LNode* p;
    p = (LNode*)malloc(sizeof(LNode));
    p = L->next;
    cout << "************************\n";
    for (int j = 1; j <= L->next->data; j++)
    {
        p = p->next;
        cout << "  " << p->data;
    }
    cout << "\n";
}

Status  Compare(ElemType e1, ElemType e2)
{
    if (e1 == e2)
        return 1;
    return 0;
}
