//  https://leetcode.com/problems/guess-number-higher-or-lower-ii/

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solveRecursion(int start,int end)
{
    if (start>=end)
    {
        return 0;
    }
    int ans=INT_MAX;
    for(int i=start;i<=end;i++)
    {
        // solveRecursion(start,i-1) is for going to the left side i.e. lower and solveRecursion(i+1,end) is going for the right side i.e. higher
        ans=min(ans,i+max(solveRecursion(start,i-1),solveRecursion(i+1,end)));
    }
    return ans;

}

int solveTopDown(int start,int end,vector<vector<int>>&dp)
{
    if (start>=end)
    {
        return 0;
    }
    if(dp[start][end]!=-1)
    {
        return dp[start][end];
    }
    int ans=INT_MAX;
    for(int i=start;i<=end;i++)
    {
        // solveRecursion(start,i-1) is for going to the left side i.e. lower and solveRecursion(i+1,end) is going for the right side i.e. higher
        ans=min(ans,i+max(solveTopDown(start,i-1,dp),solveTopDown(i+1,end,dp)));
    }
    dp[start][end]=ans;
    return dp[start][end];

}

int solveBottomUp(int n)
{
    vector<vector<int>>dp(n+2,vector<int>(n+2,0));
    
    for(int start=n;start>=1;start--)
    {
        for(int end=1;end<=n;end++)
        {   
            if(start>=end)
            {
                continue;
            }
            int ans=INT_MAX;
            for(int i=start;i<=end;i++)
            {
                // solveRecursion(start,i-1) is for going to the left side i.e. lower and solveRecursion(i+1,end) is going for the right side i.e. higher
                ans=min(ans,i+max(dp[start][i-1],dp[i+1][end]));
            }
            dp[start][end]=ans;
        }
    }
    return dp[1][n];
}

int main()
{   
    int n=10;
    int ans=solveRecursion(1,n);
    cout<<"Recursion : "<<ans<<endl;

    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    int ansTop=solveTopDown(1,n,dp);
    cout<<"Top : "<<ansTop<<endl;

    int ansBottom=solveBottomUp(n);
    cout<<"Bottom : "<<ansBottom<<endl;
}