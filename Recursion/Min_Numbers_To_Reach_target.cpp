#include <iostream>
#include <vector>
using namespace std;

int minNumber(vector<int> arr, int target)
{
    // if we reach to the sum and dont have to subtract anymore then to create 0 we need zero elements

    if (target == 0)
    {
        return 0;
    }
    if (target < 0)
    {
        return INT16_MAX;
    }
    int mini = INT16_MAX;

    // calling for each elements of the array

    for (int i = 0; i < arr.size(); i++)
    {
        int ans = minNumber(arr, target - arr[i]);
        if (ans != INT16_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }
    return mini;
}

int main()
{
    vector<int> arr{1, 2};
    int target = 5;
    int ans = minNumber(arr, target);
    cout << ans;
    return 0;
}