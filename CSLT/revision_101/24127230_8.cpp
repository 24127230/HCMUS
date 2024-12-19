#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool is_greater(string a, string b)
{
    int len = (a.length() <= b.length()) ? a.length() : b.length();
    for (int i = 0; i < len; i++)
    {
        if (tolower(a[i]) < tolower(b[i]))
            return 0;
        else if (tolower(a[i]) > tolower(b[i]))
            return 1;
    }
    return a.length() > b.length();
}
int main()
{
    ifstream fi("data.csv");
    if (!fi.is_open())
    {
        cout << "Open file to read fail!";
        return 0;
    }
    string line;
    string a[100][100];
    int row = 0, col = 0;
    while (getline(fi, line))
    {
        line = line + ';';
        int s = 0, e = 0;
        col = 0;
        while ((e = line.find(';', s)) != string::npos)
        {
            a[row][col] = line.substr(s, e - s);
            s = e + 1;
            col++;
        }
        row++;
    }
    fi.close();
    for (int i = 0; i < col; i++)
    {
        for (int j = i + 1; j < col; j++)
        {
            if (is_greater(a[0][i], a[0][j]))
            { // swap column
                for (int z = 0; z < row; z++)
                {
                    string temp = a[z][i];
                    a[z][i] = a[z][j];
                    a[z][j] = temp;
                }
            }
        }
    }
    ofstream fo("data.csv");
    if(!fo.is_open())
    {
        cout << "Open file to write fail!\n";
        return 0;
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            fo << a[i][j] << ((j < col - 1) ? ";" : "");
        }
        fo << ((i < row - 1) ? "\n" : "");
    }
    fo.close();
    return 0;
}
