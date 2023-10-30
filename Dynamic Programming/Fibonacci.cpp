#include<iostream>
#include<vector>
using namespace std;

int recursiveSol(int n)
{
    if(n==1||n==0)
    {
        return n;
    }
    int ans=recursiveSol(n-1)+recursiveSol(n-2);
    return  ans;
}

int topDownSol(int n,vector<int>&dp)
{   
    // base casse
    if(n==1||n==0)
    {
        return n;
    }

    // step 3:  after base condition checking if the element already exist in dp array or not
    if(dp[n]!=-1)
    {
        return dp[n];
    }

    //  step 2: replce ans of recursive sol with dp array
    dp[n]=topDownSol(n-1,dp)+topDownSol(n-2,dp);
    return dp[n];
}

int bottomUpSol(int n)
{   
    // step 1: create a dp array of n+1 size because it is from 0 to n and initialize it with -1
    vector<int>dp(n+1,-1);

    // Step 2: convert base contion of Top Down approach and insert it into dp array
    dp[0]=0;
    dp[1]=1;
    
    // Step 3: use the Top Down approach to determine the the start and end of loop, here it from 2 to n as 0 and 1 is already initialized and there are total n elements
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];   // convert recursive logic into iterative
    }
    return dp[n];
}

int spaceOptimizationSol(int n)
{   
    // we only need the previous 2 elements answer to calculate the current element so we dont need to maintain an array of all elements
    int prev2=0;
    int prev1=1;
    int curr=-1;
    for(int i=2;i<=n;i++)
    {
        curr=prev2+prev1;
        prev2=prev1;
        prev1=curr;
    }
    return curr;
}

int main()
{
    int n=8;
    int ans=recursiveSol(n);
    cout<<"Recursive Solution "<<ans<<endl;

    // Top Down Approach
    // step 1: create dp array
    vector<int>dp(n+1,-1);
    int ansTop=topDownSol(n,dp);
    cout<<"Top Down Solution "<<ansTop<<endl;

    // Bottom Up Approach
    int ansBottom=bottomUpSol(n);
    cout<<"Bottom Up Solution "<<ansBottom<<endl;
    
    // Space Optimization
    int ansSpace=spaceOptimizationSol(n);
    cout<<"Space Optimization Solution "<<ansSpace<<endl;
    return 0;
}