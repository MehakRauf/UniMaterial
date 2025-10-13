#include <iostream>
#include <vector>
using namespace std;

bool subsetSumDFS(vector<int>& nums, int n, int sum) {
    if (sum == 0) return true;      
    if (n == 0) return false;       // No items left and sum not reached

    // If current element is greater than sum, skip it
    if (nums[n - 1] > sum)
        return subsetSumDFS(nums, n - 1, sum);

    // Include current element
    // Exclude current element
    return subsetSumDFS(nums, n - 1, sum - nums[n - 1]) || subsetSumDFS(nums, n - 1, sum);
}

int main() {
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    if (subsetSumDFS(nums, nums.size(), sum))
        cout << "Subset with given sum exists\n";
    else
        cout << "No subset with given sum\n";

    return 0;
}
