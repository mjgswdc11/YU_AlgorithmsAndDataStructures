#include<stdio.h>
#include"linklist.h"//包含单链表操作的头文件
#include"stack.h"//包含栈操作的头文件
#include"matrix.h"//包含稀疏矩阵操作的头文件
#include "bitree.h"//包含树操作的头文件
#include"graph.h"//包含图操作的头文件
#include"topo.h"//包含拓扑序列操作的头文件
#include"mstree.h"//包含最小生成树操作的头文件


using namespace std;
void ShowMainMenu() {
	printf("\n");
	printf("*******************算法与数据结构******************\n");
	printf("* 1  单链表的基本操作及应用                       *\n");
	printf("* 2  栈的基本操作及应用                           *\n");
	printf("* 3  数组的基本操作及应用                         *\n");
	printf("* 4  树的基本操作及应用                           *\n");
	printf("* 5  图的基本操作及应用                           *\n");
	printf("* 6  退出                                         *\n");
	printf("***************************************************\n");
}

void LinkList() {
	int n;
	List L;//初始化用到的
	L = (LNode*)malloc(sizeof(LNode));
	do {
		printf("\n");
		printf("**************单链表的基本操作及应用***************\n");
		printf("* 1  创建                                         *\n");
		printf("* 2  插入                                         *\n");
		printf("* 3  删除                                         *\n");
		printf("* 4  查找                                         *\n");
		printf("* 5  显示                                         *\n");
		printf("* 6  通讯录（应用）                               *\n");
		printf("* 7  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf_s("%d", &n);
		int num = 0;
		int pos=0;
		int ele=0;
		switch (n) {
		case 1:
			printf("--------创建单链表---------"); 
			cout << endl;
			L->next = NULL;
			cout << "请输入数据个数："<<endl;
			cin >> num;
			cout << "请逆序输入数据：" << endl;
			L = CreatList(L, num);
			cout << "创建单链表操作成功" << endl;
			break;
		case 2:
			printf("--------插入元素-------"); 
			cout << endl;
			cout << "开始在pos位置插入元素ele" << endl;
			cout << "请输入pos的值：" << endl;cin >> pos;
			cout<< "请输入ele的值：" <<endl;cin >> ele;
			ListInsert(L, pos, ele);
			cout << "插入元素操作完成" << endl;
			break;
		case 3:
			printf("--------删除元素-------"); 
			cout << endl;
			cout << "开始在pos位置删除" << endl;
			cout << "请输入pos的值：" << endl; cin >> pos;
			cout<<"删除的值是："<<ListDelete(L, pos)<<endl;
			cout << "删除元素操作完成" << endl;
			break;
		case 4:
			printf("--------查找元素-------"); 
			cout << endl;
			cout << "开始在pos位置查找" << endl;
			cout << "请输入pos的值："<<endl;cin >> pos;
			cout<<"查找的值为：" << GetElem(L,pos) << endl;
			cout << "查找元素操作完成" << endl;
			break;
		case 5:
			printf("--------显示链表-------"); 
			cout << endl;
			PrintList(L);
			cout << "显示链表操作完成！" << endl;
			break;
		case 6:
			printf("--------通讯录---------"); 
			cout << endl;
			PhoneBook();
			break;
		case 7: break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 7);
}

void Stack() {
	SqStack S;
	int n;
    InitStack(S);
	do {
		printf("\n");
		printf("****************栈的基本操作及应用*****************\n");
		printf("* 1  进栈                                         *\n");
		printf("* 2  出栈                                         *\n");
		printf("* 3  取栈顶元素                                   *\n");
		printf("* 4  表达式求解（应用）                           *\n");
		printf("* 5  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("--------进栈-------"); 
			cout << endl;
			char e1;
			cout << "请输入进栈数据：（char类型）" << endl;
			cin >> e1;
			Push(S, e1);
			cout << "进栈成功" << endl;
			cout << "进栈操作完成" << endl;
			break;
		case 2:
			printf("--------出栈-------"); 
			cout << endl;
			char e2;
			Pop(S,e2);
			cout << "出栈成功" << endl;
			cout << "出栈元素为："<<e2 << endl;
			break;
		case 3:
			printf("--------取栈顶元素-------"); 
			cout << endl;
			char e3;
			GetTop(S, e3);
			cout << "栈顶元素为：" << e3 << endl;
			break;
		case 4:
			printf("--------表达式求值-------"); 
			cout << endl;
			cout << "请一次性输完式子，并以’#‘结尾:" << endl;
			cout << "计算结果是：" << EvaluateExpression() - 48 << endl;
			break;
		case 5:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 5);
}


void Array() {
	int n;
	TSMatrix T;
	do {
		printf("\n");
		printf("*************稀疏矩阵的压缩存储及应用**************\n");
		printf("* 1  创建                                         *\n");
		printf("* 2  显示                                         *\n");
		printf("* 3  矩阵乘法（应用）                             *\n");
		printf("* 4  退出                                         *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("---------创建-------"); 
			cout << endl;
			CreatTriple(T);
			cout << "创建完成" << endl;
			break;
		case 2:
			printf("---------显示-------"); 
			cout << endl;
		    ShowMatrix(T);
			cout << "显示操作完成" << endl;
			break;
		case 3:
			printf("---------矩阵乘法-------"); 
			TSMatrix matrix1, matrix2, result;
			cout << "创建第一个矩阵" << endl;
			CreatTriple(matrix1);
			cout << "创建第二个矩阵" << endl;
			CreatTriple(matrix2);
			MulMatrix(matrix1, matrix2, result);
			cout << "相乘后结果为：" << endl;
			ShowMatrix(result);
			break;
		case 4:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 4);
}

void BiTree() {
	BinTree T=NULL;

	int n;
	
	do {
		printf("\n");
		printf("**************二叉树的基本操作及应用***************\n");
		printf("* 1  创建二叉树                                   *\n");
		printf("* 2  遍历二叉树（先/中/后）                       *\n");
		printf("* 3  计算树的深度                                 *\n");
		printf("* 4  计算叶子结点个数                             *\n");
		printf("* 5  查找双亲                                     *\n");
		printf("* 6  查找兄弟                                     *\n");
		printf("* 7  Huffman编码（应用）                          *\n");
		printf("* 8  退出\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("---------创建二叉树--------"); 
			cout << endl;
			cout << "请输入想要创建的二叉树的先序序列（以“#”表示到了一个空节点）：" << endl;
			getchar();
			CreateBinTree(&T);
			cout << "构建二叉树成功" << endl;
			
			break;
		case 2:
			printf("---------*遍历二叉树-------"); 
			cout << endl;
			cout << "先序序列为：" << endl;
			Preorder(T);
			cout << endl;
			cout << "中序序列为：" << endl;
			Inorder(T);
			cout << endl;
			cout << "后序序列为：" << endl;
			Postorder(T);
			cout << endl;
			break;
		case 3:
			printf("---------计算树的深度------");
			cout << endl;
			cout << "该二叉树的深度是：" << PostOrderGetHeight(T) << endl;
			break;
		case 4:
			printf("---------计算叶子结点个数-------");
			cout << endl;
			cout << "该二叉树的叶子结点个数是："<<LeafNodeNum(T) << endl;
			break;
		case 5:
			printf("---------查找双亲-------"); 
			char x;
			cout << endl;
			cout << "请输入想要查询的结点的值（char）类型：" << endl;
			cin >> x;
			cout << "该结点的父结点的值是：" << FindFatherNode(T, x) << endl;
			break;
		case 6:
			printf("---------查找兄弟-------"); 
			cout << endl;
			cout << "请输入想要查询的结点的值（char）类型：" << endl;
			cin >> x;
			cout << "该结点的兄弟结点的值是：" << FindBrotherNode(T, x) << endl;
			break;
		case 7:
		{
            printf("---------Huffman编码-------");
			cout << endl;
			int n;
			cout << "请输入权值个数：";
			cin >> n;

			// 输入每个字符的权值
			vector<pair<char, int>> freq(n);
			cout << "请输入" << n << "个权值：";
			for (int i = 0; i < n; i++) {
				cin >> freq[i].second;
			}

			// 将输入转换为字符数组
			char ch = 'A';
			for (int i = 0; i < n; i++) {
				freq[i].first = ch++;
			}

			// 构建赫夫曼树和赫夫曼编码表
			HuffmanNode* root = buildHuffmanTree(freq);
			unordered_map<char, string> table = generateHuffmanTable(root);

			// 输出赫夫曼编码表
			cout << "赫夫曼编码表如下：" << endl;
			for (const auto& p : table) {
				cout << "权值为" << p.first << "的编码为：" << p.second << endl;
			}

		}
			
		case 8:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 8);
}

void Graph() {
	MGraph G;
	TopoGraph g;
	int n;
	do {
		printf("\n");
		printf("****************图的基本操作及应用*****************\n");
		printf("* 1  创建无向图                                    *\n");
		printf("* 2  创建无向网                                    *\n");
		printf("* 3  创建有向图                                    *\n");
		printf("* 4  创建有向网                                    *\n");
		printf("* 5  遍历                                          *\n");
		printf("* 6  拓扑排序                                      *\n");
		printf("* 7  最小生成树（应用）                            *\n");
		printf("* 8  最短路径（应用）                              *\n");
		printf("* 9  关键路径（应用）                              *\n");
		printf("* 10 退出                                          *\n");
		printf("***************************************************\n");
		printf("请选择：");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("---------创建无向图-------");
			cout << endl;
			CreateUDG(G);
			cout << "该无向图的邻接矩阵表示如下：" << endl;
			PrintG(G);  // 输出邻接矩阵

			break;
		case 2:
			printf("---------创建无向网-------"); 
			cout << endl;
			CreateUDN(G);
			cout << "该无向网的邻接矩阵表示如下：" << endl;
			PrintG(G);  // 输出邻接矩阵

			break;
		case 3:
			printf("---------创建有向图-------"); 
			cout << endl;
			CreateDG(G); // 调用GreateDG函数来生成邻接矩阵表示的有向图G
			cout << "该有向图的邻接矩阵表示如下：" << endl;
			PrintG(G);  // 输出邻接矩阵

			break;
		case 4:
			printf("---------创建有向网-------"); 
			cout << endl;
			CreateDN(G);                                //调用创建有向网函数
			cout << "该有向网的邻接矩阵表示如下：" << endl;//输出这个有向网的邻接矩阵信息
			PrintG(G);  // 输出邻接矩阵


			break;
		case 5:
			printf("---------遍历-------"); 
			cout << endl;
			InitVisited(); // 初始化访问标签数组

			printf("DFS遍历结果：");
			DFS(G, 0);  // 从节点0开始进行深度优先遍历
			printf("\n");

			InitVisited(); // 初始化访问标签数组

			printf("BFS遍历结果：");
			BFS(G, 0);  // 从节点0开始进行广度优先遍历
			printf("\n");
			break;
		case 6:
			printf("---------拓扑排序-------"); 
			cout << endl;
			
			cout << "请输入节点个数和边数：";
			cin >> g.n >> g.e;

			// 为顶点信息数组分配存储空间
			g.v = new VertexNode[g.n];

			// 初始化每一个顶点，包括其入度和第一条边
			for (int i = 0; i < g.n; i++) {
				g.v[i].in_degree = 0;
				g.v[i].first_edge = NULL;
				cout << "请输入节点" << i + 1 << "的数据：";
				cin >> g.v[i].data;
			}

			// 读入边信息并建立邻接表
			for (int k = 0; k < g.e; k++) {
				int i, j, w;
				cout << "请输入边的起点和终点编号以及边权重：";
				cin >> i >> j >> w;

				// 创建一条新边
				EdgeNode* e = new EdgeNode;
				e->to = j;
				e->weight = w;
				e->next = g.v[i].first_edge;

				// 将该边插入到起点的边表头
				g.v[i].first_edge = e;

				// 将j的入度加1
				g.v[j].in_degree++;
			}

			cout << "拓扑排序结果为：";
			TopoSort(g);
			break;
		case 7:
		{
          printf("---------最小生成树-------"); 
		cout << endl;
		int n, m;
		cout << "请输入图中的节点数n和边数m：";
		cin >> n >> m;

		vector<vector<int>> graph(n, vector<int>(n, 0));
		cout << "请输入每条边的两个端点和边权，格式为u v w（其中u、v为0到"
			<< n - 1 << "之间的整数，w为非负整数）。" << endl;
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			graph[u][v] = graph[v][u] = w;   // 无向图存储方式
		}

		vector<Edge> edges = Prim(graph);
		int cost = 0;
		for (const auto& edge : edges) {
			cout << edge.from << " -> " << edge.to << ", weight: " << edge.weight << endl;
			cost += edge.weight;
		}
		cout << "最小生成树总权值为：" << cost << endl;
		}
			
			break;
		case 8:
		{
             printf("---------最短路径-------");
			 CreateDN(G);
			 char path[MAX_NUM];
			 int length = shortestPath(G, 'A', 'F', path);
			 std::cout << "最短路径长度为：" << length << std::endl;
		}
		break;
		case 9:
		{
			printf("---------关键路径-------");
			cout << endl;
			g.n = 6;
			g.e = 8;
			g.v = new VertexNode[g.n];

			// 初始化节点数据
			for (int i = 0; i < g.n; i++) {
				g.v[i].data = 'A' + i;
				g.v[i].in_degree = 0;
				g.v[i].first_edge = nullptr;
			}

			// 添加边
			addEdge(g, 0, 1, 3);
			addEdge(g, 0, 2, 2);
			addEdge(g, 1, 3, 4);
			addEdge(g, 2, 3, 3);
			addEdge(g, 2, 4, 2);
			addEdge(g, 3, 5, 2);
			addEdge(g, 4, 5, 3);
			addEdge(g, 0, 5, 5);

			int path[MAXN * MAXN] = { 0 };
			int length = criticalTopoSort(g, path);

			cout << "关键路径长度为：" << length << endl;
			cout << "关键路径为：";
			for (int i = 0; i < g.n; i++) {
				for (int j = 0; j < g.n; j++) {
					if (path[i * g.n + j] == 1) {
						cout << g.v[i].data << "->" << g.v[j].data << " ";
					}
				}
			}
			cout << endl;

			delete[] g.v;
		}
			
		

		break;

		case 10:break;
		default:
			printf("ERROR!"); break;
		}
	} while (n != 10);
}

int main() {
	int n;
	do {
		ShowMainMenu();
		printf("请选择：");
		scanf_s("%d", &n);
		switch (n) {
		case 1:LinkList(); break;
		case 2:Stack(); break;
		case 3:Array(); break;
		case 4:BiTree(); break;
		case 5:Graph(); break;
		case 6:break;
		default:printf("ERROR!"); break;
		}
	} while (n != 6);
}
