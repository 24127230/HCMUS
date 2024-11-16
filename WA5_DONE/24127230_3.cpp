#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e4 + 5;
struct term
{
    int Exponent, Coefficient;
};
struct UnivariatePolynomial
{
    int NumTerm = 0;
    struct term t[N];
};
bool CompareExponentOfTwoTerm(term a, term b)
{
    return a.Exponent > b.Exponent;
}
UnivariatePolynomial getUP()
{
    UnivariatePolynomial a;
    int x;
    cout << "Enter univariate polynomial:\nType 1 to enter term, type 0 to finish:\n";
    while (cin >> x)
    {
        if (x == 0)
            break;
        a.NumTerm++;
        cout << "Exponent(bac): ";
        cin >> a.t[a.NumTerm].Exponent;
        cout << "Coefficient(he so): ";
        cin >> a.t[a.NumTerm].Coefficient;
        cout << "---" << endl;
    }
    cout << "Finish\n";
    return a;
}
void printUP(UnivariatePolynomial a)
{
    sort(a.t + 1, a.t + a.NumTerm + 1, CompareExponentOfTwoTerm);
    for (int i = 1; i <= a.NumTerm; i++)
    {
        // cout << a.t[i].Coefficient << " " << a.t[i].Exponent << endl;
        if (a.t[i].Exponent == 0)
            cout << a.t[i].Coefficient;
        else if (a.t[i].Exponent == 1)
            cout << a.t[i].Coefficient << "x";
        else
            cout << a.t[i].Coefficient << "x^" << a.t[i].Exponent;
        if (i != a.NumTerm)
            cout << " + ";
    }
}
void addition()
{
    UnivariatePolynomial a, b;
    a = getUP();
    b = getUP();
    UnivariatePolynomial add;
    add = a;
    int check[N] = {0};
    for (int i = 1; i <= add.NumTerm; i++)
    {
        check[add.t[i].Exponent] = i;
    }
    for (int i = 1; i <= b.NumTerm; i++)
    {
        if (check[b.t[i].Exponent] == 0) // chua co, them vao add
        {
            add.NumTerm++;
            add.t[add.NumTerm].Exponent = b.t[i].Exponent;
            add.t[add.NumTerm].Coefficient = b.t[i].Coefficient;
        }
        else // da co
        {
            add.t[check[b.t[i].Exponent]].Coefficient += b.t[i].Coefficient;
        }
    }
    cout << "Addition of two polynomials: \n";
    printUP(add);
}
int main()
{
    addition();
    return 0;
}