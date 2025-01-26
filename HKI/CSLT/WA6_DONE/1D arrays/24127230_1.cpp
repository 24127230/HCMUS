#include <iostream>
#include <string>
using namespace std;
const int N = 1e4 + 5;
void input_1Darray(int a[], int &n)
{
    int x;
    cin >> x;
    int i = 0;
    while (x)
    {
        a[i] = x % 10;
        i++;
        x /= 10;
    }
    n = i;
}
void sum_1Darray(int a[], int na, int b[], int nb, int sum[], int &nsum)
{
    int borrow = 0;
    nsum = (na >= nb) ? na : nb;
    for (int i = 0; i < nsum; i++)
    {
        int t = a[i] + b[i] + borrow;
        sum[i] = t % 10;
        borrow = t / 10;
    }
    if (borrow == 1)
    {
        sum[nsum] = borrow;
        nsum++;
    }
}
void mul_1Darray(int a[], int na, int b[], int nb, int mul[], int &nmul)
{
    for (int i = 0; i < nb; i++)
    {
        int s1[N] = {0}, n = 0;
        for (int j = 0; j < b[i]; j++)
            sum_1Darray(s1, n, a, na, s1, n);
        for (int j = n + i - 1; j >= 0; j--)
        {
            if (j >= i)
                s1[j] = s1[j - i];
            else
                s1[j] = 0;
        }
        n += i;
        sum_1Darray(s1, n, mul, nmul, mul, nmul);
    }
}
void _1Darray()
{
    cout << "1. 1D arrays\n";
    int a[N], na;
    cout << "Enter first integer:\n";
    input_1Darray(a, na);
    int b[N], nb;
    cout << "Enter second integer:\n";
    input_1Darray(b, nb);
    int c[N] = {0}, nc, d[N] = {0}, nd;
    sum_1Darray(a, na, b, nb, c, nc);
    cout << "Sum: ";
    for (int j = nc - 1; j >= 0; j--)
        cout << c[j];
    mul_1Darray(a, na, b, nb, d, nd);
    cout << "\nMultiplication: ";
    for (int j = nd - 1; j >= 0; j--)
        cout << d[j];
    cout << endl;
}
void input_string(string &s) { cin >> s; }
void swap_char(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}
void rev_string(string &s)
{
    int l = 0;
    int r = s.length() - 1;
    while (l < r)
    {
        swap_char(s[l], s[r]);
        l++;
        r--;
    }
}
void add_0(string &a, int n)
{
    int t = n - a.length();
    for (int i = 0; i < t; i++)
        a += "0";
}
void sum_string(string x, string y, string &sum)
{
    int borrow = 0;
    sum.clear();
    rev_string(x);
    rev_string(y);
    if (x.length() > y.length())
        add_0(y, x.length());
    else
        add_0(x, y.length());
    for (int i = 0; i < x.length(); i++)
    {
        int t = int(x[i]) - 48 + int(y[i]) - 48 + borrow;
        sum += char(t % 10 + 48);
        borrow = t / 10;
    }
    if (borrow == 1)
        sum += '1';
    rev_string(sum);
}
void mul_string(string x, string y, string &mul)
{
    mul.clear();
    rev_string(y);
    for (int i = 0; i < y.length(); i++)
    {
        string sub_mul = "0";
        for (int j = 0; j < char(y[i]) - 48; j++)
        {
            sum_string(sub_mul, x, sub_mul);
        }
        add_0(sub_mul, sub_mul.length() + i);
        sum_string(mul, sub_mul, mul);
    }
}
void _string()
{
    cout << "2. Strings\n";
    string a;
    cout << "Enter first integer:\n";
    input_string(a);
    string b;
    cout << "Enter second integer:\n";
    input_string(b);
    string c, d;
    sum_string(a, b, c);
    cout << "Sum: " << c;
    mul_string(a, b, d);
    cout << "\nMultiplication: " << d;
}
int main()
{
    _1Darray();
    _string();
    return 0;
}