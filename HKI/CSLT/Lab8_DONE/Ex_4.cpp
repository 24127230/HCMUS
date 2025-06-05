#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    if (!fin.is_open())
    {
        cout << "Cannot open file!";
        return 1;
    }
    string line;
    int count = 0;
    while (getline(fin, line))
    {
        while (line[0] == ' ')
            line.erase(0, 1);
        while (line[line.length() - 1] == ' ')
            line.erase(line.length() - 1, 1);
        {
            int i = 0;
            while (i < line.length())
            {
                if (line[i] != ' ' && (tolower(line[i]) < 'a' || tolower(line[i]) > 'z'))
                    line.erase(i, 1);
                else
                    i++;
            }
        }
        line += ' ';
        for (int i = 1; i < line.length(); i++)
        {
            if (line[i] == ' ')
                if (tolower(line[i - 1]) >= 'a' && tolower(line[i - 1] <= 'z'))
                {
                    count++;
                }
        }
    }
    fout << count;
    fin.close();
    fout.close();
}