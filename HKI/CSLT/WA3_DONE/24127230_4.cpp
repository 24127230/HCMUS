#include <iostream>
#include <cctype>
using namespace std;
int main()
{
    char Char;
    cout << "Input an alphabet: ";
    cin >> Char;
    Char = tolower(Char);
    cout << "The alphabet is a ";
    switch (Char)
    {
    case 'a': // a
    case 'e': // e
    case 'i': // i
    case 'o': // o
    case 'u': // u
        cout << "vowel.";
        break;
    default:
        cout << "consonant.";
        break;
    }
    return 0;
}