#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

//栈的结构体定义
typedef struct {
	char* base;
	char* top;
	int stacksize;
}SqStack;


//初始化栈
void InitStack(SqStack& S)
{
	//构建一个空栈S
	S.base = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
	if (!S.base)
	{
		cout << "存储分配失败" << endl;
		exit(-2);
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return;
}


//1.进栈
void Push(SqStack& S, char e)
{
	//插入元素e为新的栈顶元素
	if (S.top - S.base >= S.stacksize)
	{
		//栈满，追加存储空间
		S.base = (char*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(char));
		if (!S.base)
		{
			cout << "存储分配失败" << endl;
			exit(-2);
		}
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	
	return;
}


//2.出栈
void Pop(SqStack &S,char &e)
{
	// 若栈为空，则打印错误信息，否则删除栈顶元素,用e返回其值
	if (S.top == S.base)cout << "栈为空栈，删除错误!!!" << endl;
	else
	{
		e=* --S.top;
		
	}
	
}


//3.取栈顶元素
void GetTop(SqStack S,char &e)
{
	//若栈不空则返回栈顶元素，否则返回null
	if (S.top == S.base)
	{
		cout << "栈为空，无栈顶元素！！！" << endl;
		e=NULL;
	}
	e = *(S.top - 1);
}

char GetTop(SqStack S)
{
	//若栈不空则返回栈顶元素，否则返回null
	if (S.top == S.base)
	{
		cout << "栈为空，无栈顶元素！！！" << endl;
		return '#';
	}
	return *(S.top - 1);
}

//4.表达式求值
//运算符集合
const char OP[7] = { '+','-','*','/','(',')','#' };

//In方法判断形参ch是否是运算符集合OP的一员
bool In(char ch)
{
	for (int i = 0; i < 7; i++)
	{
		if (ch == OP[i])
			return true;
	}
	return false;
}

//Precede函数比较两个形参的运算符优先级
char Precede(char a, char b)
{
	if ((a == '(' && b == ')') || (a == '#' && b == '#'))
	{
		return '=';
	}
	else if (a == '(' || a == '#' || b == '(' || (a == '+' || a == '-') && (b == '*' || b == '/'))
	{
		return '<';
	}
	else
		return '>';
}

//Operate函数用于进行两数的计算，因为计算后还要入OPND栈，所以返回类型是char
char Operate(char a, char theta,char b)
{
	switch (theta) {
	case '+':
		return (a - '0') + (b - '0') + 48;
	case '-':
		return (a - '0') - (b - '0') + 48;
	case '*':
		return (a - '0') * (b - '0') + 48;
	case '/':
		return (a - '0') / (b - '0') + 48;
	}
	return 0;
}


//表达式求值主要算法
char EvaluateExpression()
{
	SqStack OPTR,OPND;//OPTR：运算符栈，OPND：操作数栈
	char c,x,theta,b,a;
	InitStack(OPTR);
	InitStack(OPND);//初始化
	Push(OPTR, '#');//将表达式起始符'#'入OPTR栈
	c = getchar();
	while (c != '#' || GetTop(OPTR) != '#')
	{
		if (!In(c))//c不是运算符就进操作数栈
		{
			Push(OPND,c);
			c=getchar();
		}
		else
			switch (Precede(GetTop(OPTR), c))//比较OPTR栈顶元素和新输入的运算符c的优先级
			{
			case '<'://栈顶元素优先级较低
				Push(OPTR, c);//新输入的运算符c入运算符栈
				c = getchar();
				break;
			case '='://栈顶元素为'('而新输入的运算符c为')'
				Pop(OPTR, x);
				c = getchar();
				break;
			case '>'://优先级较低，可以进行计算了
				Pop(OPTR ,theta);
				Pop(OPND, b);
				Pop(OPND, a);
				Push(OPND, Operate(a, theta, b));
				break;
			}
	}
	return GetTop(OPND);
}