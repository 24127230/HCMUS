#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <limits>

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

void merge(vector<int> &a, int fi, int mid, int la) 
{
    vector <int> b(a.begin() + fi, a.begin() + mid + 1);
    vector <int> c(a.begin() + mid + 1, a.begin() + la + 1);
    int i = 0;
    int j = 0;
    int index = fi;
    while (i < b.size() && j < c.size()) {
        if (b[i] < c[j]) {
            a[index++] = b[i++];
        }
        else a[index++] = c[j++];
    }
    while (i < b.size()) a[index++] = b[i++];
    while (j < c.size()) a[index++] = c[j++];
}
void merge_sort(vector<int> &a, int fi, int la)
{
    if (fi < la) {
        int middle = (la + fi) / 2;
        merge_sort(a, fi, middle);
        merge_sort(a, middle+1, la);
        merge(a, fi, middle, la);
    }
}

void counting_sort(vector<int> &a, int n)
{
    int max_val = 0;
    for (int i = 0; i < n; i++) 
        if (a[i] > max_val) max_val = a[i];
    vector<int> aux(max_val + 1);
    for (int i = 0; i < n; i++)
    {
        aux[a[i]]++;
    }
    int val = 0;
    int i = 0;
    while (i < n)
    {
        while(aux[val])
        {
            a[i++] = val;
            aux[val]--;
        }
        val++;
    }
}

void radix_sort(vector<int> &a, int n)
{
    int max_val = 0;
    for (int i = 0; i < n; i++) 
        if (a[i] > max_val) max_val = a[i];
    int numofdigit = 0;
    while (max_val)
    {
        max_val /= 10;
        numofdigit++;
    }
    for (int i_dg = 1; i_dg <= numofdigit; i_dg++)
    {
        vector<vector<int>> group(10);
        for (int i = 0; i < n; i++)
        {
            int tmp = a[i];
            for (int j = 1; j < i_dg; j++) if (tmp) tmp /= 10;
            int digit = tmp % 10;
            group[digit].push_back(a[i]);
        }
        int index = 0;
        for (int digit = 0; digit < 10; digit++)
        {
            for (int i = 0; i < group[digit].size(); i++)
            {
                a[index++] = group[digit][i];
            }
        }
    }
    
}
int main()
{
    vector<int> a1(10000);
    vector<int> a2(10000);
    vector<int> a3(10000);
    vector<int> a4(10000);
    vector<int> a5(10000);
    for (int i = 0; i < a1.size(); i++)
        a1[i] = a2[i] = a3[i] = a4[i] = a5[i] = rand() % 10000;

    vector<pair<string,double>> res;

    {
        auto start = high_resolution_clock::now();
        heap_sort(a1, 10000);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        double t = duration.count();
        res.push_back({"Heap Sort", t});
    }
    
    {
        auto start = high_resolution_clock::now();
        quick_sort(a2, 0, 10000 - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        double t = duration.count();
        res.push_back({"Quick Sort", t});
    }
    
    {
        auto start = high_resolution_clock::now();
        merge_sort(a3, 0, 10000 - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        double t = duration.count();
        res.push_back({"Merge Sort", t});
    }

    {
        auto start = high_resolution_clock::now();
        counting_sort(a4, 10000);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        double t = duration.count();
        res.push_back({"Counting Sort", t});
    }

    {
        auto start = high_resolution_clock::now();
        radix_sort(a5, 10000);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        double t = duration.count();
        res.push_back({"Radix Sort", t});
    }
    pair<string,double> resmax, resmin;
    resmax.second = 0;
    resmin.second = numeric_limits<double>::max();
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i].first << " : " << res[i].second / 1000000000.0  << " seconds\n";
        if (resmax.second < res[i].second) resmax = res[i];
        if (resmin.second > res[i].second) resmin = res[i];
    }
    
    cout << "The fastest algorithm: " << resmin.first << '\n';
    cout << "The slowest algorithm: " << resmax.first;
    
    return 0;
}