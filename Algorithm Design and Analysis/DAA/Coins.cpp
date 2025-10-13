#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void coinProblem(int amount, vector<int> coin)
{
    sort(coin.rbegin(), coin.rend());
    while (amount > 0)
    {
        bool paidSomething = false;
        for (int c : coin)
        {
            if (c <= amount)
            {
                amount -= c;
                paidSomething = true;
                cout << "Paid " << c << " remaining is " << amount << endl;
                break;
            }
        }
        if (!paidSomething)
        {
            cout << "Cannot pay the amount with given coins" << endl;
            return;
        }
    }
}
int main()
{
    coinProblem(50, {1, 5, 10, 20, 25});
    return 0;
}