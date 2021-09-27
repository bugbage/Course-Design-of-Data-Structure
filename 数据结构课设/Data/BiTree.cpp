#include"BaseDefine.h"
Status CreatBiTree(BiTree& T)
{
    TElemType ch, x;
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
        printf("构造%c的左子树", ch);
        CreatBiTree(T->lchild);
        printf("构造%c的右子树", ch);
        CreatBiTree(T->rchild);
    }

    return OK;
}

Status PreorderTraverse(BiTree T, Status(*vists)(TElemType e))//递归算法先序遍历二叉树
{
    if (T)
    {
        vists(T->data);
        PreorderTraverse(T->lchild, vists);
        PreorderTraverse(T->rchild, vists);
    }
    else return 0;
    return OK;
}
Status MidorderTraverse(BiTree T, Status(*vists)(TElemType e))
{
    if (T)
    {
        MidorderTraverse(T->lchild, vists);
        cout << "  " << T->data;
        MidorderTraverse(T->rchild, vists);
    }
    else return 0;
    return OK;
}
Status PostorderTraverse(BiTree T, Status(*vists)(TElemType e))
{
    if (T)
    {
        PostorderTraverse(T->lchild, vists);
        PostorderTraverse(T->rchild, vists);
        cout << "  " << T->data;
    }
    else return 0;
    return OK;
}
Status SumPoint(BiTree T, ElemType& e)
{

    if (T)
    {
        ++e;
        SumPoint(T->lchild, e);
        SumPoint(T->rchild, e);
    }
    return OK;
}
Status BiTreeDepth(BiTree T)
{

    if (T)
    {
        int a = BiTreeDepth(T->rchild);
        int b = BiTreeDepth(T->lchild);
        return (a > b) ? (a + 1) : (b + 1);
    }
    else
    {
        return 0;
    }

}
void  Find_Father(BiTree T, ElemType data,int &flag)
    {
        if (T == NULL)
            return;
        if (T->lchild != NULL)//当左孩子存在的时候才进行判断，否则程序出错
        {
            if (T->lchild->data == data)
            {
                printf("该节点的父结点是:%c", T->data);
                flag = 1;//全局变量设置了一个标志flag=false，如果找到父结点，则flag赋值为true
            }
        }
        if (T->rchild != NULL)//如左子树所示
        {
            if (T->rchild->data == data)
            {
                printf("该节点的父结点是:%c", T->data);
                flag = 1;
            }

        }
        Find_Father(T->lchild, data,flag);
        Find_Father(T->rchild, data,flag);
    }
void findfather(BiTree T, ElemType data,int flag)
{
    Find_Father(T, data,flag);//执行递归函数
    if (flag == 0)
    {
        printf("你搜索的结点为根节点或你搜索的结点在该二叉树中不存在\n");
    }

}
void FindBrother(BiTree T, ElemType data, int flag)
{
    if (T == NULL)
        return;
    else {
        if (T->lchild != NULL)//当左孩子存在的时候才进行判断，否则程序出错
        {
            if (T->lchild->data == data)
            {
                if (T->rchild != NULL) {
                    printf("该节点的右兄弟是:%c", T->rchild->data);
                    flag = 1;//全局变量设置了一个标志flag=false，如果找到父结点，则flag赋值为true
                    return;
                }
                else
                    printf("该节点没有右兄弟\n");

            }
        }
        if (T->rchild != NULL)//如左子树所示
        {
            if (T->rchild->data == data)
            {

                    if (T->lchild != NULL) {
                        printf("该节点的左兄弟是:%c", T->lchild->data);
                        flag = 1;//全局变量设置了一个标志flag=false，如果找到父结点，则flag赋值为true
                        return;
                    }
                    else
                    printf("该节点没有左兄弟\n");
            }

        }
    }
    FindBrother(T->lchild, data, flag);
    FindBrother(T->rchild, data, flag);
}
void FindChild(BiTree T, ElemType data)
{
    if (T == NULL)
        return;
    if (T->data == data)
    {
        if (T->lchild != NULL)
        {
            printf("该结点的左孩子为:%c", T->lchild->data);
        }
        if (T->rchild != NULL)
        {
            printf("\t该结点的右孩子为:%c", T->rchild->data);
        }

    }
    else
    {
        FindChild(T->lchild, data);
        FindChild(T->rchild, data);
    }
        

}
int PrintElemType(TElemType e)
{
    cout << "  " << e;
    return 0;
}
int Compare(TElemType& e1, TElemType& e2)
{
    if (e1 == e2)
        return 1;
    else
        return 0;
}