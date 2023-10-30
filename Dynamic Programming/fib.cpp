#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n=6;
    int k=3;
    int m=k;
    vector<int>res;
    while(m--)
    {
        res.push_back(1);
    }
    m=k;
    for(int i=m;i<n;i++)
    {
        int sum=0;
        int sum=0;
        for(int j=i-k;j<i;j++)
        {
            sum=sum+res[j];
        }
        res.push_back(sum);
    }
    for(auto it:res)
    {
        cout<<it<<" ";
    }
    return 0;
}