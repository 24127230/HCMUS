#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)                              //viet thuong cac ki tu
    {
        s[i] = tolower(s[i]);
    }
    while (s[0] == ' ') s.erase(0, 1);                              //xoa " " dau string
    while (s[s.size() - 1] == ' ') s.erase(s.size() - 1, 1);        //xoa " " cuoi string
    while (s.find("  ") != string::npos) s.erase(s.find("  "), 1);  //xoa " " du o giu, vd: "  " thi -> " " 
    int pos;                                                        //sau khi chay vong lap string s se xoa het dau " ", pos nay se la vi tri dau tien cua ten
    do
    {
        pos = s.find(" ");
        s.erase(s.find(" "), 1);
    } while (s.find(" ") != string::npos);
    string res = s.substr(pos, s.size() - pos) + "." + s.substr(0, pos) + "@xyz.edu.vn";
    cout << res;
    return 0;
}