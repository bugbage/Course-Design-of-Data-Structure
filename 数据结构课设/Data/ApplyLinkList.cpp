#include"ApplyLinkList.h"

int  Create(PhoneList& P)
{
	P = (PhoneList)malloc(sizeof(PhoneNode));
	P->next = NULL;
	char name[] = "ͨѶ¼";
	char number[] = "0";
	strcpy_s(P->name, name);
	strcpy_s(P->number, number);
	P->next = NULL;
	return 1;
}
int  CreatPhoneNode(PhoneList& P)
{
	PhoneList p, q;
	p = (PhoneList)malloc(sizeof(PhoneNode));
	q = (PhoneList)malloc(sizeof(PhoneNode));
	p = P;
	printf("��������ϵ�˵��������绰\n");
	cin >> q->name >> q->number;
	if (strlen(q->number) == 11)
	{
		while (p)
		{
			if (!p->next)
			{
				p->next = q;
				p = p->next;
				break;
			}
			else
				p = p->next;
		}
		p->next = NULL;
		return	1;
	}
	else
	{
		printf("����ĵ绰����������������\n");
		CreatPhoneNode(P);
		return 0;
	}

}
int  SerachPeople(PhoneList& P)
{
	PhoneList p;
	p = (PhoneList)malloc(sizeof(PhoneNode));
	p = P->next;
	char name[20];
	printf("������Ҫ���ҵ���ϵ������\n");
	cin >> name;
	while (p)
	{
		if (strcmp(name, p->name) == 0)
		{
			printf("��ϵ�˵�����:%s\n", p->name);
			printf("�绰���룺%s\n", p->number);
			break;
		}
		else
			p = p->next;
	}
	return 1;
}
int  DeletePeople(PhoneList& P)
{
	PhoneList p, q;
	char name[20];
	p = (PhoneList)malloc(sizeof(PhoneNode));
	q = (PhoneList)malloc(sizeof(PhoneNode));
	p = P;
	printf("���ͨѶ¼\n");
	ShowPhoneNode(P);
	printf("������ɾ����ϵ�˵�����\n");
	cin >> name;
	while (p)
	{
		if (strcmp(name, p->name) == 0)
		{
			printf("ɾ����ϵ�˵�����:%s", p->name);
			printf("�绰���룺%s\n", p->number);
			q->next = p->next;
			free(p);
			break;
		}
		else
		{
			q = p;
			p = p->next;
		}

	}
	return 1;
}
int  Changenumber(PhoneList& P)
{
	PhoneList p, q;
	char name[20];
	p = (PhoneList)malloc(sizeof(PhoneNode));
	q = (PhoneList)malloc(sizeof(PhoneNode));
	p = P;
	printf("���ͨѶ¼\n");
	ShowPhoneNode(P);
	printf("�����������ϵ�˵�����\n");
	cin >> name;
	while (p)
	{
		if (strcmp(name, p->name) == 0)
		{
			printf("��������ĵĵ绰����\n");
			cin >> p->number;
			if (strlen(q->number) == 11)
			{
				printf("��������ĺ����Ϣ\n");
				printf("��ϵ�˵�������%s", p->name);
				printf("\t�绰���룺%s\n", p->number);
				break;
			}
			else
			{
				printf("����ĸ���,����������!\n");
				Changenumber(P);
			}

		}
		else
		{
			q = p;
			p = p->next;
		}
	}
	return 1;
}
int  ShowPhoneNode(PhoneList P)
{
	PhoneList p;
	p = (PhoneList)malloc(sizeof(PhoneNode));
	p = P->next;
	while (p)
	{
		printf("��ϵ�˵�������%s", p->name);
		printf("\t�绰���룺%s\n", p->number);
		p = p->next;
	}
	return 1;
}
