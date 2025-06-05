#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
struct Edge {int u, v, weight;};
struct CompareEdge {
    bool operator()(const Edge& e1, const Edge& e2) {
        return e1.weight > e2.weight; // Min-heap based on weight
    }
};
int findSet(int u, vector<int>& parent) {
    if (u != parent[u]) {
        parent[u] = findSet(parent[u], parent);
    }
    return parent[u];
}
void unionSets(int u, int v, vector<int>& parent) {
    int rootU = findSet(u, parent);
    int rootV = findSet(v, parent);
    if (rootU != rootV) {
        parent[rootU] = rootV;
    }
}
void Kruskal(int n, priority_queue<Edge, vector<Edge>, greater<Edge>> pq) {
    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    vector<Edge> mst;
    int mstW = 0;

    while (!pq.empty() && mst.size() < n - 1) {
        Edge e = pq.top();
        pq.pop();

        if (findSet(e.u, parent) != findSet(e.v, parent)) {
            mst.push_back(e);
            mstW += e.weight;
            unionSets(e.u, e.v, parent);
        }
    }
    cout << "Edge Weight\n";
    for (const auto& e : mst) {
        cout << e.u << " - " << e.v << " " << e.weight << "\n";
    }
}
int main() {
    ifstream fin("graph.txt");
    if (!fin.is_open()) {
        cerr << "Can not open file to read";
        return 0;
    }
    int n;
    fin >> n;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int w;
            fin >> w;
            if (w > 0 && i < j) {
                pq.push({i, j, w});
            }
        }
    }
    fin.close();
    Kruskal(n, pq);
    return 0;
}