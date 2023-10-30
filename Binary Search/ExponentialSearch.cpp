#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>res,int start,int end,int target)
{
    int mid=start+(end-start)/2;
    while(start<=end)
    {
        if(res[mid]==target)
        {
            return mid;
        }
        else if(res[mid]>target)
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
    vector<int>res{1,2,3,4,5,6,7,8,9,11,22,33,44,55,66,77,88,99,111,222,333,444,555,666,777,888,999};
    int target=777;
    if(res[0]==target)
    {
        return 0;
    }
    int i=1;
    while(i<res.size() && res[i]<target)
    {
        i=i*2;
    }
    int ans=binarySearch(res,i/2,i,target);
    cout<<ans;
    return 0;
}