// we have and array which represents number of chocolate in each packet
// we have to distribute the chocolate between M students in such a way that each student gets exactly 1 packet and the difference between the maximum
// number of chocolate given to a student and minumum number of chocolate given is minimum



// first sort the array 
// create a window of M size and find the difference between the max and min element in that window
// shift the window forward and repeat the same procedure until then window reaches the end of array
// the minimum difference we get after calculating the differences in each window would be our answer

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

int main()
{
    int arr[]={7,3,2,4,9,12,56};
    int n=7;
    int m=3;
    sort(arr,arr+n);
    int minDiff=INT_MAX;
    for(int i=0;i<n;i++)
    {   
        if(i<n-5)
        {
            int diff=arr[i+m-1]-arr[i];
            minDiff=min(minDiff,diff);
        }
    }
    cout<<minDiff;
    return 0;
}