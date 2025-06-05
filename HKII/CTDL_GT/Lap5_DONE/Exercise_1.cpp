#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
using namespace std::chrono;
using namespace std;
void SWAP(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void heap_rebuild(int index, vector<int> &arr, int n)
{
    bool isheap = 0;
    int k = index;

    while (!isheap && 2 * k + 1 < n)
    {
        int j = 2 * k + 1;
        if (j + 1 < n)
            if (arr[j] < arr[j + 1])
                j++;
        if (arr[k] < arr[j])
        {
            SWAP(arr[k], arr[j]);
            // for (int i = 0; i < arr.size(); i++) cout << arr[i] << ' ';
            // cout << "("<<k << "," << j <<")\n";
        }
        else
        {
            isheap = 1;
            // for (int i = 0; i < arr.size(); i++) cout << arr[i] << ' ';
            // cout << "("<< k << ",x)\n";
        }
        k = j;
    }
}
void heap_cons(vector<int> &arr, int n)
{
    int index = n / 2 - 1;
    while (index >= 0)
    {
        heap_rebuild(index, arr, n);
        index--;
    }
}
void heap_sort(vector<int> &arr, int n)
{
    heap_cons(arr, n);
    int r = n - 1;
    while (r > 0)
    {
        SWAP(arr[0], arr[r]);
        // for (int i = 0; i < arr.size(); i++) cout << arr[i] << ' ';
        // cout << "("<< r << "," << 0 <<")\n";
        r = r - 1;
        heap_rebuild(0, arr, r + 1);
    }
}
int middle(vector<int>arr ,int a, int b, int c)
{
    if (arr[a] > arr[b] ^ arr[a] > arr[c])
        return a;
    if (arr[b] > arr[a] ^ arr[b] > arr[c])
        return b;
    return c;
}
int partition(vector<int> &arr, int fi, int la)
{
    int p = middle(arr,fi,(fi+la)/2,la);
    SWAP(arr[p],arr[fi]);
    p = fi;
    int f_unknown = fi + 1;
    int lasts1 = fi;
    while (f_unknown <= la)
    {
        if (arr[f_unknown] < arr[p])
            SWAP(arr[f_unknown], arr[++lasts1]);
        f_unknown++;
    }
    SWAP(arr[p], arr[lasts1]);
    return lasts1;
}
void quick_sort(vector<int> &arr, int fi, int la)
{
    int p;
    if (fi < la)
    {
        p = partition(arr, fi, la);
        quick_sort(arr, fi, p - 1);
        quick_sort(arr, p + 1, la);
    }
}
int main()
{
    vector<int> a1(10000);
    vector<int> a2(10000);
    for (int i = 0; i < a1.size(); i++)
        a1[i] = a2[i] = rand() % 10000;

    auto start1 = high_resolution_clock::now();
    heap_sort(a1, 10000);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "Heap Sort: " << duration1.count() / 1000000.0 << " seconds\n";

    auto start2 = high_resolution_clock::now();
    quick_sort(a2,0, 10000 - 1);
    // for (int i = 0; i < 20; i++) cout << a2[i] <<' ';
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Quick Sort: " << duration2.count() / 1000000.0 << " seconds\n";
    cout << "The fastest algorithm: ";
    if (duration1 < duration2) cout << "Heap Sort\n";
    else cout << "Quick Sort\n";
    cout << "The slowest algorithm: ";
    if (duration1 > duration2) cout << "Heap Sort\n";
    else cout << "Quick Sort";
    return 0;
}