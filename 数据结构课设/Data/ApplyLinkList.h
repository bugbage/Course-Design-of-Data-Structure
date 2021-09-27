#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
typedef struct PhoneNode
{
	char name[20];//联系人名
	char number[20];//电话
	struct PhoneNode* next;//指向下一个人
}*PhoneList, PhoneNode;
int Create(PhoneList& P);//初始化链表的头节点
int CreatPhoneNode(PhoneList& P);//存储联系人
int SerachPeople(PhoneList& P);//查找联系人
int DeletePeople(PhoneList& P);//删除联系人
int Changenumber(PhoneList& P);//更改联系人的号码
int ShowPhoneNode(PhoneList  P);//输出通讯录

