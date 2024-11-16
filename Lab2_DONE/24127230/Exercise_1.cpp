#include <iostream>
using namespace std;
int main()
{
    float score;
    cin >> score;
    if(score <= 10 && score >= 8) cout << "A";
    else if(score >= 6) cout << "B";
    else if(score >= 5) cout << "C";
    else if(score >= 3) cout << "D";
    else cout << "F";
    return 0;
}