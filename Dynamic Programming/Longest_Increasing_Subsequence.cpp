//  https://leetcode.com/problems/longest-increasing-subsequence/

#include<iostream>
#include<vector>
using namespace std;

  int solveRecursion(vector<int>nums,int curr,int prev)
    {
        if(curr==nums.size())
        {
            return 0;
        }
        // include
        int include=0;
        if(prev==-1  ||   nums[prev]<nums[curr])    // hum tab hi include karenge agar hum 0 index pe honge ya prev element chota hoga curr se
        {
            include=1+solveRecursion(nums,curr+1,curr);         // curr ko aage badha denge aur prev ko curr bana denge
        }
        // exclude
        int exclude=0+solveRecursion(nums,curr+1,prev);
        
        int ans=max(include,exclude);
        return ans;
        
    }

int solveTopDown(vector<int>&nums,int curr,int prev,vector<vector<int>>&dp)
    {
        if(curr>=nums.size())
        {
            return 0;
        }
        if(dp[curr][prev+1]!=-1)
        {
            return dp[curr][prev+1];
        }
        // include
        int include=0;
        if(prev==-1  ||   nums[prev]<nums[curr])    // hum tab hi include karenge agar hum 0 index (array empty) pe honge ya prev element chota hoga curr se
        {
            include=1+solveTopDown(nums,curr+1,curr,dp);         // curr ko aage badha denge aur prev ko curr bana denge
        }
        // exclude
        int exclude=0+solveTopDown(nums,curr+1,prev,dp);
        
        int ans=max(include,exclude);
        dp[curr][prev+1]=ans;           // +1 islie kia hai kyoki prev -1 se inititalize kia hai aur -1 valid index nahi hai 
        return dp[curr][prev+1];
}

int solveBottomUp(vector<int>nums)
{
    vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0));
    for(int curr=nums.size()-1;curr>=0;curr--)
    {
        for(int prev=curr-1;prev>=-1;prev--)
        {
        int include=0;
        if(prev==-1  ||   nums[prev]<nums[curr])    // hum tab hi include karenge agar hum 0 index (array empty) pe honge ya prev element chota hoga curr se
        {
            include=1+dp[curr+1][curr+1];         // curr ko aage badha denge aur prev ko curr bana denge
        }
        // exclude
        int exclude=0+dp[curr+1][prev+1];
        
        int ans=max(include,exclude);
        dp[curr][prev+1]=ans;           // +1 islie kia hai kyoki prev -1 se inititalize kia hai aur -1 valid index nahi hai 
        }
    }
    return dp[0][-1+1];
}

int main()
{   
    vector<int>nums{10,9,2,5,3,7,101,18};
    int curr=0;
    int prev=-1;
    int ans=solveRecursion(nums,curr,prev);
    cout<<"Recurision : "<<ans<<endl;

    vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
    int ansTop=solveTopDown(nums,curr,prev,dp);
    cout<<"Top Down : "<<ansTop<<endl;

    int ansBottom=solveBottomUp(nums);
    cout<<"Bottom Up  : "<<ansBottom<<endl;
}