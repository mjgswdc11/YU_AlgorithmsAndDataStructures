#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
#define MAXSIZE 200

typedef struct {
	int i, j;//i为行，j为列
	int e;//i行j列储存数据为e
}Triple;//三元组结构体，用于稀疏矩阵结构体中
typedef struct {
	Triple data[MAXSIZE];//非零元三元组表
	int mu, nu, tu;//矩阵行数，矩阵列数，矩阵中非零元个数
}TSMatrix;


//1.创建矩阵
void CreatTriple(TSMatrix& T)
{
	int m, n, t;
	cout << "请输入行数：";
	cin >> m;
	cout << "请输入列数：";
	cin >> n;
	cout << "请输入非0元个数：";
	cin >> t;
	int i, j, e, p = 0;
	cout << "请输入三元组表表示稀疏矩阵：" << endl;
	while (p < t)//循环t次输入三元组数据
	{
		cout << "请输入非零元的行 列 值" << endl;
		cin >> i >> j >> e;
		if (e != 0)//如果输入的非零元的值不为零就进入三元组表
		{
			T.data[p].i=i;
			T.data[p].j = j;
			T.data[p].e = e;
			p++;
		}
		else//如果输入的非零元的值为零
		{
			cout << "非零元的值不能为0，请重新输入" << endl;;
			continue;
		}
	}
	T.mu = m; T.nu = n; T.tu = t;//三元组表录入完毕，将矩阵行 列 非零元个数同步
}


//2.显示矩阵
void ShowMatrix(TSMatrix T)
{
	if (T.tu <= 0)//如果矩阵非零元数为0
	{
		cout << "这是一个空矩阵" << endl;
		return ;
	}
	cout << "矩阵为：" << endl;
	int p = 0;
	for (int i = 0; i < T.mu; i++)//双层for循环遍历矩阵
	{
		for (int j = 0; j < T.nu; j++)
		{
			if (T.data[p].i == i && T.data[p].j == j)//如果三元表中储存的非零元行列数与遍历到的对应的话，就输出该非零元的值
			{
				cout << T.data[p].e << "    ";
				++p;
			}
			else cout << "0" << "    ";//否则就输出0
		}
		cout << endl;
	}
	
}


//3.矩阵乘法
void MulMatrix(TSMatrix& matrix1, TSMatrix& matrix2, TSMatrix& result)
{
	int i1=0, j1=0, k1 = 0;
	int q;
	if (matrix1.nu != matrix2.mu)
		cout << "前一个矩阵的列数不等于后一个矩阵的行数" << endl;
	result.mu = matrix1.mu;//结果矩阵的行数等于前一个相乘矩阵的行数
	result.nu = matrix2.nu;//结果矩阵的列数等于后一个相乘矩阵的列数
	for ( k1 = 0; k1 < matrix1.mu * matrix2.nu; k1++)//初始化结果矩阵
	{
		result.data[k1].e = 0;
	}
	k1 = 0;
	while(i1<matrix1.tu)//当前一个矩阵内非零元还没遍历完时继续while内操作
	{
		for (j1 = 0; j1 < matrix2.tu; j1++)//遍历后一个相乘矩阵的每一个非零元
		{
			if (matrix1.data[i1].j == matrix2.data[j1].i)//前一个矩阵的非零元的列等于后一个矩阵的非零元的行时
			{
				result.data[k1].i = matrix1.data[i1].i;//结果矩阵中结果非零元的行为前一个矩阵的非零元的行
				result.data[k1].j = matrix2.data[j1].j;//结果矩阵中结果非零元的列为后一个矩阵的非零元的列
				result.data[k1].e = matrix1.data[i1].e* matrix2.data[j1].e;//结果矩阵该非零元的值为两者相乘
				for (q = 0; q < k1; q++)//每次都要判断是否前一次乘出的非零元与之前的位置冲突
				{
					if (result.data[k1].i == result.data[q].i && result.data[k1].j == result.data[q].j)
					{
						result.data[q].e += result.data[k1].e;//如果有冲突就让前后的值相加
						k1--;//这时由于前后两次操作的非零元是同一个位置的，所以非零元个数不增加（此次--抵消后面的++，达到不增加的效果）
					}
				}
				k1++;
			}
		}
		i1++;
	}
	result.tu = k1;
}
