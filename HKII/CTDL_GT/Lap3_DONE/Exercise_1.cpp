#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int linear_search(int n, vector<int> arr, int target)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] == target)
            return i;
        i++;
    }
    return -1;
}

int linear_search_with_sentinel(int n, vector<int> arr, int target)
{
    arr.push_back(target);
    // arr[n] = target;
    int i = 0;
    while (arr[i] != target)
    {
        i++;
    }
    if (i == n)
        return -1;
    return i;
}

int Binary_search(int n, vector<int> arr, int target)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    // Parse arguments
    int algorithm = atoi(argv[1]);
    int x = atoi(argv[2]);
    char *input_path = argv[3];
    char *output_path = argv[4];

    // Process
    ifstream fin(input_path);
    if (!fin.is_open()) {
        cout << "Open file to read failed!";
        return 0;
    }
    int n;
    cout << "Find " << x << " in array[";
    fin >> n;
    cout << n << "] = {";
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        fin >> a[i];
        cout << a[i] << ((i == n - 1) ? "" : ", ");
    }
    cout << "} by ";
    fin.close();


    ofstream fout(output_path);
    if (!fout.is_open()) {
        cout << "Open file to write failed!";
        return 0;
    }
    int res = 10000;
    switch (algorithm)
    {
    case 1:
        cout << "linear search";
        res = linear_search(n, a, x);
        break;
    case 2:
        cout << "linear search with sentinel";
        res = linear_search_with_sentinel(n, a, x);
        break;
    case 3:
        cout << "binary search";
        res = Binary_search(n, a, x);
        break;
    }
    
    cout <<  " algorithm -> Index: " << res;
    fout << res;
    fout.close();

    return 0;
}