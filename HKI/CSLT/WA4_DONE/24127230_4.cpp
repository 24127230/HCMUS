#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long n = 600851475143, maxpf = 0;
    for (long long index = 2; index <= sqrt(n); index++)
    {
        while (n % index == 0)
        {
            n /= index;
            maxpf = (index > maxpf) ? index : maxpf;
        }
    }
    maxpf = (n > maxpf) ? n : maxpf;
    cout << "Max: " << maxpf;
    return 0;
}