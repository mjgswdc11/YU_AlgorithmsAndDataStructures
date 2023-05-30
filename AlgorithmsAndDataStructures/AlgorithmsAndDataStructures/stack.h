#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

//ջ�Ľṹ�嶨��
typedef struct {
	char* base;
	char* top;
	int stacksize;
}SqStack;


//��ʼ��ջ
void InitStack(SqStack& S)
{
	//����һ����ջS
	S.base = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
	if (!S.base)
	{
		cout << "�洢����ʧ��" << endl;
		exit(-2);
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return;
}


//1.��ջ
void Push(SqStack& S, char e)
{
	//����Ԫ��eΪ�µ�ջ��Ԫ��
	if (S.top - S.base >= S.stacksize)
	{
		//ջ����׷�Ӵ洢�ռ�
		S.base = (char*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(char));
		if (!S.base)
		{
			cout << "�洢����ʧ��" << endl;
			exit(-2);
		}
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	
	return;
}


//2.��ջ
void Pop(SqStack &S,char &e)
{
	// ��ջΪ�գ����ӡ������Ϣ������ɾ��ջ��Ԫ��,��e������ֵ
	if (S.top == S.base)cout << "ջΪ��ջ��ɾ������!!!" << endl;
	else
	{
		e=* --S.top;
		
	}
	
}


//3.ȡջ��Ԫ��
void GetTop(SqStack S,char &e)
{
	//��ջ�����򷵻�ջ��Ԫ�أ����򷵻�null
	if (S.top == S.base)
	{
		cout << "ջΪ�գ���ջ��Ԫ�أ�����" << endl;
		e=NULL;
	}
	e = *(S.top - 1);
}

char GetTop(SqStack S)
{
	//��ջ�����򷵻�ջ��Ԫ�أ����򷵻�null
	if (S.top == S.base)
	{
		cout << "ջΪ�գ���ջ��Ԫ�أ�����" << endl;
		return '#';
	}
	return *(S.top - 1);
}

//4.���ʽ��ֵ
//���������
const char OP[7] = { '+','-','*','/','(',')','#' };

//In�����ж��β�ch�Ƿ������������OP��һԱ
bool In(char ch)
{
	for (int i = 0; i < 7; i++)
	{
		if (ch == OP[i])
			return true;
	}
	return false;
}

//Precede�����Ƚ������βε���������ȼ�
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

//Operate�������ڽ��������ļ��㣬��Ϊ�����Ҫ��OPNDջ�����Է���������char
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


//���ʽ��ֵ��Ҫ�㷨
char EvaluateExpression()
{
	SqStack OPTR,OPND;//OPTR�������ջ��OPND��������ջ
	char c,x,theta,b,a;
	InitStack(OPTR);
	InitStack(OPND);//��ʼ��
	Push(OPTR, '#');//�����ʽ��ʼ��'#'��OPTRջ
	c = getchar();
	while (c != '#' || GetTop(OPTR) != '#')
	{
		if (!In(c))//c����������ͽ�������ջ
		{
			Push(OPND,c);
			c=getchar();
		}
		else
			switch (Precede(GetTop(OPTR), c))//�Ƚ�OPTRջ��Ԫ�غ�������������c�����ȼ�
			{
			case '<'://ջ��Ԫ�����ȼ��ϵ�
				Push(OPTR, c);//������������c�������ջ
				c = getchar();
				break;
			case '='://ջ��Ԫ��Ϊ'('��������������cΪ')'
				Pop(OPTR, x);
				c = getchar();
				break;
			case '>'://���ȼ��ϵͣ����Խ��м�����
				Pop(OPTR ,theta);
				Pop(OPND, b);
				Pop(OPND, a);
				Push(OPND, Operate(a, theta, b));
				break;
			}
	}
	return GetTop(OPND);
}