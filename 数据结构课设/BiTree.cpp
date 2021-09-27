#include"BaseDefine.h"
Status CreatBiTree(BiTree& T)
{
    TElemType ch,x;
    getchar();
    scanf_s("%c", &ch);
    if (ch == '\n')
    {
        printf("错误输入！！！\n");
        return CreatBiTree(T);
    }
    if (ch == ' ') T = NULL;
    else {
        if (!(T = (BiTNode*)malloc(sizeof(BiTNode))))exit(OVERFLOW);
        T->data = ch;
        printf("构造%c的左子树",ch);
        CreatBiTree(T->lchild);
        printf("构造%c的右子树", ch);
        CreatBiTree(T->rchild);
    }

    return OK;
}

Status PreorderTraverse(BiTree T, Status(*vist)(TElemType e))//递归算法先序遍历二叉树
{
    if (T)
    {
        vist(T->data);
        PreorderTraverse(T->lchild, vist);
        PreorderTraverse(T->rchild, vist);
    }
    else return 0;
    return OK;
}
Status MidorderTraverse(BiTree T, Status(*vist)(TElemType e))
{
    if (T)
    {
        MidorderTraverse(T->lchild, vist);
        cout << "  " << T->data;
        MidorderTraverse(T->rchild, vist);
    }
    else return 0;
    return OK;
}
Status PostorderTraverse(BiTree T, Status(*vist)(TElemType e))
{
    if (T)
    {
        PostorderTraverse(T->lchild, vist);
        PostorderTraverse(T->rchild, vist);
        cout << "  " << T->data;
    }
    else return 0;
    return OK;
}

Status SumPoint(BiTree T, ElemType& e)
{ 
    
    if (T)
    {  ++e;
        SumPoint(T->lchild,e);
        SumPoint(T->rchild,e);
    }
    return OK;
}

Status BiTreeDepth(BiTree T)
{
   
    if (T)
    {
      int a=BiTreeDepth(T->rchild);
      int b=BiTreeDepth(T->lchild);
      return (a > b) ? (a + 1) : (b + 1);
    }
    else
    {
        return 0;
    }
    
}

Status FindParent(BiTree T,ElemType &e, Status(*Compare)(ElemType& e1, ElemType& e2))
{
    if (T)
    {

        if (T->rchild)
        {
            if (T->rchild->data == e)
                e = T->data;
        }
        if (T->lchild)
        {
            if (T->lchild->data == e)
                e = T->data;
        }
        FindParent(T->lchild, e, Compare);
        FindParent(T->rchild, e, Compare);
    }
    return OK;
}

int PrintElemType(TElemType e)
{
    cout << "  " << e;
    return 0;
}
int Compare(ElemType& e1, ElemType& e2)
{
    if (e1 == e2)
        return 1;
    else
        return 0;
}