#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <climits> 
<<<<<<< HEAD
#include <queue>
using namespace std;
struct Edge {int vertex, weight;};
=======
using namespace std;
>>>>>>> 13ae612820f3526fcd772dc069469470d564ef07
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
<<<<<<< HEAD
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
    
=======
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
>>>>>>> 13ae612820f3526fcd772dc069469470d564ef07
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
<<<<<<< HEAD
    vector<vector<Edge>> a(n);
=======
    vector<vector<int>> a(n, vector<int>(n, 0));
>>>>>>> 13ae612820f3526fcd772dc069469470d564ef07
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
<<<<<<< HEAD
            int w;
            fin >> w;
            if (w > 0)
                a[i].push_back({j, w});
        }
=======
            fin >> a[i][j];
            cout << a[i][j] << " ";
        }
        cout << "\n";
>>>>>>> 13ae612820f3526fcd772dc069469470d564ef07
    }
    fin.close();

    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    Dijkstra(a, src);

    return 0;
}