#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

bool isPossible(int res[],int N,int M,int sol)
{
    int pageSum=0;
    int c=1;
    for(int i=0;i<N;i++)
    {
        if(res[i]>sol)
        {
            return false;
        }
        if(pageSum+res[i]>sol)
        {
            c++;
            pageSum=res[i];
            if(c>M)
            {
                return false;
            }
        }
        else{
            pageSum=pageSum+res[i];
        }
    }
    return true;
}

int main()
{   
    int res[]={12,34,67,90};
    int N=4;
    int M=2;
    int start=0;  
    int end=accumulate(res,res+N,0);
    int ans=-1;
    
    while(start<=end)
    {   int mid=start+(end-start)/2;
        if(isPossible(res,N,M,mid))
        {
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    cout<<ans;
    return 0;
}