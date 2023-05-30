#pragma once
#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
#define MAXN 100
// �ṹ�嶨��
struct EdgeNode {
    int to;             // �ñ�ָ��Ľڵ���
    int weight;         // �ߵ�Ȩֵ
    struct EdgeNode* next;   // ��һ���ߵ�ָ��
};

struct VertexNode {
    int in_degree;      // �ڵ�����
    char data;          // �ڵ�����ݣ��������ַ���ʾ��
    struct EdgeNode* first_edge;     // �Ըýڵ�Ϊ������ĵ�һ���ߵ�ָ��
};

struct TopoGraph {
    int n;                  // �ڵ����
    int e;                  // ����
    struct VertexNode* v;   // ������Ϣ�����ָ��
};

// ����������
void TopoSort(TopoGraph g) {
    stack<int> s;           // ����ջ���洢���Ϊ0�Ľڵ���
    for (int i = 0; i < g.n; i++) {
        if (g.v[i].in_degree == 0) {    // �����Ϊ0�Ľڵ����ջ��
            s.push(i);
        }
    }

    while (!s.empty()) {
        int u = s.top();        // ȡ��ջ��Ԫ��
        s.pop();

        cout << g.v[u].data << " ";     // ����ýڵ������

        EdgeNode* p = g.v[u].first_edge;
        while (p) {
            int v = p->to;          // ȡ���ñ�ָ��Ľڵ���
            g.v[v].in_degree--;     // ���ýڵ����ȼ�1

            if (g.v[v].in_degree == 0) {    // ����ýڵ����ȱ�Ϊ0������ջ
                s.push(v);
            }

            p = p->next;            // ������һ����
        }
    }
}
//�ؼ�·��
/**
 * ��ؼ�·��
 * @param g ����ͼ
 * @param path �ؼ�·��
 * @return �ؼ�·������
 */
int criticalTopoSort(const TopoGraph& g, int* path) {
    int* earliest_time = new int[g.n];  // ���緢��ʱ��
    int* latest_time = new int[g.n];    // ������ʱ��
    int length = 0;

    // ��ʼ�����緢��ʱ��
    for (int i = 0; i < g.n; i++) {
        earliest_time[i] = 0;
    }

    // �������緢��ʱ��
    for (int i = 0; i < g.n; i++) {
        int u = g.v[i].data - 'A';
        EdgeNode* p = g.v[i].first_edge;
        while (p != nullptr) {
            int v = p->to;
            int e = p->weight;
            if (earliest_time[u] + e > earliest_time[v]) {
                earliest_time[v] = earliest_time[u] + e;
            }
            p = p->next;
        }
    }

    // ��ʼ��������ʱ��
    for (int i = 0; i < g.n; i++) {
        latest_time[i] = earliest_time[g.n - 1];
    }

    // ����������ʱ��
    for (int i = g.n - 1; i >= 0; i--) {
        int u = g.v[i].data - 'A';
        EdgeNode* p = g.v[i].first_edge;
        while (p != nullptr) {
            int v = p->to;
            int e = p->weight;
            if (latest_time[v] - e < latest_time[u]) {
                latest_time[u] = latest_time[v] - e;
            }
            p = p->next;
        }
    }

    // ����ؼ�·��
    for (int i = 0; i < g.n; i++) {
        int u = g.v[i].data - 'A';
        EdgeNode* p = g.v[i].first_edge;
        while (p != nullptr) {
            int v = p->to;
            int e = p->weight;
            if (earliest_time[u] + e == latest_time[v]) {
                path[u * g.n + v] = 1;
                length += e;
            }
            p = p->next;
        }
    }

    delete[] earliest_time;
    delete[] latest_time;
    return length;
}
/**
 * ���һ����
 * @param g ����ͼ
 * @param u ���
 * @param v �յ�
 * @param w ��Ȩֵ
 */
void addEdge(TopoGraph& g, int u, int v, int w) {
    EdgeNode* p = new EdgeNode;
    p->to = v;
    p->weight = w;
    p->next = g.v[u].first_edge;
    g.v[u].first_edge = p;
    g.v[v].in_degree++;
}
/**
 * �����·����Dijkstra�㷨��
 * @param G ������
 * @param start ���
 * @param end �յ�
 * @param path ·��
 * @return ���·������
 */
int shortestPath(const MGraph& G, char start, char end, char* path) {
    const int INF = 0x3f3f3f3f;  // �����
    int* dist = new int[G.v];    // ����
    bool* visited = new bool[G.v];  // �Ƿ���ʹ�
    int* prev = new int[G.v];        // ǰ���ڵ�
    int length = 0;

    // ��ʼ��
    for (int i = 0; i < G.v; i++) {
        dist[i] = INF;
        visited[i] = false;
        prev[i] = -1;
    }
    int start_index = adjloction(G, start);
    dist[start_index] = 0;

    // ����n-1��ѭ��
    for (int i = 0; i < G.v - 1; i++) {
        // �ҵ�δ���ʹ��ľ�����̵Ľڵ�
        int u = -1;
        int min_dist = INF;
        for (int j = 0; j < G.v; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                u = j;
                min_dist = dist[j];
            }
        }
        if (u == -1) {
            break;
        }
        visited[u] = true;

        // ������u���ڵĽڵ�ľ���
        for (int v = 0; v < G.v; v++) {
            if (!visited[v] && G.arcs[u][v].adj != 0 && dist[u] + G.arcs[u][v].adj < dist[v]) {
                dist[v] = dist[u] + G.arcs[u][v].adj;
                prev[v] = u;
            }
        }
    }

    // ����·��
    int u = adjloction(G, end);
    int index = 0;
    while (prev[u] != -1) {
        path[index++] = G.vexs[u];
        u = prev[u];
    }
    path[index++] = G.vexs[u];
    for (int i = index - 1; i >= 0; i--) {
        std::cout << path[i];
        if (i > 0) {
            std::cout << "->";
        }
    }
    std::cout << std::endl;

    length = dist[adjloction(G, end)];

    delete[] dist;
    delete[] visited;
    delete[] prev;
    return length;
}