// two pointer approach use kar lenge
// start aur end pointer use karenge dono ko 0 index se shuru karenge
// hum sabka sum lete chalenge
// agar sum < target hua to end++ kar denge jisse window ka size bada ho jaega aur sum bhi bada ho jaega
// agar sum > = target hua to hum uski length store kar lenge aur start ki value minus kar denge sum se aur fir lenght minimize karne ke lie start ++ kar denge

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
    vector<int> nums{2, 3, 1, 2, 4, 3};
    int target = 7;
    int minLength = INT_MAX;
    int end = 0;
    int start = 0;
    int sum = 0;
    while (end < nums.size())
    {
        // include current number
        sum = sum + nums[end];
        // ek window ka sum ready hai
        while (sum >= target)
        {
            minLength = min(minLength, end - start + 1);
            sum = sum - nums[start];
            start++;
        }
        end++;
    }
    if (minLength == INT_MAX)
    {
        return 0;
    }
    else
    {
        cout<<minLength;
    }
    return 0;
}