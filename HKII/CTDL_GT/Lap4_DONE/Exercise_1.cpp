#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
using namespace std::chrono;
using namespace std;
void insertion_sort(vector<int> arr, int n)
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
void Swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void selection_sort(vector<int> arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        Swap(arr[i], arr[min]);
    }
}
void interchange_sort(vector<int> arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                Swap(arr[i], arr[j]);
        }
    }
}
int main()
{
    vector<int> a1(10000);
    vector<int> a2(10000);
    vector<int> a3(10000);
    for (int i = 0; i < a1.size(); i++)
        a1[i] = a2[i] = a3[i] = rand() % 10000;

    auto start1 = high_resolution_clock::now();
    insertion_sort(a1, 10000);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "Insertion Sort Time: " << duration1.count() / 1000000.0 << " seconds\n";

    auto start2 = high_resolution_clock::now();
    selection_sort(a2, 10000);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Selection Sort Time: " << duration2.count() / 1000000.0 << " seconds\n";

    auto start3 = high_resolution_clock::now();
    interchange_sort(a3, 10000);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    cout << "Interchange Sort Time: " << duration3.count() / 1000000.0 << " seconds\n";

    cout << "The fastest algorithm: ";
    if (duration1 < duration2)
    {
        if (duration1 < duration3)
            cout << "Insertion Sort";
        else
            cout << "Interchange Sort";
    }
    else if (duration2 < duration3)
        cout << "Selection Sort";
    else
        cout << "Interchange Sort";
    cout << "\nThe slowest algorithm: ";
    if (duration1 > duration2)
    {
        if (duration1 > duration3)
            cout << "Insertion Sort";
        else
            cout << "Interchange Sort";
    }
    else if (duration2 > duration3)
        cout << "Selection Sort";
    else
        cout << "Interchange Sort";
    return 0;
}