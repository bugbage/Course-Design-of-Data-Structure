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
int In(char c); //判断是否为运算符，是运算符返回1，若不是返回0
int evaluateExpression(char exp[]);
