#include<stdio.h>
#include"linklist.h"//���������������ͷ�ļ�
#include"stack.h"//����ջ������ͷ�ļ�
#include"matrix.h"//����ϡ����������ͷ�ļ�
#include "bitree.h"//������������ͷ�ļ�
#include"graph.h"//����ͼ������ͷ�ļ�
#include"topo.h"//�����������в�����ͷ�ļ�
#include"mstree.h"//������С������������ͷ�ļ�


using namespace std;
void ShowMainMenu() {
	printf("\n");
	printf("*******************�㷨�����ݽṹ******************\n");
	printf("* 1  ������Ļ���������Ӧ��                       *\n");
	printf("* 2  ջ�Ļ���������Ӧ��                           *\n");
	printf("* 3  ����Ļ���������Ӧ��                         *\n");
	printf("* 4  ���Ļ���������Ӧ��                           *\n");
	printf("* 5  ͼ�Ļ���������Ӧ��                           *\n");
	printf("* 6  �˳�                                         *\n");
	printf("***************************************************\n");
}

void LinkList() {
	int n;
	List L;//��ʼ���õ���
	L = (LNode*)malloc(sizeof(LNode));
	do {
		printf("\n");
		printf("**************������Ļ���������Ӧ��***************\n");
		printf("* 1  ����                                         *\n");
		printf("* 2  ����                                         *\n");
		printf("* 3  ɾ��                                         *\n");
		printf("* 4  ����                                         *\n");
		printf("* 5  ��ʾ                                         *\n");
		printf("* 6  ͨѶ¼��Ӧ�ã�                               *\n");
		printf("* 7  �˳�                                         *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf_s("%d", &n);
		int num = 0;
		int pos=0;
		int ele=0;
		switch (n) {
		case 1:
			printf("--------����������---------"); 
			cout << endl;
			L->next = NULL;
			cout << "���������ݸ�����"<<endl;
			cin >> num;
			cout << "�������������ݣ�" << endl;
			L = CreatList(L, num);
			cout << "��������������ɹ�" << endl;
			break;
		case 2:
			printf("--------����Ԫ��-------"); 
			cout << endl;
			cout << "��ʼ��posλ�ò���Ԫ��ele" << endl;
			cout << "������pos��ֵ��" << endl;cin >> pos;
			cout<< "������ele��ֵ��" <<endl;cin >> ele;
			ListInsert(L, pos, ele);
			cout << "����Ԫ�ز������" << endl;
			break;
		case 3:
			printf("--------ɾ��Ԫ��-------"); 
			cout << endl;
			cout << "��ʼ��posλ��ɾ��" << endl;
			cout << "������pos��ֵ��" << endl; cin >> pos;
			cout<<"ɾ����ֵ�ǣ�"<<ListDelete(L, pos)<<endl;
			cout << "ɾ��Ԫ�ز������" << endl;
			break;
		case 4:
			printf("--------����Ԫ��-------"); 
			cout << endl;
			cout << "��ʼ��posλ�ò���" << endl;
			cout << "������pos��ֵ��"<<endl;cin >> pos;
			cout<<"���ҵ�ֵΪ��" << GetElem(L,pos) << endl;
			cout << "����Ԫ�ز������" << endl;
			break;
		case 5:
			printf("--------��ʾ����-------"); 
			cout << endl;
			PrintList(L);
			cout << "��ʾ���������ɣ�" << endl;
			break;
		case 6:
			printf("--------ͨѶ¼---------"); 
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
		printf("****************ջ�Ļ���������Ӧ��*****************\n");
		printf("* 1  ��ջ                                         *\n");
		printf("* 2  ��ջ                                         *\n");
		printf("* 3  ȡջ��Ԫ��                                   *\n");
		printf("* 4  ���ʽ��⣨Ӧ�ã�                           *\n");
		printf("* 5  �˳�                                         *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("--------��ջ-------"); 
			cout << endl;
			char e1;
			cout << "�������ջ���ݣ���char���ͣ�" << endl;
			cin >> e1;
			Push(S, e1);
			cout << "��ջ�ɹ�" << endl;
			cout << "��ջ�������" << endl;
			break;
		case 2:
			printf("--------��ջ-------"); 
			cout << endl;
			char e2;
			Pop(S,e2);
			cout << "��ջ�ɹ�" << endl;
			cout << "��ջԪ��Ϊ��"<<e2 << endl;
			break;
		case 3:
			printf("--------ȡջ��Ԫ��-------"); 
			cout << endl;
			char e3;
			GetTop(S, e3);
			cout << "ջ��Ԫ��Ϊ��" << e3 << endl;
			break;
		case 4:
			printf("--------���ʽ��ֵ-------"); 
			cout << endl;
			cout << "��һ��������ʽ�ӣ����ԡ�#����β:" << endl;
			cout << "�������ǣ�" << EvaluateExpression() - 48 << endl;
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
		printf("*************ϡ������ѹ���洢��Ӧ��**************\n");
		printf("* 1  ����                                         *\n");
		printf("* 2  ��ʾ                                         *\n");
		printf("* 3  ����˷���Ӧ�ã�                             *\n");
		printf("* 4  �˳�                                         *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("---------����-------"); 
			cout << endl;
			CreatTriple(T);
			cout << "�������" << endl;
			break;
		case 2:
			printf("---------��ʾ-------"); 
			cout << endl;
		    ShowMatrix(T);
			cout << "��ʾ�������" << endl;
			break;
		case 3:
			printf("---------����˷�-------"); 
			TSMatrix matrix1, matrix2, result;
			cout << "������һ������" << endl;
			CreatTriple(matrix1);
			cout << "�����ڶ�������" << endl;
			CreatTriple(matrix2);
			MulMatrix(matrix1, matrix2, result);
			cout << "��˺���Ϊ��" << endl;
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
		printf("**************�������Ļ���������Ӧ��***************\n");
		printf("* 1  ����������                                   *\n");
		printf("* 2  ��������������/��/��                       *\n");
		printf("* 3  �����������                                 *\n");
		printf("* 4  ����Ҷ�ӽ�����                             *\n");
		printf("* 5  ����˫��                                     *\n");
		printf("* 6  �����ֵ�                                     *\n");
		printf("* 7  Huffman���루Ӧ�ã�                          *\n");
		printf("* 8  �˳�\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("---------����������--------"); 
			cout << endl;
			cout << "��������Ҫ�����Ķ��������������У��ԡ�#����ʾ����һ���սڵ㣩��" << endl;
			getchar();
			CreateBinTree(&T);
			cout << "�����������ɹ�" << endl;
			
			break;
		case 2:
			printf("---------*����������-------"); 
			cout << endl;
			cout << "��������Ϊ��" << endl;
			Preorder(T);
			cout << endl;
			cout << "��������Ϊ��" << endl;
			Inorder(T);
			cout << endl;
			cout << "��������Ϊ��" << endl;
			Postorder(T);
			cout << endl;
			break;
		case 3:
			printf("---------�����������------");
			cout << endl;
			cout << "�ö�����������ǣ�" << PostOrderGetHeight(T) << endl;
			break;
		case 4:
			printf("---------����Ҷ�ӽ�����-------");
			cout << endl;
			cout << "�ö�������Ҷ�ӽ������ǣ�"<<LeafNodeNum(T) << endl;
			break;
		case 5:
			printf("---------����˫��-------"); 
			char x;
			cout << endl;
			cout << "��������Ҫ��ѯ�Ľ���ֵ��char�����ͣ�" << endl;
			cin >> x;
			cout << "�ý��ĸ�����ֵ�ǣ�" << FindFatherNode(T, x) << endl;
			break;
		case 6:
			printf("---------�����ֵ�-------"); 
			cout << endl;
			cout << "��������Ҫ��ѯ�Ľ���ֵ��char�����ͣ�" << endl;
			cin >> x;
			cout << "�ý����ֵܽ���ֵ�ǣ�" << FindBrotherNode(T, x) << endl;
			break;
		case 7:
		{
            printf("---------Huffman����-------");
			cout << endl;
			int n;
			cout << "������Ȩֵ������";
			cin >> n;

			// ����ÿ���ַ���Ȩֵ
			vector<pair<char, int>> freq(n);
			cout << "������" << n << "��Ȩֵ��";
			for (int i = 0; i < n; i++) {
				cin >> freq[i].second;
			}

			// ������ת��Ϊ�ַ�����
			char ch = 'A';
			for (int i = 0; i < n; i++) {
				freq[i].first = ch++;
			}

			// �����շ������ͺշ��������
			HuffmanNode* root = buildHuffmanTree(freq);
			unordered_map<char, string> table = generateHuffmanTable(root);

			// ����շ��������
			cout << "�շ�����������£�" << endl;
			for (const auto& p : table) {
				cout << "ȨֵΪ" << p.first << "�ı���Ϊ��" << p.second << endl;
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
		printf("****************ͼ�Ļ���������Ӧ��*****************\n");
		printf("* 1  ��������ͼ                                    *\n");
		printf("* 2  ����������                                    *\n");
		printf("* 3  ��������ͼ                                    *\n");
		printf("* 4  ����������                                    *\n");
		printf("* 5  ����                                          *\n");
		printf("* 6  ��������                                      *\n");
		printf("* 7  ��С��������Ӧ�ã�                            *\n");
		printf("* 8  ���·����Ӧ�ã�                              *\n");
		printf("* 9  �ؼ�·����Ӧ�ã�                              *\n");
		printf("* 10 �˳�                                          *\n");
		printf("***************************************************\n");
		printf("��ѡ��");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			printf("---------��������ͼ-------");
			cout << endl;
			CreateUDG(G);
			cout << "������ͼ���ڽӾ����ʾ���£�" << endl;
			PrintG(G);  // ����ڽӾ���

			break;
		case 2:
			printf("---------����������-------"); 
			cout << endl;
			CreateUDN(G);
			cout << "�����������ڽӾ����ʾ���£�" << endl;
			PrintG(G);  // ����ڽӾ���

			break;
		case 3:
			printf("---------��������ͼ-------"); 
			cout << endl;
			CreateDG(G); // ����GreateDG�����������ڽӾ����ʾ������ͼG
			cout << "������ͼ���ڽӾ����ʾ���£�" << endl;
			PrintG(G);  // ����ڽӾ���

			break;
		case 4:
			printf("---------����������-------"); 
			cout << endl;
			CreateDN(G);                                //���ô�������������
			cout << "�����������ڽӾ����ʾ���£�" << endl;//���������������ڽӾ�����Ϣ
			PrintG(G);  // ����ڽӾ���


			break;
		case 5:
			printf("---------����-------"); 
			cout << endl;
			InitVisited(); // ��ʼ�����ʱ�ǩ����

			printf("DFS���������");
			DFS(G, 0);  // �ӽڵ�0��ʼ����������ȱ���
			printf("\n");

			InitVisited(); // ��ʼ�����ʱ�ǩ����

			printf("BFS���������");
			BFS(G, 0);  // �ӽڵ�0��ʼ���й�����ȱ���
			printf("\n");
			break;
		case 6:
			printf("---------��������-------"); 
			cout << endl;
			
			cout << "������ڵ�����ͱ�����";
			cin >> g.n >> g.e;

			// Ϊ������Ϣ�������洢�ռ�
			g.v = new VertexNode[g.n];

			// ��ʼ��ÿһ�����㣬��������Ⱥ͵�һ����
			for (int i = 0; i < g.n; i++) {
				g.v[i].in_degree = 0;
				g.v[i].first_edge = NULL;
				cout << "������ڵ�" << i + 1 << "�����ݣ�";
				cin >> g.v[i].data;
			}

			// �������Ϣ�������ڽӱ�
			for (int k = 0; k < g.e; k++) {
				int i, j, w;
				cout << "������ߵ������յ����Լ���Ȩ�أ�";
				cin >> i >> j >> w;

				// ����һ���±�
				EdgeNode* e = new EdgeNode;
				e->to = j;
				e->weight = w;
				e->next = g.v[i].first_edge;

				// ���ñ߲��뵽���ı߱�ͷ
				g.v[i].first_edge = e;

				// ��j����ȼ�1
				g.v[j].in_degree++;
			}

			cout << "����������Ϊ��";
			TopoSort(g);
			break;
		case 7:
		{
          printf("---------��С������-------"); 
		cout << endl;
		int n, m;
		cout << "������ͼ�еĽڵ���n�ͱ���m��";
		cin >> n >> m;

		vector<vector<int>> graph(n, vector<int>(n, 0));
		cout << "������ÿ���ߵ������˵�ͱ�Ȩ����ʽΪu v w������u��vΪ0��"
			<< n - 1 << "֮���������wΪ�Ǹ���������" << endl;
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			graph[u][v] = graph[v][u] = w;   // ����ͼ�洢��ʽ
		}

		vector<Edge> edges = Prim(graph);
		int cost = 0;
		for (const auto& edge : edges) {
			cout << edge.from << " -> " << edge.to << ", weight: " << edge.weight << endl;
			cost += edge.weight;
		}
		cout << "��С��������ȨֵΪ��" << cost << endl;
		}
			
			break;
		case 8:
		{
             printf("---------���·��-------");
			 CreateDN(G);
			 char path[MAX_NUM];
			 int length = shortestPath(G, 'A', 'F', path);
			 std::cout << "���·������Ϊ��" << length << std::endl;
		}
		break;
		case 9:
		{
			printf("---------�ؼ�·��-------");
			cout << endl;
			g.n = 6;
			g.e = 8;
			g.v = new VertexNode[g.n];

			// ��ʼ���ڵ�����
			for (int i = 0; i < g.n; i++) {
				g.v[i].data = 'A' + i;
				g.v[i].in_degree = 0;
				g.v[i].first_edge = nullptr;
			}

			// ��ӱ�
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

			cout << "�ؼ�·������Ϊ��" << length << endl;
			cout << "�ؼ�·��Ϊ��";
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
		printf("��ѡ��");
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
