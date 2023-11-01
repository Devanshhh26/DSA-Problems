// nummber of times a sorted array is rotated = index of minimum element
// we can use linear search to find minimum element

// we can apply binary search to reduce time compexity
// we can also use this approach to search in a sorted rotated array : pehle minimum element nikal lenge fir start se minimum element -1 tak sinary search laga 
// denge aur minimum element se end last element tak binary search laga denge kahi na kahi to element mil hi jaega agar nahi mila to matlab element present hi nahi hai
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int>res={5,6,7,8,11,12,15,18,19,2};
    int start=0;
    int end=res.size()-1;
    int ans=0;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(res[mid]>res[mid+1])         // agar mid element mid+1 element se bada ho to matlab mid+1 answer hoga
        {
            ans=mid+1;
            break;
        }
        if(res[mid]<res[mid-1])         // agar mid element mid-1 se chota ho to to matlab mid answer hoga
        {
            ans=mid;
            break;
        }

        if(res[start]<res[mid])        
        {
            start=mid;
        }
        if(res[end]>res[mid])
        {
            end=mid-1;
        }
    }
    cout<<ans;
    return 0;
}