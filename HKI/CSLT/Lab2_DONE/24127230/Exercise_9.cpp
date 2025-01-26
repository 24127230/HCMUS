#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    if (a % 10 == 0)
        cout << "No reverse number";
    else
    {
        while (a) // print reverse digit of num
        {
            cout << a % 10;
            a /= 10;
        }
        /*int new_num = 0; // make a reverse num
        while (a)
        {
            new_num += (a % 10);
            new_num *= 10;
            a /= 10;
        }
        new_num /= 10;
        cout << new_num;*/
    }
    return 0;
}