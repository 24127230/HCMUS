#include <iostream>
#include <string>
using namespace std;

string res = "";

void GenerateBinString(int index, int &n) {
    if(index == n){
        cout << res << '\n';
        return;
    }
    for (int i = 0; i <= 1; i++){
        res += char('0' + i);
        GenerateBinString(index + 1, n);
        res = res.substr(0, index);
    }
}

int main()
{
    int n; 
    cin >> n;
    GenerateBinString(0, n);
    return 0;
}