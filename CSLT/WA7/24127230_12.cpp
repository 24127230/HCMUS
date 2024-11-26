#include <iostream>
using namespace std;
int main()
{
    char a[] = "A string.";
    char *ptr = a;
    cout << *ptr << " " << &ptr << " " << *(ptr + 3) << endl;
    ptr = ptr + 2;
    cout << *(ptr + 2) << " " << *(ptr + 5);
    return 0;
}