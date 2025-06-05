#include <iostream>
using namespace std;
int main()
{
    int cap, on, wait;
    cout << "cap = ";
    cin >> cap;
    cout << "on = ";
    cin >> on;
    cout << "wait = ";
    cin >> wait;
    int freespace = cap - on - wait;
    if (freespace >= 0)
        cout << "He can fit all " << wait << " passengers";
    else
        cout << "He can't fit " << -(freespace) << " of the " << wait << " waiting";
    return 0;
}