#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
typedef struct PhoneNode
{
	char name[20];//��ϵ����
	char number[20];//�绰
	struct PhoneNode* next;//ָ����һ����
}*PhoneList, PhoneNode;
int Create(PhoneList& P);//��ʼ�������ͷ�ڵ�
int CreatPhoneNode(PhoneList& P);//�洢��ϵ��
int SerachPeople(PhoneList& P);//������ϵ��
int DeletePeople(PhoneList& P);//ɾ����ϵ��
int Changenumber(PhoneList& P);//������ϵ�˵ĺ���
int ShowPhoneNode(PhoneList  P);//���ͨѶ¼

