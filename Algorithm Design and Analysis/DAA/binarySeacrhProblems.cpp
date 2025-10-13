#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int> arr, int tar)
{
    int st = 0, end = arr.size() - 1;
    int result = -1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (arr[mid] == tar)
        {
            result = mid;
            end = mid - 1;
        }
        else if (arr[mid] < tar)
        {
            st++;
        }
        else
        {
            end--;
        }
    }
    return result;
}

int insertPosition(vector<int> arr, int insertElement)
{
    int st = 0, end = arr.size() - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (arr[mid] == insertElement)
        {
            return mid;
        }
        else if (arr[mid] < insertElement)
        {
            st++;
        }
        else
        {
            end--;
        }
    }
    return st;
}

int main()
{
    vector<int> arr = {1, 3, 3, 3, 4, 5};
    int ans = insertPosition(arr, 2);
    cout << "Element should be inserted at: " << ans;
    return 0;
}