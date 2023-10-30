//  https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

#include<iostream>
#include<vector>
using namespace std;

int MOD=1000000007;

int solveRecursion(int n, int k, int target)
{
    if(target<0)
    {
        return 0;
    }
    // dice bhi nahi hai aur target bhi nahi hai
    if(n==0 &&  target==0)
    {
        return 1;
    }
    // dice nahi hai but target bacha hai
    if(n==0 &&  target!=0)
    {
        return 0;
    }
    // dice hai but target bacha nahi hai
    if(n!=0 &&  target==0)
    {
        return 0;
    }
    int ans=0;
    for(int i=1;i<=k;i++)
    {
        ans=ans+solveRecursion(n-1,k,target-i);
    }
    return ans;
}

int solveTopDown(int n,int k,int target,vector<vector<int>>&dp)
{
     if(target<0)
    {
        return 0;
    }
    // dice bhi nahi hai aur target bhi nahi hai
    if(n==0 &&  target==0)
    {
        return 1;
    }
    // dice nahi hai but target bacha hai
    if(n==0 &&  target!=0)
    {
        return 0;
    }
    // dice hai but target bacha nahi hai
    if(n!=0 &&  target==0)
    {
        return 0;
    }
    if(dp[n][target]!=-1)
    {
        return dp[n][target];
    }
    int ans=0;
    for(int i=1;i<=k;i++)
    {
        ans=(ans%MOD+solveTopDown(n-1,k,target-i,dp)%MOD)%MOD;
    }
    dp[n][target]=ans;
    return dp[n][target];
}

 int solveUsingTabulation(int n, int k, int target) {
        vector<vector< long long int> > dp(n+1, vector< long long int>(target+1, 0));
        dp[0][0] = 1;

        for(int index = 1; index <=n; index++) {
            for(int t=1; t<=target; t++) {

                long long int ans = 0;
                for(int i=1; i<=k; i++) {
                    long long int recAns = 0;
                    if(t - i >= 0 )
                        recAns = dp[index-1][t-i];
                    ans = (ans % MOD + recAns % MOD) % MOD;
                }
                dp[index][t] =  ans;
            }
        }

    return dp[n][target];

    }


    int solveUsingTabulationSO(int n, int k, int target) {

        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);

        prev[0] = 1;

        for(int index = 1; index <=n; index++) {
            for(int t=1; t<=target; t++) {

                long long int ans = 0;
                for(int i=1; i<=k; i++) {
                    long long int recAns = 0;
                    if(t - i >= 0 )
                        recAns = prev[t-i];
                    ans = (ans % MOD + recAns % MOD) % MOD;
                }
                curr[t] =  ans;
            }
            //shift
            prev = curr;
        }

    return prev[target];

    }


int main()
{
    int n=1;
    int k=6;
    int target =6;

    int ans=solveRecursion(n,k,target);
    cout<<"Recursion : "<<ans<<endl;

    vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
    int ansTop=solveTopDown(n,k,target,dp);
    cout<<"Top Down : "<<ansTop<<endl;

}