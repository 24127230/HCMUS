#include <iostream>
#include <fstream>
#include <vector>
#include <climits> 
#include <queue>
using namespace std;
struct Edge {int vertex, weight;};
void Prim (vector<vector<Edge>> a, int src) {
    int n = a.size();
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<int> inMST(n, 0);
    key[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (inMST[u]) continue;
        inMST[u] = 1;
        for (Edge e : a[u]) {
            int v = e.vertex;
            int weight = e.weight;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
    cout << "Edge \tWeight\n";
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << " \t" << key[i] << "\n";
        }
    }
}
int main() {
    ifstream fin ("graph.txt");
    if (!fin.is_open()) {
        cerr << "Can not open file to read";
        return 0;
    } 

    int n;
    fin >> n;
    vector<vector<Edge>> a(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int w;
            fin >> w;
            if (w > 0)
                a[i].push_back({j, w});
        }
    }
    fin.close();

    int src = 0;
    Prim(a, src);

    return 0;
}