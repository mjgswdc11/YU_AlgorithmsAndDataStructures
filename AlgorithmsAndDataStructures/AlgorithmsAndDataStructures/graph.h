#pragma once
#include<stdlib.h>
#include<iostream>
#include<queue>
#include"stack.h"
#define MAX_NUM 30
using namespace std;
typedef int status;
typedef enum { DG, UDG, DN, UDN }GraphKind;
typedef struct AreCell {
	int adj;
	int* info;
}AreCell, AdjMatrix[MAX_NUM][MAX_NUM];
typedef struct MGraph {
	char vexs[MAX_NUM];
	AdjMatrix arcs;//�ڽӾ���
	int v, a;//�������ͻ���
	GraphKind kind;
}MGraph;
status adjloction(MGraph G, char v)
{
	for (int i = 0; i < G.v; i++)
		if (G.vexs[i] == v)
			return i;
	return -1;
}
//��������ͼ
void CreateUDG(MGraph& G)
{
	char v1, v2;
	G = *(MGraph*)malloc(sizeof(MGraph));
	cout << "�����붥�����ͻ���" << endl;
	cin >> G.v >> G.a;
	cout << "�����붥��" << endl;
	for (int i = 0; i < G.v; i++)
	{
		cin >> G.vexs[i];
	}
	for (int i = 0; i < G.v; i++)
	{
		for (int j = 0; j < G.a; j++)
		{
			G.arcs[i][j] = { 0,NULL };
		}
	}
	int m, n;
	cout << "�����뻡" << endl;
	for (int k = 0; k < G.a; k++)
	{
		cin >> v1 >> v2;
		m = adjloction(G, v1);
		n = adjloction(G, v2);
		G.arcs[m][n].adj = 1;
		G.arcs[n][m].adj = G.arcs[m][n].adj;
	}
}
// ��������ͼ
void CreateDG(MGraph& G)
{
	char v1, v2;  // ��������ߵ������յ�
	G = *(MGraph*)malloc(sizeof(MGraph)); // ��̬�����ڴ沢��ָ�븳ֵ��ͼ�Ľṹ���ͱ��� G
	cout << "�����붥�����ͻ���" << endl;  // ��ʾ�û����붥������������� 
	cin >> G.v >> G.a;  // ��ȡ�û�����Ķ������ݱ�ź��������
	cout << "�����붥��" << endl;  // ��ʾ�û�����ÿ�����������
	for (int i = 0; i < G.v; i++)  // ѭ����ȡÿ����������ƣ����洢���ṹ�� G �� vexs ������
	{
		cin >> G.vexs[i];
	}
	for (int i = 0; i < G.v; i++)
	{
		for (int j = 0; j < G.v; j++)
		{
			G.arcs[i][j] = { 0,NULL };  // ��ʼ���ڽӾ���ʹ���е�Ԫ�ض�Ϊ0
		}
	}
	int m, n;
	cout << "�����뻡" << endl;  // ��ʾ�û���������ߵ���Ϣ
	for (int k = 0; k < G.a; k++)
	{
		cin >> v1 >> v2;  // ��������ߵ������յ�
		m = adjloction(G, v1);  // ���Ҹ�����ߵ�����ڽṹ�� G �е�λ�ã������丳ֵ�����α��� m
		n = adjloction(G, v2);  // ���Ҹ�����ߵ��յ��ڽṹ�� G �е�λ�ã������丳ֵ�����α��� n
		G.arcs[m][n].adj = 1;  // ���ڽӾ����м�¼������ߵ���Ϣ��������ʱ����¼�Ƿ��������ߣ�1Ϊ����ߣ�0Ϊ����ߣ�
	}
}
//����������
void CreateUDN(MGraph& G)
{
	char v1, v2;
	int v3;                     // ������һ������v3����ʾ�ߵ�Ȩ��
	G = *(MGraph*)malloc(sizeof(MGraph));  // ����ռ�

	cout << "�����붥�����ͻ���" << endl;
	cin >> G.v >> G.a;           // ����ڵ�ͱߵ�����

	cout << "�����붥��" << endl;
	for (int i = 0; i < G.v; i++)   // ����ÿ���ڵ����Ϣ
	{
		cin >> G.vexs[i];
	}

	// ��ʼ���ڽӾ���
	for (int i = 0; i < G.v; i++)
	{
		for (int j = 0; j < G.a; j++)
		{
			G.arcs[i][j] = { 0,NULL };
		}
	}

	int m, n;
	cout << "�����뻡��Ȩֵ" << endl;
	for (int k = 0; k < G.a; k++)    // ����ÿһ���߼���Ȩ��
	{
		cin >> v1 >> v2 >> v3;        // ��������������Ȩ�ص���Ϣ
		m = adjloction(G, v1);
		n = adjloction(G, v2);

		// ��������ͼ�Ķ��壬���ڽӾ����н����������Ȩ�ض�����Ϊv3
		G.arcs[m][n].adj = G.arcs[n][m].adj = v3;
	}
}

