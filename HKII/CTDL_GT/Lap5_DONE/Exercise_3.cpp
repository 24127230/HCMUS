#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct data_can
{
    string name;
    double avg, t1, t2;
    string opts;
};

bool is_smaller_than(data_can a, data_can b)
{
    if (a.avg == b.avg)
    {
        if (a.t1 == b.t1)
            return bool(a.t2 < b.t2);
        return bool(a.t1 < b.t1);
    }
    return bool(a.avg < b.avg);
}

void insertion_sort(vector<data_can> &a, int n)
{
    for (int i = 1; i < n; i++)
    {
        data_can key = a[i];
        int j = i - 1;
        while (a[j].avg < key.avg && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    ifstream fin("exam.txt");
    if (!fin.is_open())
    {
        cerr << "Can not open file to read!";
        return 0;
    }
    int m;
    fin >> m;
    vector<int> option(m + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        fin >> x >> y;
        option[x] = y;
    }

    string line;
    getline(fin, line);
    vector<data_can> a;
    while (getline(fin, line))
    {
        data_can tmp;
        int i_line = line.find(",");
        tmp.name = line.substr(0, i_line);
        tmp.name.erase(0,1);
        tmp.name.erase(tmp.name.size() - 1,1);
        line.erase(0, i_line + 1);

        i_line = line.find(",");
        tmp.t1 = stod(line.substr(0, i_line));
        line.erase(0, i_line + 1);

        i_line = line.find(",");
        tmp.t2 = stod(line.substr(0, i_line));
        line.erase(0, i_line + 1);

        tmp.opts = line;

        tmp.avg = (tmp.t1 + tmp.t2) / 2.0;
        // tmp.avg = int(tmp.avg * 100) / 100.0;
        a.push_back(tmp);
    }
    insertion_sort(a, a.size());

    vector<vector<data_can>> res(m + 1);
    for (int i = 0; i < a.size(); i++)
    {
        a[i].opts += ",";
        bool have_opt = 0;
        int index = 0;
        while(index++ < m) {
            int i_line = a[i].opts.find(",");
            // cout << stoi(a[i].opts.substr(0, i_line)) << ' ';
            int opt = stoi(a[i].opts.substr(0, i_line));
            if (option[opt]) {
                option[opt]--;
                res[opt].push_back(a[i]);
                have_opt = 1;
                break;
            }
            a[i].opts.erase(0, i_line + 1);
        }
        // if (!have_opt) res[0].push_back(a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        cout << "Successful candidates for option " << i << "\n";
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << j + 1 << ". " << res[i][j].name << " " << res[i][j].avg << '\n';
        }
        
    }
    cout << "Unsuccessful candidates\n";
    for (int j = 0; j < res[0].size(); j++)
    {
        cout << j + 1 << ". " << res[0][j].name << " " << res[0][j].avg << '\n';
    }
    
    return 0;
}
/*

*/