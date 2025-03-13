#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
void insertion_sort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main() {
    ifstream fin ("input.txt");
    if (!fin.is_open())
    {
        cerr << "can not open!";
        return 0;
    }
    int n, m;
    fin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fin >> a[i][j];
        }
    }
    fin.close();

    int top = 0;
    int bot = n - 1;
    int left = 0;
    int right = m - 1;
    while (top <= bot && left <= right) {
        for (int i = left; i <= right; i++) {
            temp.push_back(a[top][i]);
        }
        top++;
        for (int i = top; i <= bot; i++) {
            temp.push_back(a[i][right]);
        }
        right--;
        if(top <= bot) {
            for (int i = right; i >= left; i--) {
                temp.push_back(a[bot][i]);
            }
            bot--;
        }
        if (left <= right) {  
            for (int i = bot; i >= top; i--) {
                temp.push_back(a[i][left]);
            }
            left++;
        }
    }
    insertion_sort(temp,temp.size());
    int index = 0;
    top = 0;
    bot = n - 1;
    left = 0;
    right = m - 1;
    while (top <= bot && left <= right) {
        for (int i = left; i <= right; i++) {
            a[top][i] = temp[index++];
        }
        top++;
        for (int i = top; i <= bot; i++) {
            a[i][right] = temp[index++];
        }
        right--;
        if(top <= bot) {
            for (int i = right; i >= left; i--) {
                a[bot][i] = temp[index++];
            }
            bot--;
        }
        if (left <= right) {  
            for (int i = bot; i >= top; i--) {
                a[i][left] = temp[index++];
            }
            left++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}