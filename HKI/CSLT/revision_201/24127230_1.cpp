#include <iostream>
using namespace std;
struct Job
{
    std::string id; // Job Id
    int dead;       // Deadline of the job
    int profit;     // Profit if the job is done before or on the deadline
};
int main()
{
    int n;
    cin >> n;
    Job *a = new Job[n];
    for (int i = 0; i < n; i++)
    {
        getline(cin, a[i].id);
        cin >> a[i].dead >> a[i].profit;
    }
    
    return 0;
}