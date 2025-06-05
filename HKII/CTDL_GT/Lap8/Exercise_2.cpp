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
<<<<<<< HEAD
    
    vector<int> d(n, INT_MAX);
    d[source] = 0;
    
=======
    for (const Edge &e : edgeSet)
    {
        cout << e.u << " " << e.v << " " << e.w << '\n';
    }
    
    vector<int> d(n, INT_MAX);
    d[source] = 0;
>>>>>>> 13ae612820f3526fcd772dc069469470d564ef07
    vector<int> parent(n); 
    for (int step = 0; step < n - 1; step++)
    {
        
        for (const Edge &e : edgeSet) {
<<<<<<< HEAD
            if (d[e.u] != INT_MAX && d[e.v] > d[e.u] + e.w) {
=======
            if (d[e.v] > d[e.u] + e.w){
>>>>>>> 13ae612820f3526fcd772dc069469470d564ef07
                d[e.v] = d[e.u] + e.w;
                parent[e.v] = e.u;
            }
        }
    }
    // run 1 more time
    for (const Edge &e : edgeSet) {
<<<<<<< HEAD
        if (d[e.u] != INT_MAX && d[e.v] > d[e.u] + e.w) {
=======
        if (d[e.v] > d[e.u] + e.w){
>>>>>>> 13ae612820f3526fcd772dc069469470d564ef07
            cout << "Graph have negative cicle.";
            return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i != source) 
        {
            cout << "The shortest path from "<< source << " to " << i << ": ";
<<<<<<< HEAD
            if (d[i] == INT_MAX) {
                cout << "No path exists.\n";
            } else {
                printPath_utov(source, i, parent);
                cout << ".\n";
            }
=======
            printPath_utov(source, i, parent);
            cout << ".\n";
>>>>>>> 13ae612820f3526fcd772dc069469470d564ef07
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