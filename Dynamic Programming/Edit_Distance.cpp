// https://leetcode.com/problems/edit-distance/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int solveRecursion(string a,string b,int i,int j)
    {
        if(i==a.length())
        {
            return b.length()-j;
        }
        if(j==b.length())
        {
            return a.length()-i;
        }
        int ans=0;
        if(a[i]==b[j])
        {   
            // sgar string match kar jar
            ans=solveRecursion(a,b,i+1,j+1);
        }
        else{
            // agar match na kare to hum 3 operations perform kar sakte hai 
            int insert=1+solveRecursion(a,b,i,j+1);         //insert me hum aisa assume karenge ki new char humne string ke aage insert 
            //kia hai that is i-1 position me aur fir match ho jaega isliye fir humne j++ kar denge next char ko match karvane ke lie 
            //but i will remain in its original position so that we can check it with next char of word2
            int deleted=1+solveRecursion(a,b,i+1,j);        //delete kar do vo char, so basically i++ karke aage badh jao
            int replace=1+solveRecursion(a,b,i+1,j+1);      //replace kar do char, it means humne a[i] ko replace kar dia b[j] se fir
            // iska  matlab it is sure that a[i]==b[j] ho jaega isliye fir i++,j++ kardenge
            ans=min(insert,min(deleted,replace));           // minimum poocha hai question me 
        }
        return ans;
    }

int solveTopDown(string a,string b,int i,int j,vector<vector<int>>&dp)
{
    if(i==a.length())
        {
            return b.length()-j;
        }
        if(j==b.length())
        {
            return a.length()-i;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=0;
        if(a[i]==b[j])
        {   
            // agar string match kar jar
            ans=solveTopDown(a,b,i+1,j+1,dp);
        }
        else{
            int insert=1+solveTopDown(a,b,i,j+1,dp);
            int deleted=1+solveTopDown(a,b,i+1,j,dp);
            int replace=1+solveTopDown(a,b,i+1,j+1,dp);
            ans=min(insert,min(deleted,replace));
        }
        dp[i][j]=ans;
        return dp[i][j];
}

int solveBottomUp(string a,string b)
{
    vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
    for(int j=0;j<=b.length();j++)
    {
        dp[a.length()][j]=b.length()-j;
    }
    for(int i=0;i<=a.length();i++)
    {
        dp[i][b.length()]=a.length()-i;
    }
    for(int i=a.length()-1;i>=0;i--)
    {
        for(int j=b.length()-1;j>=0;j--)
        {
        int ans=0;
        if(a[i]==b[j])
        {   
            // agar string match kar jar
            ans=dp[i+1][j+1];
        }
        else{
            int insert=1+dp[i][j+1];
            int deleted=1+dp[i+1][j];
            int replace=1+dp[i+1][j+1];
            ans=min(insert,min(deleted,replace));
        }
        dp[i][j]=ans;
        
        }
    }
    return dp[0][0];
}


int spaceOptimization(string a,string b)
{
    vector<int>curr(b.length()+1,0);
    vector<int>next(b.length()+1,0);
    for(int j=0;j<=b.length();j++)
    {
        next[j]=b.length()-j;
    }
    for(int i=a.length()-1;i>=0;i--)
    {   
        curr[b.length()]=a.length()-i;
        for(int j=b.length()-1;j>=0;j--)
        {
        int ans=0;
        if(a[i]==b[j])
        {   
            // agar string match kar jar
            ans=next[j+1];
        }
        else{
            int insert=1+curr[j+1];
            int deleted=1+next[j];
            int replace=1+next[j+1];
            ans=min(insert,min(deleted,replace));
        }
        curr[j]=ans;
        
        }
        next=curr;
    }
    return next[0];
}

int main()
{
    string word1="horse";
    string word2="ros";
    int i=0;
    int j=0;
    int ans=solveRecursion(word1,word2,i,j);
    cout<<"Recursion : "<<ans<<endl;

    vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
    int ansTop=solveTopDown(word1,word2,i,j,dp);
    cout<<"Top Down : "<<ansTop<<endl;

    int ansBottom=solveBottomUp(word1,word2);
    cout<<"Bottom Up : "<<ansBottom<<endl;

    int ansSO=spaceOptimization(word1,word2);
    cout<<"Space Optimization : "<<ansSO<<endl;
}