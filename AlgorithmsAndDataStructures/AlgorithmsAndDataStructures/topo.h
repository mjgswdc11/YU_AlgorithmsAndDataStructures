#pragma once
#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
#define MAXN 100
// 结构体定义
struct EdgeNode {
    int to;             // 该边指向的节点编号
    int weight;         // 边的权值
    struct EdgeNode* next;   // 下一条边的指针
};

struct VertexNode {
    int in_degree;      // 节点的入度
    char data;          // 节点的数据（这里用字符表示）
    struct EdgeNode* first_edge;     // 以该节点为出发点的第一条边的指针
};

struct TopoGraph {
    int n;                  // 节点个数
    int e;                  // 边数
    struct VertexNode* v;   // 顶点信息数组的指针
};

// 拓扑排序函数
void TopoSort(TopoGraph g) {
    stack<int> s;           // 定义栈，存储入度为0的节点编号
    for (int i = 0; i < g.n; i++) {
        if (g.v[i].in_degree == 0) {    // 将入度为0的节点放入栈中
            s.push(i);
        }
    }

    while (!s.empty()) {
        int u = s.top();        // 取出栈顶元素
        s.pop();

        cout << g.v[u].data << " ";     // 输出该节点的数据

        EdgeNode* p = g.v[u].first_edge;
        while (p) {
            int v = p->to;          // 取出该边指向的节点编号
            g.v[v].in_degree--;     // 将该节点的入度减1

            if (g.v[v].in_degree == 0) {    // 如果该节点的入度变为0，则入栈
                s.push(v);
            }

            p = p->next;            // 处理下一条边
        }
    }
}
//关键路径
/**
 * 求关键路径
 * @param g 拓扑图
 * @param path 关键路径
 * @return 关键路径长度
 */
int criticalTopoSort(const TopoGraph& g, int* path) {
    int* earliest_time = new int[g.n];  // 最早发生时间
    int* latest_time = new int[g.n];    // 最晚发生时间
    int length = 0;

    // 初始化最早发生时间
    for (int i = 0; i < g.n; i++) {
        earliest_time[i] = 0;
    }

    // 计算最早发生时间
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

    // 初始化最晚发生时间
    for (int i = 0; i < g.n; i++) {
        latest_time[i] = earliest_time[g.n - 1];
    }

    // 计算最晚发生时间
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

    // 计算关键路径
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
 * 添加一条边
 * @param g 拓扑图
 * @param u 起点
 * @param v 终点
 * @param w 边权值
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
 * 求最短路径（Dijkstra算法）
 * @param G 有向网
 * @param start 起点
 * @param end 终点
 * @param path 路径
 * @return 最短路径长度
 */
int shortestPath(const MGraph& G, char start, char end, char* path) {
    const int INF = 0x3f3f3f3f;  // 无穷大
    int* dist = new int[G.v];    // 距离
    bool* visited = new bool[G.v];  // 是否访问过
    int* prev = new int[G.v];        // 前驱节点
    int length = 0;

    // 初始化
    for (int i = 0; i < G.v; i++) {
        dist[i] = INF;
        visited[i] = false;
        prev[i] = -1;
    }
    int start_index = adjloction(G, start);
    dist[start_index] = 0;

    // 进行n-1次循环
    for (int i = 0; i < G.v - 1; i++) {
        // 找到未访问过的距离最短的节点
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

        // 更新与u相邻的节点的距离
        for (int v = 0; v < G.v; v++) {
            if (!visited[v] && G.arcs[u][v].adj != 0 && dist[u] + G.arcs[u][v].adj < dist[v]) {
                dist[v] = dist[u] + G.arcs[u][v].adj;
                prev[v] = u;
            }
        }
    }

    // 生成路径
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