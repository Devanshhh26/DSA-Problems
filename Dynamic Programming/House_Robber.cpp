#include<iostream>
#include<vector>
using namespace std;

int solveRecursion(vector<int>&nums,int n)
{   
    // only 1 house left
    if(n==0)
    {
        return nums[n];
    }
    // no house left
    if(n<0)
    {
        return 0;
    }
    // include
    int include=nums[n]+solveRecursion(nums,n-2);
    // exclude
    int exclude=0+solveRecursion(nums,n-1);

    return max(include,exclude);
}   

int topDownApproach(vector<int>&nums,int n,vector<int>&dp)
{
    if(n==0)
    {
        return nums[n];
    }
    if(n<0)
    {
        return 0;
    }
    // step 3 check if element already present in dp array
    if(dp[n]!=-1)
    {
        return dp[n];
    }
     // include
    int include=nums[n]+topDownApproach(nums,n-2,dp);
    // exclude
    int exclude=0+topDownApproach(nums,n-1,dp);

   // step 2 result ko dp array se replace karo
    dp[n]=max(include,exclude);

    return dp[n];

}

int bottomUpApproach(vector<int>&nums,int n)
{
    vector<int>dp(n+1,-0);
    dp[0]=nums[0];
    for(int i=1;i<=n;i++)
    {   
        int temp=0;
        if(i-2>=0)
        {
            temp=dp[i-2];
        }
        int include=temp+nums[i];
        int exclude=dp[i-1]+0;
        dp[i]=max(include,exclude);     
    }
    return dp[n];  
}

int spaceOptimization(vector<int>&nums,int n)
{
    int prev2=0;
    int prev1=nums[0];
    int curr=0;
    for(int i=1;i<=n;i++)
    {
        int temp=0;
        if(i-2>=0)
        {
            temp=prev2;
        }
        int include=temp+nums[i];
        int exclude=prev1+0;
        curr=max(include,exclude);     
        prev2=prev1;
        prev1=curr;
    }
    return curr;
}


int main()
{   
    // using recursion   
    vector<int>nums{1,2,3,1};
    int n=nums.size()-1;
    int ans=solveRecursion(nums,n);
    cout<<"Recursive ans : "<<ans<<endl;

    // using top down
    //step 1 create dp array
    vector<int>dp(n+1,-1);
    int ansTop=topDownApproach(nums,n,dp);
    cout<<"Top down : "<<ansTop<<endl;
    return 0;
    
}