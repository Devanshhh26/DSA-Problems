#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

 int knapsack(vector<int>profit,vector<int>weight,int w,int n)
 {
    if(n==0 ||  w==0)                                   // agar humare pass koi element hi na ho ya fir humare bag ki capacity hi khatam ho jae to iska matlab hum aur profit add nahi karsakte
    {
        return 0;
    }
    if(weight[n-1]>w)                                   // agar element ka weight capacity se zyada ho to uss element ko skip kar denge
    {
        return knapsack(profit,weight,w,n-1);           
    }
    if(weight[n-1]<=w)                                  // agar uss element ka weight kam ho ya equal ho capacity ke to hum humare pass 2 choice hogi ya to include kare ya nahi hum sirf tab hi include karenge agar vo hume zyada profit de isliye hum dono choices me recursive call mar denge ek baar uss element ko add karke (i.e uska profit add karke) aur ek baar use skip karke
    {
        return max(profit[n-1]+knapsack(profit,weight,w-weight[n-1],n-1),knapsack(profit,weight,w,n-1));    
    }
 }

int topDownApproach(vector<int>profit,vector<int>weight,int w,int n,vector<vector<int>>&dp)
 {
    if(n==0 ||  w==0)                                   // agar humare pass koi element hi na ho ya fir humare bag ki capacity hi khatam ho jae to iska matlab hum aur profit add nahi karsakte
    {
        return 0;
    }
    if(dp[n][w]!=-1)                                    // matlab iss type ka case already process kar chuke hai to dp array se use return kardo
    {
        return dp[n][w];
    }
    if(weight[n-1]>w)                                   // agar element ka weight capacity se zyada ho to uss element ko skip kar denge
    {
        return dp[n][w]=topDownApproach(profit,weight,w,n-1,dp);           
    }
    if(weight[n-1]<=w)                                  // agar uss element ka weight kam ho ya equal ho capacity ke to hum humare pass 2 choice hogi ya to include kare ya nahi hum sirf tab hi include karenge agar vo hume zyada profit de isliye hum dono choices me recursive call mar denge ek baar uss element ko add karke (i.e uska profit add karke) aur ek baar use skip karke
    {
        return dp[n][w]=max(profit[n-1]+topDownApproach(profit,weight,w-weight[n-1],n-1,dp),topDownApproach(profit,weight,w,n-1,dp));    
    }
 }

  int bottomUpApproach(vector<int>profit,vector<int>weight,int w,int n)
 {  
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<w+1;j++)
        {
            if(weight[i-1]<=j)
            {
                dp[i][j]=max((profit[i-1]+dp[i-1][j-weight[i-1]]),dp[i-1][j]);      // top down approach me jaha bhi recursive call thi use dp array se replace kar do aur jaha bhi n tha use i se replace kar do aur w ko j se 
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
 }

int main()
{
    int n=3;
    int w=4;
    vector<int>profit={1,2,3};
    vector<int>weight={4,5,1};
    //recursive
    int ans=knapsack(profit,weight,w,n);
    cout<<"Answer is : "<<ans<<endl;
    //top down dp
    vector<vector<int>>dp(n+1,vector<int>(w+2,-1));
    int ansTop=topDownApproach(profit,weight,w,n,dp);
    cout<<"Answer for TopDown is : "<<ansTop<<endl;
    // bottom up approach
    int ansBottom=bottomUpApproach(profit,weight,w,n);
    cout<<"Answer for bottom up is : "<<ansBottom<<endl;
    return 0;
}