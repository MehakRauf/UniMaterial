#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int taxiRoutingProblem(vector<vector<int>> &rides, int index, int fare)
{
    // Base case
    if (index == rides.size())
        return fare;

    int maxIncome = 0;
    for (int nextFare : rides[index])
    {
        maxIncome = max(maxIncome, taxiRoutingProblem(rides, index + 1, fare + nextFare));
    }

    return maxIncome;
}

int main()
{
    vector<vector<int>> rides = {
        {100},       
        {150},       
        {180, 140},  
        {250, 300}   
    };

    cout << "Maximum Fare: " << taxiRoutingProblem(rides, 0, 0);
    return 0;
}
