#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
void bfs(int *Check, int *Path, vector<int> *a)
{
    queue<int> q;
    q.push(1);
    Check[1] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i : a[u])
        {
            if (!Check[i])
            {
                q.push(i);
                Check[i] = Check[u] + 1;
                Path[i] = u;
            }
        }
    }
}
void querypath(int n, int *Path)
{
    stack<int> v;
    for (int i = n; i != 0; i = Path[i])
    {
        v.push(i);
    }
    while (!v.empty())
    {
        cout << v.top() << ' ';
        v.pop();
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int *Check = new int[n + 1]{0};
    int *Path = new int[m]{0};
    vector<int> *a = new vector<int>[n + 1]; // danh sach ke
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    bfs(Check, Path, a);
    if (!Check[n])
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        cout << Check[n] << '\n';
        querypath(n, Path);
    }
    delete[] Check;
    delete[] Path;
    delete[] a;
}