#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cout << "Enter integer a: ";
    cin >> a;
    cout << "Enter integer b: ";
    cin >> b;
    int *ptrA = &a;
    int *ptrB = &b;
    cout << "The value of ptrA: " << ptrA << endl;
    cout << "The value dereferenced by ptrA: " << *ptrA << endl;
    cout << "The value of ptrB: " << ptrB << endl;
    cout << "The value dereferenced by ptrB: " << *ptrB << endl;
    return 0;
}
