#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <climits> 
using namespace std;
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
void Dijkstra(vector<vector<int>> &a, int source) {
    int n = a.size();
    vector<int> d(n, INT_MAX);
    d[source] = 0;
    int step = 0;
    vector<bool> vertexset(n, 0);
    int u; // vertex
    vector<int> parent(n); 
    while (step++ < n) {
        int min = INT_MAX;
        for (int i = 0; i < n; i++)
            if (min > d[i] && !vertexset[i]) {
                min = d[i];
                u = i;
            }
        vertexset[u] = 1;
        for (int v = 0; v < n; v++) {
            if (a[u][v] != 0 && !vertexset[v] && d[v] > d[u] + a[u][v]) {
                d[v] = d[u] + a[u][v];
                parent[v] = u;
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
    Dijkstra(a, src);

    return 0;
}