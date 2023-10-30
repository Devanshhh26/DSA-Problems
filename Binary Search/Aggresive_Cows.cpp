

// https://practice.geeksforgeeks.org/problems/aggressive-cows/1


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int>stalls,int k,int mid)
{
    int pos=stalls[0];
    int c=1;
    for(int i=1;i<stalls.size();i++)
    {
        if(stalls[i]-pos>=mid)
        {
            c++;
            pos=stalls[i];
        }
        if(c==k)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int>stalls{1,2,4,8,9};
    int k=3;
    sort(stalls.begin(),stalls.end());
    int ans=-1;
    int start=0;
    int end=stalls[stalls.size()-1]-stalls[0];
    int mid=start+(end-start)/2;
    while(start<=end)
    {
        if(isPossible(stalls,k,mid))
        {
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    cout<<ans;
    return 0;

}