#pragma once
#include <iostream>
#include <vector>

using namespace std;

// 定义一个边类，包含起点、终点和边权
class Edge {
public:
    int from, to, weight;
    Edge(int f, int t, int w) :from(f), to(t), weight(w) {};
};

// Prim算法求最小生成树
vector<Edge> Prim(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> vis(n, false);    // 标记节点是否访问过
    vector<Edge> edges;            // 存放最小生成树的所有边
    vis[0] = true;
    // 从节点0开始，不断加入新的最短边直到所有节点都被访问
    for (int i = 0; i < n - 1; i++) {
        int minWeight = INT_MAX, minFrom, minTo;
        // 遍历已经访问过的节点，找到最短的连通边
        for (int j = 0; j < n; j++) {
            if (vis[j]) {
                for (int k = 0; k < n; k++) {
                    if (!vis[k] && graph[j][k] != 0 && graph[j][k] < minWeight) {
                        minWeight = graph[j][k];
                        minFrom = j;
                        minTo = k;
                    }
                }
            }
        }
        vis[minTo] = true;
        edges.emplace_back(minFrom, minTo, minWeight);    // 将最短的边加入edges中
    }
    return edges;
}