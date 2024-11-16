#include <iostream>
#include <cstdlib> // srand() va rand()
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
    int SecretNumber = rand() % 20 + 1; // random tu 1 den 20
    int Guess;
    int LastGuess = -1;
    int cnt = 0;
    cout << "It's GUESSING GAME " << '\n';
    while (1)
    {
        cout << "Enter your guess: ";
        cin >> Guess;
        if (Guess == LastGuess)
        {
            cout << "You've already guessed that. Try something else!" << '\n';
            continue; // skip lan doan nay
        }
        cnt++; // dem so lan doan
        LastGuess = Guess;
        if (Guess < SecretNumber)
            cout << "Too small!" << '\n';
        else if (Guess > SecretNumber)
            cout << "Too large!" << '\n';
        else
        {
            cout << "Congratulations, you've guessed the number " << SecretNumber << '\n';
            cout << "It took you " << cnt << " tries";
            break;
        }
    }
    return 0;
}