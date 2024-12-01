#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
int *countEvens(int *arr, int n);
int *genEvenSubarray(int *arr, int n);
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    f(i, 0, n) cin >> *(a + i);
    int *count = countEvens(a, n);
    int *evenSuba = genEvenSubarray(a, n);
    delete[] a;
    cout << "The count of even numbers: " << *count;
    cout << "\nA subarray containing only the even numbers: ";
    f(i, 0, *count) cout << *(evenSuba + i) << " ";
    delete count;
    delete[] evenSuba;
    return 0;
}
int *countEvens(int *arr, int n)
{
    int *cnt = new int;
    *cnt = 0;
    // f(i, 0, n) *cnt = (*(arr + i) % 2 == 0) ? (*cnt)++ : *cnt;
    f(i, 0, n) if (*(arr + i) % 2 == 0)(*cnt)++;
    return cnt;
}
int *genEvenSubarray(int *arr, int n)
{
    int *esn = countEvens(arr, n);
    int *esa = new int[*esn];
    delete esn;
    int j = 0;
    f(i, 0, n)
    {
        if (*(arr + i) % 2 == 0)
        {
            *(esa + j) = *(arr + i);
            j++;
        }
    }
    return esa;
}