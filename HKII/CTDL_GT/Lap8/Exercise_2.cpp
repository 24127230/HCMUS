#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <climits> 
using namespace std;
struct Edge {int u,v,w;};
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
void Bellman_Ford(vector<vector<int>> &a, int source) {
    int n = a.size();
    vector<Edge> edgeSet;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(a[i][j]) edgeSet.push_back({i, j, a[i][j]});
        }
    }
    
    vector<int> d(n, INT_MAX);
    d[source] = 0;
    
    vector<int> parent(n); 
    for (int step = 0; step < n - 1; step++)
    {
        
        for (const Edge &e : edgeSet) {
            if (d[e.u] != INT_MAX && d[e.v] > d[e.u] + e.w) {
                d[e.v] = d[e.u] + e.w;
                parent[e.v] = e.u;
            }
        }
    }
    // run 1 more time
    for (const Edge &e : edgeSet) {
        if (d[e.u] != INT_MAX && d[e.v] > d[e.u] + e.w) {
            cout << "Graph have negative cicle.";
            return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i != source) 
        {
            cout << "The shortest path from "<< source << " to " << i << ": ";
            if (d[i] == INT_MAX) {
                cout << "No path exists.\n";
            } else {
                printPath_utov(source, i, parent);
                cout << ".\n";
            }
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
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fin >> a[i][j];
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    fin.close();

    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    Bellman_Ford(a, src);

    return 0;
}