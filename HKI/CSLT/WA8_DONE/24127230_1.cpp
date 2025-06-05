#include <iostream>
using namespace std;
void triple_it(int *p)
{
    *p = *p * 3;
}
int main()
{
    int n = 15;
    cout << "Val. of n before tripling: " << n << endl;
    triple_it(&n);
    cout << "Val. of n after tripling: " << n;
    return 0;
}