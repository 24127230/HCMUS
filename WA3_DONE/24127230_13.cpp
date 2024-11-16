#include <iostream>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    if (s1 == "scissors")
    {
        if (s2 == "scissors")
            cout << "Draw!";
        if (s2 == "rock")
            cout << "Player 2 won!";
        if (s2 == "paper")
            cout << "Player 1 won!";
    }
    else if (s1 == "rock")
    {
        if (s2 == "rock")
            cout << "Draw!";
        if (s2 == "paper")
            cout << "Player 2 won!";
        if (s2 == "scissors")
            cout << "Player 1 won!";
    }
    else if (s1 == "paper")
    {
        if (s2 == "paper")
            cout << "Draw!";
        if (s2 == "scissors")
            cout << "Player 2 won!";
        if (s2 == "rock")
            cout << "Player 1 won!";
    }
    return 0;
}