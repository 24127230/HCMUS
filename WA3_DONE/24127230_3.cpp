#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float f1, f2, f3, max_num;
    cout << "Input the three numbers: ";
    cin >> f1 >> f2 >> f3;
    max_num = max(f1, max(f2, f3));
    cout << max_num;
    return 0;
}