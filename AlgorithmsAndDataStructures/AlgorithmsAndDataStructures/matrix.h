#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
#define MAXSIZE 200

typedef struct {
	int i, j;//iΪ�У�jΪ��
	int e;//i��j�д�������Ϊe
}Triple;//��Ԫ��ṹ�壬����ϡ�����ṹ����
typedef struct {
	Triple data[MAXSIZE];//����Ԫ��Ԫ���
	int mu, nu, tu;//�������������������������з���Ԫ����
}TSMatrix;


//1.��������
void CreatTriple(TSMatrix& T)
{
	int m, n, t;
	cout << "������������";
	cin >> m;
	cout << "������������";
	cin >> n;
	cout << "�������0Ԫ������";
	cin >> t;
	int i, j, e, p = 0;
	cout << "��������Ԫ����ʾϡ�����" << endl;
	while (p < t)//ѭ��t��������Ԫ������
	{
		cout << "���������Ԫ���� �� ֵ" << endl;
		cin >> i >> j >> e;
		if (e != 0)//�������ķ���Ԫ��ֵ��Ϊ��ͽ�����Ԫ���
		{
			T.data[p].i=i;
			T.data[p].j = j;
			T.data[p].e = e;
			p++;
		}
		else//�������ķ���Ԫ��ֵΪ��
		{
			cout << "����Ԫ��ֵ����Ϊ0������������" << endl;;
			continue;
		}
	}
	T.mu = m; T.nu = n; T.tu = t;//��Ԫ���¼����ϣ��������� �� ����Ԫ����ͬ��
}


//2.��ʾ����
void ShowMatrix(TSMatrix T)
{
	if (T.tu <= 0)//����������Ԫ��Ϊ0
	{
		cout << "����һ���վ���" << endl;
		return ;
	}
	cout << "����Ϊ��" << endl;
	int p = 0;
	for (int i = 0; i < T.mu; i++)//˫��forѭ����������
	{
		for (int j = 0; j < T.nu; j++)
		{
			if (T.data[p].i == i && T.data[p].j == j)//�����Ԫ���д���ķ���Ԫ��������������Ķ�Ӧ�Ļ���������÷���Ԫ��ֵ
			{
				cout << T.data[p].e << "    ";
				++p;
			}
			else cout << "0" << "    ";//��������0
		}
		cout << endl;
	}
	
}


//3.����˷�
void MulMatrix(TSMatrix& matrix1, TSMatrix& matrix2, TSMatrix& result)
{
	int i1=0, j1=0, k1 = 0;
	int q;
	if (matrix1.nu != matrix2.mu)
		cout << "ǰһ����������������ں�һ�����������" << endl;
	result.mu = matrix1.mu;//����������������ǰһ����˾��������
	result.nu = matrix2.nu;//���������������ں�һ����˾��������
	for ( k1 = 0; k1 < matrix1.mu * matrix2.nu; k1++)//��ʼ���������
	{
		result.data[k1].e = 0;
	}
	k1 = 0;
	while(i1<matrix1.tu)//��ǰһ�������ڷ���Ԫ��û������ʱ����while�ڲ���
	{
		for (j1 = 0; j1 < matrix2.tu; j1++)//������һ����˾����ÿһ������Ԫ
		{
			if (matrix1.data[i1].j == matrix2.data[j1].i)//ǰһ������ķ���Ԫ���е��ں�һ������ķ���Ԫ����ʱ
			{
				result.data[k1].i = matrix1.data[i1].i;//��������н������Ԫ����Ϊǰһ������ķ���Ԫ����
				result.data[k1].j = matrix2.data[j1].j;//��������н������Ԫ����Ϊ��һ������ķ���Ԫ����
				result.data[k1].e = matrix1.data[i1].e* matrix2.data[j1].e;//�������÷���Ԫ��ֵΪ�������
				for (q = 0; q < k1; q++)//ÿ�ζ�Ҫ�ж��Ƿ�ǰһ�γ˳��ķ���Ԫ��֮ǰ��λ�ó�ͻ
				{
					if (result.data[k1].i == result.data[q].i && result.data[k1].j == result.data[q].j)
					{
						result.data[q].e += result.data[k1].e;//����г�ͻ����ǰ���ֵ���
						k1--;//��ʱ����ǰ�����β����ķ���Ԫ��ͬһ��λ�õģ����Է���Ԫ���������ӣ��˴�--���������++���ﵽ�����ӵ�Ч����
					}
				}
				k1++;
			}
		}
		i1++;
	}
	result.tu = k1;
}
