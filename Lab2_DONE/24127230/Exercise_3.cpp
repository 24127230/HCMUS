#include <iostream>
using namespace std;
#include <cmath>
int main()
{
    float a, b, c;
    cin >> a >> b >> c;
    if(a != 0)
    {
        float delta = pow(b,2) - (4 * a * c);
        if(delta < 0) cout << "No solutions";
        else if(delta > 0)
        {
            float x1, x2;
            x1 = (-b - sqrt(delta)) / (2 * a);
            x2 = (-b + sqrt(delta)) / (2 * a);
            cout << x2 << " " << x1;
        }
        else cout << (float) (-b) / (2 * a);
    }
    else
    {
        if(b == 0) 
        {
            if(c == 0) cout << "Any solutions";
            else cout << "No solutions";
        }
        else cout << (float) (-c) / b;
    }
    return 0;
}