#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>arr{1,4,2,7,4,7,9,7};
    for(int i=0;i<arr.size()-1;i++)
    {   int ans=i;
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[j]<arr[ans])
            {
                ans=j;
            }
        }
        swap(arr[i],arr[ans]);
    }
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}