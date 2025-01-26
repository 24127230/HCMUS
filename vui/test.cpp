#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> a({1, 2, 3, 4, 5});
    // a.assign(3, 100);
    for (auto x : a)
        cout << x << ' ';
}