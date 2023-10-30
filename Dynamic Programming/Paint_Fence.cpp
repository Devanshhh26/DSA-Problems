// n= number of fences and k= number of colors
// do se zyada lagatar same color paint nahi kar sakte
#include<iostream>
#include<vector>
using namespace std;

int solveRecursion(int n,int k)
{   
    // agar sirf 1 hi fence hogi aur humare pass ke colors honge to humare pass k ways honge paint karne ke that is jitne number of paints hai humpe
    if(n==1)
    {
        return k;
    }
    // agar 2 fence hogi to humare pass (k+k*(k-1)) tareeke honge paint karne ke that is after solving k*k
    if(n==2)
    {
        return k*k;
    }
    // agar yaad na ho raha ho to iska ratta maar lo
    int ans=(solveRecursion(n-2,k)+solveRecursion(n-1,k))*(k-1);
    return ans;
}

int solveTopDown(int n,int k,vector<int>&dp)
{
    if(n==1)
    {
        return k;
    }
    if(n==2)
    {
        return k*k;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    dp[n]=(solveTopDown(n-2,k,dp)+solveTopDown(n-1,k,dp))*(k-1);
    return dp[n];
}

int solveBottomUp(int n,int k)
{
    vector<int>dp(n+1,-1);
    dp[1]=k;
    dp[2]=k*k;
    for(int i=3;i<=n;i++)
    {
        dp[i]=(dp[i-2]+dp[i-1])*(k-1);
    }
    return dp[n];

}

int spaceOptimization(int n,int k)
{
    
    int prev2=k;
    int prev1=k*k;
    int curr=0;
    for(int i=3;i<=n;i++)
    {
        curr=(prev2+prev1)*(k-1);

        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

int main()
{
    int n=4;
    int k=3;
    int ans=solveRecursion(n,k);
    cout<<"Recursive sol: "<<ans<<endl;

    vector<int>dp(n+1,-1);
    int ansTop=solveTopDown(n,k,dp);
    cout<<"Top Down : "<<ansTop<<endl;

    int ansBottom=solveBottomUp(n,k);
    cout<<"Bottom Up : "<<ansBottom<<endl;

    int ansSpace=spaceOptimization(n,k);
    cout<<"Space Optimization : "<<ansSpace<<endl;
}