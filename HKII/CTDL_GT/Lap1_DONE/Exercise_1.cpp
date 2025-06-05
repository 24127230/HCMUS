#include <iostream>
#include <limits>
using namespace std;

void inputArray(int *&arr, int n);
void printArray(int *arr, int n);
int findMax(int *arr, int n);
int sumArray(int *arr, int n);
void concatArrays(int *a, int na, int *b, int nb, int *&res, int &nres);
void findLongestAscendingSubarray(int *arr, int n, int *&res, int &nres);

void inputArray(int *&arr, int n)
{
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}
int findMax(int *arr, int n)
{
    int Max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        Max = (arr[i] > Max) ? arr[i] : Max;
    }
    return Max;
}
int sumArray(int *arr, int n)
{
    int Sum = 0;
    for (int i = 0; i < n; i++)
    {
        Sum += arr[i];
    }
    return Sum;
}
void concatArrays(int *a, int na, int *b, int nb, int *&res, int &nres)
{
    nres = na + nb;
    res = new int[nres];
    for (int i = 0; i < nres; i++)
    {
        res[i] = (i < na) ? a[i] : b[i - na];
    }
}
void findLongestAscendingSubarray(int *arr, int n, int *&res, int &nres)
{
    int count = 1;
    int end = 0;
    nres = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            count = 1;
        }
        else
            count++;
        if (count > nres)
        {
            nres = count;
            end = i;
        }
    }
    res = new int[nres];
    for (int i = 0; i < nres; i++)
    {
        res[i] = arr[i + end - nres + 1];
    }
}

int main()
{
    cout << "Enter the number of elements in array a: ";
    int na;
    int *a;
    cin >> na;
    cout << "Then enter the array a:\n";
    inputArray(a, na);

    cout << "Enter the number of elements in array b: ";
    int nb;
    int *b;
    cin >> nb;
    cout << "Then enter the array b:\n";
    inputArray(b, nb);

    int nc;
    int *c;
    concatArrays(a, na, b, nb, c, nc);
    cout << "Array c:\n";
    printArray(c, nc);

    cout << "\nPrint the maximum value in the array c: " << findMax(c, nc);

    cout << "\nPrint the sum of elements in the array c: " << sumArray(c, nc);

    cout << "\nPrint the longest ascending subarray in the array c:\n";
    int *LAS;
    int nLAS;
    findLongestAscendingSubarray(c, nc, LAS, nLAS);
    printArray(LAS, nLAS);

    delete[] a;
    delete[] b;
    delete[] c;
    delete[] LAS;
    return 0;
}