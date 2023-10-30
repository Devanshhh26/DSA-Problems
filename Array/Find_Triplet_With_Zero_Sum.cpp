#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{   
    int arr[5]={0, -1, 2, -3, 1};
    int n=5;
    sort(arr,arr+n);
        for(int i=0;i<n;i++)
        {
            int left=i+1;
            int right=n-1;
            while(left<right)
            {
                int sum=arr[i]+arr[left]+arr[right];
                if(sum==0)
                {
                    cout<<"True";
                    return 0;
                }
                if(sum<0)
                {
                    left++;
                }
                if(sum>0)
                {
                    right--;
                }
            }
        }
    cout<<"False";
    return 0;
}