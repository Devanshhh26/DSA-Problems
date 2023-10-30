//https://leetcode.com/problems/coin-change/

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solveUsingRecursion(vector<int>&coins,int amount)
{
    if(amount==0)
    {
        return 0;
    }
    if(amount<0)
    {
        return INT16_MAX;
    }
    int mini=INT_MAX;
    for(int i=0;i<coins.size();i++)
    {
        int ans=solveUsingRecursion(coins,amount-coins[i]);
        if(ans!=INT_MAX)
        {
            mini=min(mini,ans+1);
        }
    }
    return mini;
}

int topDownApproach(vector<int>&coins,int amount,vector<int>&dp)
{
    if(amount==0)
    {
        return 0;
    }
    if(amount<0)
    {
        return INT16_MAX;
    }
    if(dp[amount]!=-1)
    {
        return dp[amount];
    }
    int mini=INT16_MAX;
    for(int i=0;i<coins.size();i++)
    {
        int ans=topDownApproach(coins,amount-coins[i],dp);
        if(ans!=INT16_MAX)
        {
            mini=min(mini,1+ans);
        }
    }
    dp[amount]=mini;
    return dp[amount];
}

int bottomUpApproach(vector<int>coins,int amount)
{   
    // step 1 : dp array banao
    vector<int>dp(amount+1,INT_MAX);
    // step 2 : base case dekho
    dp[0]=0;
    // step 3: check the range  and flow of top down  approach accordingly
    for(int target=1;target<=amount;target++)
    {   
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++)
        {   
            if(target-coins[i]>=0 && dp[target-coins[i]]!=INT_MAX)
            {
                int ans=dp[target - coins[i]];
                if(ans!=INT_MAX)
                {
                    mini=min(mini,1+ans);
                }
            }
        }
        dp[target]=mini;
    }
    return dp[amount];
}

int main()
{   
    vector<int>coins{1,2,5};
    int amount=11;
    // method 1 using recursion
    int ans=solveUsingRecursion(coins,amount);
    if(ans==INT_MAX)
    {
        return -1;
    }
    cout<<"Recursive Answer is : "<<ans<<endl;
    
    // method 2 using top down approach
    vector<int>dp(amount+1,-1);
    int ansTop=topDownApproach(coins,amount,dp);
    if(ansTop==INT_MAX)
    {
        return -1;
    }
    cout<<"Top answer is : "<<ansTop<<endl;

    // method 3 using bottom up approach
    int ansBottom=bottomUpApproach(coins,amount);
    if(ansBottom==INT_MAX)
    {
        return -1;
    }
    cout<<"Bottom answer is : "<<ansBottom<<endl;
    
}
