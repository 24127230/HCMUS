#include <iostream>
using namespace std;
void sort(int n);
void swap(int *p1, int *p2);
int a[10];
int main()
{
    for (int i = 0; i < 10; ++i)
    {
        cout << "Enter array element #" << i << ": ";
        cin >> a[i];
    }
    sort(10);
    cout << "Here is the array, sorted:" << endl;
    for (int i = 0; i < 10; ++i)
    {
        cout << a[i] << " ";
    }
    return 0;
}
void sort(int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        bool in_oder = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[j + 1] < a[j])
            {
                swap(a[j], a[j + 1]);
                in_oder = 0;
            }
        }
        if (in_oder)
            break;
    }
}
void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// 1 3 3 4 5 5 6 7 8 9

//     3 5 1 6 7 9 3 5 4 8