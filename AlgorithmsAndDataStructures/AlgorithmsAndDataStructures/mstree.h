#pragma once
#include <iostream>
#include <vector>

using namespace std;

// ����һ�����࣬������㡢�յ�ͱ�Ȩ
class Edge {
public:
    int from, to, weight;
    Edge(int f, int t, int w) :from(f), to(t), weight(w) {};
};

// Prim�㷨����С������
vector<Edge> Prim(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> vis(n, false);    // ��ǽڵ��Ƿ���ʹ�
    vector<Edge> edges;            // �����С�����������б�
    vis[0] = true;
    // �ӽڵ�0��ʼ�����ϼ����µ���̱�ֱ�����нڵ㶼������
    for (int i = 0; i < n - 1; i++) {
        int minWeight = INT_MAX, minFrom, minTo;
        // �����Ѿ����ʹ��Ľڵ㣬�ҵ���̵���ͨ��
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
        edges.emplace_back(minFrom, minTo, minWeight);    // ����̵ı߼���edges��
    }
    return edges;
}