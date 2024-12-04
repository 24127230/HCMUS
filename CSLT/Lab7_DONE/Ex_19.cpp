#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
int **findSubmatrix(int **a, int length, int width,
                    int subLength, int subWidth);
int main()
{
    cout << "Enter matrix: ";
    int n, m;
    cin >> n >> m;
    int **a = new int *[n];
    f(i, 0, n)
    {
        a[i] = new int[m];
        f(j, 0, m) cin >> a[i][j];
    }
    cout << "Enter size submatrix: ";
    int subn, subm;
    cin >> subn >> subm;
    int **suba = findSubmatrix(a, n, m, subn, subm);
    f(i, 0, subn)
    {
        f(j, 0, subm) cout << suba[i][j] << " ";
        cout << endl;
        delete[] suba[i];
    }
    delete[] suba;

    f(i, 0, n) delete[] a[i];
    delete[] a;

    return 0;
}
int **findSubmatrix(int **a, int length, int width,
                    int subLength, int subWidth)
{
    int **s = new int *[length];
    f(i, 0, length)
    {
        s[i] = new int[width];
        f(j, 0, width)
        {
            s[i][j] = a[i][j];
            if (i != 0 && j != 0)
                s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            if (i != 0 && j == 0)
                s[i][j] += s[i - 1][j];
            if (i == 0 && j != 0)
                s[i][j] += s[i][j - 1];
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
    int max = 0, subi, subj;
    f(i, subLength - 1, length)
    {
        f(j, subWidth - 1, width)
        {
            int t = s[i][j];
            if (i != subLength - 1 && j != subWidth - 1) //
                t -= (s[i - subLength][j] + s[i][j - subWidth] - s[i - subLength][j - subWidth]);
            if (i != subLength - 1 && j == subWidth - 1)
                t -= s[i - subLength][j];
            if (i == subLength && j != subWidth)
                t -= s[i][j - subWidth];
            if (t > max)
            {
                max = t;
                subi = i - subLength + 1;
                subj = j - subWidth + 1;
            }
        }
    }
    f(i, 0, length) delete[] s[i];
    delete[] s;
    int **res = new int *[subLength];
    f(i, 0, subLength)
    {
        res[i] = new int[subWidth];
        f(j, 0, subWidth) res[i][j] = a[i + subi][j + subj];
    }
    return res;
}