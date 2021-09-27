#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include<string.h>
#define Maxsize 100
typedef int dataType;
typedef struct Stack
{
	dataType* top;
	dataType* base;
	int stacksize;
}sqstack;
void create(sqstack* s);
int push_in(sqstack* s, dataType value);
int pop_out(sqstack* s, dataType* elem);
dataType GetTop(sqstack* s);
char Precede(char theta1, char theta2);
int Operate(int a, char theta, int b);
int In(char c); //�ж��Ƿ�Ϊ������������������1�������Ƿ���0
int evaluateExpression(char exp[]);
