#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int binarySearch(vector<int>&res,int start,int end,int x)
{
    int mid=start+(end-start)/2;
    while(start<=end)
    {
        if(res[mid]==x)
        {
            return mid;
        }
        else if(res[mid]>x)
        {
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}

int main()
{
    vector<int> res{1, 2, 4, 6, 2, 9, 6, 3, 7, 8, 1, 4, 5, 8, 7};
    set<pair<int, int>> ans;                                     //only takes unique pairs
    int k = 2;
    sort(res.begin(), res.end());
    for(int i=0;i<res.size();i++)
    {
        if(binarySearch(res,i+1,res.size()-1,res[i]+k)!=-1)     // k=res[j]-res[i]  ==> res[i]+k=res[j] find if there exist an element whose value is equal rto res[i]+k
        {
            ans.insert({res[i],res[i]+k});
        }
    }
    cout<<ans.size();
    
    return 0;
}