//����������
void CreateDN(MGraph& G)
{
	char v1, v2;
	int v3;
	//����ṹ���ڴ�ռ䣬����ʼ��
	G = *(MGraph*)malloc(sizeof(MGraph));
	cout << "�����붥�����ͻ���" << endl;        //���붥�����ͻ���
	cin >> G.v >> G.a;
	cout << "�����붥��" << endl;                //����ÿ����������
	for (int i = 0; i < G.v; i++)
	{
		cin >> G.vexs[i];
	}
	//��ʼ���ڽӾ���
	for (int i = 0; i < G.v; i++)
	{
		for (int j = 0; j < G.a; j++)
		{
			G.arcs[i][j] = { 0,NULL };
		}
	}
	int m, n;
	cout << "�����뻡��Ȩֵ" << endl;           //����ÿ�������ӵ�������������Լ����Ӧ��Ȩֵ
	for (int k = 0; k < G.a; k++)
	{
		cin >> v1 >> v2 >> v3;
		m = adjloction(G, v1);
		n = adjloction(G, v2);
		G.arcs[m][n].adj = v3;                  //����Ӧ������㡢�յ㼰��Ȩֵ�洢���ڽӾ�����
	}
}
//��Ƿ�������
int visited[MAX_NUM];
//��ʼ�����ʱ�ǩ����
void InitVisited()
{
	for (int i = 0; i < MAX_NUM; i++)
	{
		visited[i] = 0;
	}
}
//������ȱ���
void DFS(MGraph G, int v)
{
	if (visited[v] == 0)
	{
		printf("%c", G.vexs[v]);
		visited[v] = 1;
	}
	for (int k = 0; k < G.v; k++)
	{
		if ((G.arcs[v][k].adj != 0) && (!visited[k]))
			DFS(G, k);
	}
	for (int i = 0; i < G.v; i++)
	{
		if (visited[i] == 0)
			DFS(G, v - 1);
	}
}
//������ȱ���
void BFS(MGraph G, int v)
{
	queue<int>Q;
	if (visited[v] == 0)
	{
		printf("%c", G.vexs[v]);
		visited[v] = 1;
		Q.push(v);
	}
	while (!Q.empty())
	{
		int vex = Q.front();
		Q.pop();
		for (int i = 0; i <G.v; i++)
		{
			if (G.arcs[vex][i].adj != 0 && (visited[i] == 0))
			{
				printf("%c", G.vexs[i]);
				visited[i] = 1;
				Q.push(i);
			}
		}
	}
}
//��ӡ�ڽӾ���
void PrintG(MGraph G)
{
	cout << "����ڽӾ���" << endl;
	for (int i = 0; i < G.v; i++)
	{
		for (int j = 0; j < G.v; j++)
		{
			cout << "  " << G.arcs[i][j].adj;
		}
		cout << endl;
	}
}
