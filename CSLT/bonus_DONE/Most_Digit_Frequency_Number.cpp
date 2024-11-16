#include <iostream>
using namespace std;
int digit_frequency_analysis(int x, int y);
int count_dif_digit(int x)
{
    int cnt = 0;
    int tmp = x; // tmp 102
    while (x > 0)
    {
        int digit = x % 10, check = 0;
        cnt++;
        int t = x;
        while (t > 0)
        {
            if (digit == t % 10)
                check++;
            t /= 10;
        }
        cnt -= (check - 1);
        x /= 10;
    }
    return cnt;
}
int main()
{
    int a, b;
    // cout << count_dif_digit(123452);
    cin >> a >> b;
    int res = digit_frequency_analysis(a, b);
    cout << res;
}
int digit_frequency_analysis(int x, int y)
{
    int max = -1, value;
    for (int index = x; index <= y; index++)
    {
        if (max < count_dif_digit(index))
        {
            // cout << index << " " << count_dif_digit(index) << endl;
            max = count_dif_digit(index);
            value = index;
        }
    }
    return value;
}
