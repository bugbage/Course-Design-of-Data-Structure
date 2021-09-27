#include"BaseDefine.h"
Status CreatBiTree(BiTree& T)
{
    TElemType ch, x;
    getchar();
    scanf_s("%c", &ch);
    if (ch == '\n')
    {
        printf("�������룡����\n");
        return CreatBiTree(T);
    }
    if (ch == ' ') T = NULL;
    else {
        if (!(T = (BiTNode*)malloc(sizeof(BiTNode))))exit(OVERFLOW);
        T->data = ch;
        printf("����%c��������", ch);
        CreatBiTree(T->lchild);
        printf("����%c��������", ch);
        CreatBiTree(T->rchild);
    }

    return OK;
}

Status PreorderTraverse(BiTree T, Status(*vists)(TElemType e))//�ݹ��㷨�������������
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
        if (T->lchild != NULL)//�����Ӵ��ڵ�ʱ��Ž����жϣ�����������
        {
            if (T->lchild->data == data)
            {
                printf("�ýڵ�ĸ������:%c", T->data);
                flag = 1;//ȫ�ֱ���������һ����־flag=false������ҵ�����㣬��flag��ֵΪtrue
            }
        }
        if (T->rchild != NULL)//����������ʾ
        {
            if (T->rchild->data == data)
            {
                printf("�ýڵ�ĸ������:%c", T->data);
                flag = 1;
            }

        }
        Find_Father(T->lchild, data,flag);
        Find_Father(T->rchild, data,flag);
    }
void findfather(BiTree T, ElemType data,int flag)
{
    Find_Father(T, data,flag);//ִ�еݹ麯��
    if (flag == 0)
    {
        printf("�������Ľ��Ϊ���ڵ���������Ľ���ڸö������в�����\n");
    }

}
void FindBrother(BiTree T, ElemType data, int flag)
{
    if (T == NULL)
        return;
    else {
        if (T->lchild != NULL)//�����Ӵ��ڵ�ʱ��Ž����жϣ�����������
        {
            if (T->lchild->data == data)
            {
                if (T->rchild != NULL) {
                    printf("�ýڵ�����ֵ���:%c", T->rchild->data);
                    flag = 1;//ȫ�ֱ���������һ����־flag=false������ҵ�����㣬��flag��ֵΪtrue
                    return;
                }
                else
                    printf("�ýڵ�û�����ֵ�\n");

            }
        }
        if (T->rchild != NULL)//����������ʾ
        {
            if (T->rchild->data == data)
            {

                    if (T->lchild != NULL) {
                        printf("�ýڵ�����ֵ���:%c", T->lchild->data);
                        flag = 1;//ȫ�ֱ���������һ����־flag=false������ҵ�����㣬��flag��ֵΪtrue
                        return;
                    }
                    else
                    printf("�ýڵ�û�����ֵ�\n");
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
            printf("�ý�������Ϊ:%c", T->lchild->data);
        }
        if (T->rchild != NULL)
        {
            printf("\t�ý����Һ���Ϊ:%c", T->rchild->data);
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