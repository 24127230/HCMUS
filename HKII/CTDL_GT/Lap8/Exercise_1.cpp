#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <climits> 
#include <queue>
using namespace std;
struct Edge {int vertex, weight;};
void printPath_utov(int u, int v, vector<int> &parent) {
    stack<int> s;
    while(v != u) {
        s.push(v);
        v = parent[v];
    }
    s.push(v);
    while (!s.empty()) { 
        cout << s.top();
        s.pop();
        if (!s.empty()) cout << " -> ";
    }
}
void Dijkstra(vector<vector<Edge>> &a, int source) {
    int n = a.size();
    vector<int> d(n, INT_MAX);
    vector<int> parent(n, -1);
    d[source] = 0;

    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source});
    while (!pq.empty()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du > d[u]) continue;

        for(Edge e : a[u]) {
            int v = e.vertex, auv = e.weight;
            if (d[v] > auv + d[u])
            {
                d[v] = auv + d[u];
                parent[v] = u;
                pq.push({d[v], v});
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (i != source) 
        {
            cout << "The shortest path from "<< source << " to " << i << ": ";
            printPath_utov(source, i, parent);
            cout << ".\n";
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

    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    Dijkstra(a, src);

    return 0;
}