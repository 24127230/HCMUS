#include <iostream>
#include <string>

using namespace std;

struct abc {
    int s1, s2;
};
int main() {
    abc a = {1, 2};
    abc b = {3, 4};
    b = a;
    cout << a.s1;
    return 0;
}