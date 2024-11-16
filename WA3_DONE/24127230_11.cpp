#include <iostream>
using namespace std;
int main()
{
    int p, ch, m;
    cout << "Input the marks obtained in Physics: ";
    cin >> p;
    cout << "Input the marks obtained in Chemistry: ";
    cin >> ch;
    cout << "Input the marks obtained in Mathematics: ";
    cin >> m;
    if (m >= 65)
        if (p >= 55)
            if (ch >= 50)
                if ((p + ch + m) >= 180 || (m + p) >= 140)
                {
                    cout << "The candidate is eligible for admission";
                    return 1;
                }
    cout << "The candidate is not eligible for admission";
    return 0;
}