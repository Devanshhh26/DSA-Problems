#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int lowerBound(vector<int> &arr, int x)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    int ans = e;
    while (s <= e)
    {
        if (arr[mid] >= x)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    vector<int> arr{1, 2, 4, 6, 8, 34, 56, 89, 90};
    int x = 6;
    int high = lowerBound(arr, x);
    int low = high - 1;
    vector<int> res;
    int k = 4;
    while (k--)
    {
        if (low < 0)
        {
            high++;
        }
        else if (high >= arr.size())
        {
            low--;
        }
        else if (x - arr[low] > arr[high] - x)
        {
            high++;
        }
        else
        {
            low--;
        }
    }
    for (int i = low + 1; i <= high - 1; i++)
    {
        res.push_back(arr[i]);
    }
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}