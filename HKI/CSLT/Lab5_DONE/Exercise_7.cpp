#include <iostream>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    int vowel = 0, consonant = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (tolower(s[i]) > 'a' && tolower(s[i]) < 'z')
            switch (tolower(s[i]))
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vowel++;
                break;
            default:
                consonant++;
                break;
            }
    }
    cout << "Vowels: " << vowel << ", Consonant: " << consonant;
    return 0;
}