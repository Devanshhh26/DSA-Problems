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

int main()
{
    int n=3;
    int w=4;
    vector<int>profit={1,2,3};
    vector<int>weight={4,5,1};
    int ans=knapsack(profit,weight,w,n);
    cout<<"Answer is : "<<ans;
    return 0;
}