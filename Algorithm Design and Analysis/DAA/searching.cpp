#include <iostream>
using namespace std;

int linearSearch(int arr[], int tar, int size)
{

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == tar)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int tar, int size)
{
    int st = 0, end = size - 1;
    while (st <= end)
    {
        int mid = (st + end) / 2;
        if (arr[mid] == tar)
        {
            return mid;
        }
        else if (arr[mid] < tar)
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4,6, 50};
    int tar = 6;
    cout << binarySearch(arr, tar, 5) << endl;
    return 0;
}