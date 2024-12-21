#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    char s[256], check[256];
    cin.getline(s, 256);
    strcpy(check, s);
    char *token = strtok(check, ".");
    int count = 0;
    while (token != NULL)
    {
        int temp = atoi(token);
        if(strlen(token) == 3 && temp < 100)
        {
            cout << "Invalid IP";
            return 0;
        } 
        if (temp < 0 || temp > 255)
        {
            cout << "Invalid IP";
            return 0;
        }
        token = strtok(NULL, ".");
        count++;
    }
    if (count == 4)
    {
        cout << "Valid IP";
        return 0;
    }
    else
    {
        cout << "Invalid IP";
        return 0;
    }
}