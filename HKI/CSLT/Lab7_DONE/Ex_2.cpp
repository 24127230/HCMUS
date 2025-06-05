#include <iostream>
using namespace std;
int *sum(int *a, int *b);
int main()
{
    int a, b;
    cin >> a >> b;
    int *s = sum(&a, &b);
    cout << *s;
    delete s;
    return 0;
}
int *sum(int *a, int *b)
{
    int *ptr = new int;
    *ptr = *a + *b;
    return ptr;
}