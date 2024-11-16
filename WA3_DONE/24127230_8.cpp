#include <iostream>
#include <cmath>
using namespace std;
float dis(float a, float b, float a1, float b1)
{
    return sqrt(pow(a - a1, 2) + pow(b - b1, 2));
}
int main()
{
    cout << "Input the first 2-D coordinate: ";
    int x1, y1;
    cin >> x1 >> y1;
    cout << "Input the second 2-D coordinate: ";
    int x2, y2;
    cin >> x2 >> y2;
    cout << "Input the third 2-D coordinate: ";
    int x3, y3;
    cin >> x3 >> y3;
    float A = dis(x2, y2, x3, y3);
    float B = dis(x1, y1, x3, y3);
    float C = dis(x1, y1, x2, y2);
    float sum = A + B + C;
    float Max = max(A, max(B, C));
    if (sum - Max > Max)
    {
        cout << "That is a valid triangle." << endl
             << "That is ";
        if (A == B && A == C)
            cout << "an Equilateral triangle.";
        else if (A == B || A == C || B == C)
            cout << "an Isosceles triangle.";
        else
            cout << "a Scalene triangle.";
    }
    else
        cout << "That isn't a valid triangle.";
    return 0;
}