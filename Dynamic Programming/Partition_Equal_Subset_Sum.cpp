//https://leetcode.com/problems/partition-equal-subset-sum/


#include <iostream>
#include <vector>
using namespace std;

bool solveRecursion(int index, vector<int> nums, int target)
{
    // index is more than size of nums
    int n = nums.size();
    if (index >= n)
    {
        return false;
    }
    // if we find the target value
    if (target == 0)
    {
        return true;
    }
    // if the target value is negative
    if (target < 0)
    {
        return false;
    }
    // include
    bool include = solveRecursion(index + 1, nums, target - nums[index]);
    // exclude
    bool exclude = solveRecursion(index + 1, nums, target);
    // if even one of them is true return true
    if (include || exclude)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool solveTopDown(int index,vector<int>&nums,int target,vector<vector<int>>&dp)
{
    int n = nums.size();
    if (index >= n)
    {
        return false;
    }
    // if we find the target value
    if (target == 0)
    {
        return true;
    }
    // if the target value is negative
    if (target < 0)
    {
        return false;
    }
    if(dp[index][target]!=-1)
    {
        return dp[index][target];
    }
    // include
    bool include = solveTopDown(index + 1, nums, target - nums[index],dp);
    // exclude
    bool exclude = solveTopDown(index + 1, nums, target,dp);
    // if even one of them is true return true
    dp[index][target]=(include || exclude);
    if (dp[index][target])
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool solveBottomUp(vector<int> &nums, int target)
{
    vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, 0));
    // top down ke bsae case se dekha ki target == 0  me true store karna hai which means 0th column me 1 store karna hai
    // kyoki target column ko represent kar raha hai
    for (int i = 0; i < nums.size(); i++)
    {
        dp[i][0] = 1;
    }
    // i ko index ke ulta chalo aur t ko target ke ulta chalao
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        for (int t = 1; t <= target; t++)
        {   
            // t-nums[i] <0 ja sakta hai to islie pehle check karlo
            bool include = 0;
            if (t - nums[i] >= 0)
                include = dp[i + 1][t - nums[i]];

            bool exclude = dp[i + 1][t];

            dp[i][t] = (include || exclude);
        }
    }
    if (dp[0][target])
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool spaceOptimization(vector<int>&nums,int target)
{   
    // we only need two 1d vectors instead of one 2d vector because the answer depends on the curr and next row
    
    vector<bool>curr(target+1,0);
    vector<bool>next(target+1,0);

    next[0]=1;
    curr[0]=1;
    // i ko index ke ulta chalo aur t ko target ke ulta chalao
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        for (int t = 1; t <= target; t++)
        {   
            // t-nums[i] <0 ja sakta hai to islie pehle check karlo
            bool include = 0;
            if (t - nums[i] >= 0)
                include = next[t - nums[i]];

            bool exclude =next[t];

            curr[t] = (include || exclude);
        }
        next=curr;

    }
   return next[target];
}

int main()
{
    vector<int> nums{1, 5, 11, 5};
    int sum = 0;
    int target = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum = sum + nums[i];
    }
    // odd sum return 0 since odd numbers cannot be divided into two parts
    if (sum % 2 != 0)
    {
        return false;
    }
    target = sum / 2;
    int index = 0;
    bool ans = solveRecursion(index, nums, target);
    cout<<"Recursion : "<<ans<<endl;

    vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
    bool ansTop=solveTopDown(index,nums,target,dp);
    cout<<"Top Down : "<<ansTop<<endl;

    bool ansBottom=solveBottomUp(nums,target);
    cout<<"Bottom Up : "<<ansBottom<<endl;

    bool ansSO=spaceOptimization(nums,target);
    cout<<"Space Optimization : "<<ansSO<<endl;

    

}