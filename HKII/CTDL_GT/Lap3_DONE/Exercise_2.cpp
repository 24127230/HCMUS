#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool is_equal(string a, string b) 
{
    if (a.length() != b.length()) return 0;
    for (int i = 0; i < a.length(); i++)
    {
        if(tolower(a[i]) != tolower(b[i]))
            return 0;
    }
    return 1;
}
int linear_search(vector<pair<string, string>> &a, string target) 
{
    for (int i = 1; i < a.size(); i++) {
        if(is_equal(a[i].first, target))
            return i;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    ifstream fin(".\\English-Vietnamese Dictionary.txt");
    if (!fin.is_open())
    {
        cerr << "Open file data failed!";
        return 0;
    }
    vector<pair<string, string>> data;
    data.push_back({"", ""});
    string line;
    while (getline(fin, line))
    {
        int colon_index = line.find(":");
        string word = line.substr(0, colon_index);
        string definition = line.substr(colon_index + 1, line.length() - colon_index - 1);
        while(definition[0] == ' ') definition.erase(0, 1);
        while(definition[definition.length() - 1] == ' ') definition.erase(definition.length() - 1, 1);
        if (definition[definition.length() - 1] != '.') definition += '.';
        data.push_back(make_pair(word, definition));
    }
    fin.close();
    cout << "Data loaded! Ready to searching...\n";

    // Parse arguments
    string output_path = argv[argc - 1];
    
    // Process
    ofstream fout(output_path);
    if(!fout.is_open()) {
        cerr << "Open file to write failed!";
        return 0;
    }
    for (int i = 1; i < argc - 1; i++)
    {
        string word = argv[i];
        int index = linear_search(data, word);
        if (index == -1)
            fout << word << ": unknown\n";
        else fout << data[index].first << ": " << data[index].second << '\n';
    }
    fout.close();
    return 0;
}