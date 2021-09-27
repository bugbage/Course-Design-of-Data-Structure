#include"ApplyLinkList.h"

int  Create(PhoneList& P)
{
	P = (PhoneList)malloc(sizeof(PhoneNode));
	P->next = NULL;
	char name[] = "通讯录";
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
	printf("请输入联系人的姓名、电话\n");
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
		printf("输入的电话号有误，请重新输入\n");
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
	printf("请输入要查找的联系人姓名\n");
	cin >> name;
	while (p)
	{
		if (strcmp(name, p->name) == 0)
		{
			printf("联系人的姓名:%s\n", p->name);
			printf("电话号码：%s\n", p->number);
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
	printf("输出通讯录\n");
	ShowPhoneNode(P);
	printf("请输入删除联系人的姓名\n");
	cin >> name;
	while (p)
	{
		if (strcmp(name, p->name) == 0)
		{
			printf("删除联系人的姓名:%s", p->name);
			printf("电话号码：%s\n", p->number);
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
	printf("输出通讯录\n");
	ShowPhoneNode(P);
	printf("请输入更改联系人的姓名\n");
	cin >> name;
	while (p)
	{
		if (strcmp(name, p->name) == 0)
		{
			printf("请输入更改的电话号码\n");
			cin >> p->number;
			if (strlen(q->number) == 11)
			{
				printf("请输出更改后的信息\n");
				printf("联系人的姓名：%s", p->name);
				printf("\t电话号码：%s\n", p->number);
				break;
			}
			else
			{
				printf("错误的更改,请重新输入!\n");
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
		printf("联系人的姓名：%s", p->name);
		printf("\t电话号码：%s\n", p->number);
		p = p->next;
	}
	return 1;
}
