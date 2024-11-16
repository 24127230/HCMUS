#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    float a, b, c;
    cin >> a >> b >> c; 
    if((a + b + c) - max(a,max(b,c)) <= max(a,max(b,c))) cout << "Not a triangle";
    else if (a == b || a == c || b == c)
    {
        if(a == b && a == c) cout << "Equilateral triangle";
        else if((a*a + b*b + c*c) - max(a,max(b,c)) * max(a,max(b,c)) == max(a,max(b,c)) * max(a,max(b,c))) cout << "Right isosceles triangle";
        else cout << "Isosceles triangle";
    }
    else if ((a*a + b*b + c*c) - max(a,max(b,c)) * max(a,max(b,c)) == max(a,max(b,c)) * max(a,max(b,c))) cout << "Right triangle";
    else cout << "Regular triangle";
    
    return 0;
}