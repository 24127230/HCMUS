#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
void generateMatrix1(int **a, int &length, int &width);
int main()
{
    int length, width;
    int **a = nullptr;
    generateMatrix1(a, length, width);
    return 0;
}
void generateMatrix1(int **a, int &length, int &width)
{
    cout << "Enter length, width: ";
    cin >> length >> width;
    a = new int *[length];
    f(i, 0, length)
    {
        a[i] = new int[width];
    }
    f(i, 0, length)
    {
        f(j, 0, width)
        {
            cin >> a[i][j];
        }
    }
    f(i, 0, length)
    {
        f(j, 0, width)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    f(i, 0, length) delete[] *(a + i);
    delete[] a;
}