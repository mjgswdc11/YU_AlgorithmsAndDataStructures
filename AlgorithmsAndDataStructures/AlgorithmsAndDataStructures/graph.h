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
	AdjMatrix arcs;//邻接矩阵
	int v, a;//顶点数和弧数
	GraphKind kind;
}MGraph;
status adjloction(MGraph G, char v)
{
	for (int i = 0; i < G.v; i++)
		if (G.vexs[i] == v)
			return i;
	return -1;
}
//创建无向图
void CreateUDG(MGraph& G)
{
	char v1, v2;
	G = *(MGraph*)malloc(sizeof(MGraph));
	cout << "请输入顶点数和弧数" << endl;
	cin >> G.v >> G.a;
	cout << "请输入顶点" << endl;
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
	cout << "请输入弧" << endl;
	for (int k = 0; k < G.a; k++)
	{
		cin >> v1 >> v2;
		m = adjloction(G, v1);
		n = adjloction(G, v2);
		G.arcs[m][n].adj = 1;
		G.arcs[n][m].adj = G.arcs[m][n].adj;
	}
}
// 创建有向图
void CreateDG(MGraph& G)
{
	char v1, v2;  // 定义有向边的起点和终点
	G = *(MGraph*)malloc(sizeof(MGraph)); // 动态分配内存并将指针赋值给图的结构类型变量 G
	cout << "请输入顶点数和弧数" << endl;  // 提示用户输入顶点数和有向边数 
	cin >> G.v >> G.a;  // 获取用户输入的顶点数据编号和有向边数
	cout << "请输入顶点" << endl;  // 提示用户输入每个顶点的名称
	for (int i = 0; i < G.v; i++)  // 循环获取每个顶点的名称，并存储到结构体 G 的 vexs 数组中
	{
		cin >> G.vexs[i];
	}
	for (int i = 0; i < G.v; i++)
	{
		for (int j = 0; j < G.v; j++)
		{
			G.arcs[i][j] = { 0,NULL };  // 初始化邻接矩阵，使其中的元素都为0
		}
	}
	int m, n;
	cout << "请输入弧" << endl;  // 提示用户输入有向边的信息
	for (int k = 0; k < G.a; k++)
	{
		cin >> v1 >> v2;  // 输入有向边的起点和终点
		m = adjloction(G, v1);  // 查找该有向边的起点在结构体 G 中的位置，并将其赋值给整形变量 m
		n = adjloction(G, v2);  // 查找该有向边的终点在结构体 G 中的位置，并将其赋值给整形变量 n
		G.arcs[m][n].adj = 1;  // 在邻接矩阵中记录该有向边的信息，这里暂时仅记录是否存在有向边（1为有向边，0为无向边）
	}
}
//创建无向网
void CreateUDN(MGraph& G)
{
	char v1, v2;
	int v3;                     // 增加了一个变量v3，表示边的权重
	G = *(MGraph*)malloc(sizeof(MGraph));  // 分配空间

	cout << "请输入顶点数和弧数" << endl;
	cin >> G.v >> G.a;           // 输入节点和边的数量

	cout << "请输入顶点" << endl;
	for (int i = 0; i < G.v; i++)   // 输入每个节点的信息
	{
		cin >> G.vexs[i];
	}

	// 初始化邻接矩阵
	for (int i = 0; i < G.v; i++)
	{
		for (int j = 0; j < G.a; j++)
		{
			G.arcs[i][j] = { 0,NULL };
		}
	}

	int m, n;
	cout << "请输入弧和权值" << endl;
	for (int k = 0; k < G.a; k++)    // 输入每一条边及其权重
	{
		cin >> v1 >> v2 >> v3;        // 在输入中增加了权重的信息
		m = adjloction(G, v1);
		n = adjloction(G, v2);

		// 根据无向图的定义，在邻接矩阵中将两个方向的权重都设置为v3
		G.arcs[m][n].adj = G.arcs[n][m].adj = v3;
	}
}

//创建有向网
void CreateDN(MGraph& G)
{
	char v1, v2;
	int v3;
	//申请结构体内存空间，并初始化
	G = *(MGraph*)malloc(sizeof(MGraph));
	cout << "请输入顶点数和弧数" << endl;        //输入顶点数和弧数
	cin >> G.v >> G.a;
	cout << "请输入顶点" << endl;                //输入每个结点的名称
	for (int i = 0; i < G.v; i++)
	{
		cin >> G.vexs[i];
	}
	//初始化邻接矩阵
	for (int i = 0; i < G.v; i++)
	{
		for (int j = 0; j < G.a; j++)
		{
			G.arcs[i][j] = { 0,NULL };
		}
	}
	int m, n;
	cout << "请输入弧和权值" << endl;           //输入每条弧连接的两个结点名称以及其对应的权值
	for (int k = 0; k < G.a; k++)
	{
		cin >> v1 >> v2 >> v3;
		m = adjloction(G, v1);
		n = adjloction(G, v2);
		G.arcs[m][n].adj = v3;                  //将对应弧的起点、终点及其权值存储进邻接矩阵中
	}
}
//标记访问数组
int visited[MAX_NUM];
//初始化访问标签数组
void InitVisited()
{
	for (int i = 0; i < MAX_NUM; i++)
	{
		visited[i] = 0;
	}
}
//深度优先遍历
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
//广度优先遍历
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
//打印邻接矩阵
void PrintG(MGraph G)
{
	cout << "输出邻接矩阵" << endl;
	for (int i = 0; i < G.v; i++)
	{
		for (int j = 0; j < G.v; j++)
		{
			cout << "  " << G.arcs[i][j].adj;
		}
		cout << endl;
	}
}
