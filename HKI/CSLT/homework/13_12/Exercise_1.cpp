#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct info
{
    string fname, lname;
    int math, literature, physic;
};
void delete_space(string &s)
{
    int i = 0;
    while (i < s.length())
    {
        if (s[i] == ' ')
            s.erase(i, 1);
        else
            i++;
    }
}
int main()
{
    ifstream in("Text.txt");
    if (!in.is_open())
    {
        cout << "Open file for read fail!";
    }
    else
    {
        int n;
        in >> n;
        in.ignore();
        info *a = new info[n];
        int index = 0;
        while (index < n)
        {
            string data;
            getline(in, data);
            int start = 0;
            int end = 0;
            end = data.find(',', start); // ten
            a[index].fname = data.substr(start, end - start);
            start = end + 1;

            end = data.find(',', start); // toan
            a[index].math = stoi(data.substr(start, end - start));
            start = end + 1;

            end = data.find(',', start); // van
            a[index].literature = stoi(data.substr(start, end - start));
            start = end + 1;

            end = data.find(',', start); // ly
            a[index].physic = stoi(data.substr(start, end - start));
            start = end + 1;

            index++;
        }
        in.close();
        for (int i = 0; i < n; i++)
        {
            cout << "First Name: " << a[i].fname << endl;
            cout << "Last Name: " << a[i].lname << endl;
            cout << "Math Score: " << a[i].math << endl;
            cout << "Literature Score: " << a[i].literature << endl;
            cout << "Physics Score: " << a[i].physic << endl
                 << endl;
        }
    }
}