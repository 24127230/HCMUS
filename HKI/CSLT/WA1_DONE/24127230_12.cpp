#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Please enter a number: ";
    cin >> n;
    cout << "Sum of the number 1 to " << n << " is: " << n * (n + 1) / 2;
    return 0;
}