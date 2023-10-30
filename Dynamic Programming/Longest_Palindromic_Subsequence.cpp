// https://leetcode.com/problems/longest-palindromic-subsequence/
// same question ans longest common subsequence bas isme hume sirf 1 hi string mili hai to dursi string hume jo given string hai
// usko reverse karke banani hai baaki sab same hai

//  https://leetcode.com/problems/longest-common-subsequence/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int solveRecursion(string a,string b,int i,int j)
    {
        if(i==a.length())
        {
            return 0;
        }
        if(j==b.length())
        {
            return 0;
        }
        int ans=0;
        if(a[i]==b[j])
        {   
            // agar dono macth kar jae to i aur j dono ko increament kar do
            ans=1+solveRecursion(a,b,i+1,j+1);
        }
        else
        {   
            // agar a[i]!=b[j] to ek baar i++ karo aur j ko as it is rehnedo aur ek baar j++ aur i ko as it is rehnedo aur hume 
            // longest string nikalni hai isliye un sabka max nikal lia
            ans=0+max(solveRecursion(a,b,i,j+1),solveRecursion(a,b,i+1,j));
        }
        return ans;
    }

int solveTopDown(string a,string b,int i,int j,vector<vector<int>>&dp)
    {
        if(i==a.length())
        {
            return 0;
        }
        if(j==b.length())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=0;
        if(a[i]==b[j])
        {
            ans=1+solveTopDown(a,b,i+1,j+1,dp);
        }
        else
        {
            ans=0+max(solveTopDown(a,b,i,j+1,dp),solveTopDown(a,b,i+1,j,dp));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }

int solveBottomUp(string a,string b,int i,int j)
    {   
        vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
        for(int i=a.length()-1;i>=0;i--)
        {
            for(int j=b.length()-1;j>=0;j--)
            {   
                int ans=0;
                if(a[i]==b[j])
                {
                    ans=1+dp[i+1][j+1];
                }
                else
                {
                    ans=0+max(dp[i][j+1],dp[i+1][j]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }

int spaceOptimization(string a,string b)
{
    vector<int>curr(b.length()+1,0);
    vector<int>next(a.length()+1,0);
    for(int i=a.length()-1;i>=0;i--)
        {
            for(int j=b.length()-1;j>=0;j--)
            {   
                int ans=0;
                if(a[i]==b[j])
                {
                    ans=1+next[j+1];
                }
                else
                {
                    ans=0+max(curr[j+1],next[j]);
                }
                curr[j]=ans;
            }
            next=curr;
        }
        return next[0];
}


int main()
{
    string s="bbbab";   
    string text1=s;
    reverse(text1.begin(),text1.end());
    string text2=s;
    int i=0;
    int j=0;
    int ans= solveRecursion(text1,text2,i,j);
    cout<<"Recursion : "<<ans<<endl;

    vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length(),-1));
    int ansTop=solveTopDown(text1,text2,i,j,dp);
    cout<<"TopDown : "<<ansTop<<endl;

    int ansBottom=solveBottomUp(text1,text2,i,j);
    cout<<"Bottom : "<<ansBottom<<endl;

    int ansspaceOptimization=spaceOptimization(text1,text2);
    cout<<"Space Optimization : "<<ansspaceOptimization<<endl;
}