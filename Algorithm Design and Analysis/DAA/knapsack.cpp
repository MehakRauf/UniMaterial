#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
};

// Comparator: sort by value/weight ratio (descending)
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items, int n) {
    sort(items.begin(), items.end(), cmp);  // Sort by ratio
    double finalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= W) {
            // Take full item
            W -= items[i].weight;
            finalValue += items[i].value;
        } else {
            // Take fraction of item
            finalValue += items[i].value * ((double)W / items[i].weight);
            break;
        }
    }
    return finalValue;
}

int main() {
    int W = 50; // Max weight
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int n = items.size();

    cout << "Maximum value in Knapsack = " << fractionalKnapsack(W, items, n);
    return 0;
}
