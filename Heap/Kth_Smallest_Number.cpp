// min heap se bhi ho jaega easily but space compexity zyada lagegi

#include<iostream>
#include<queue>
using namespace std;

int getKthSmallest(int arr[],int n,int k)
{
    priority_queue<int>pq;
    
    // inserting initial k elements int pq
    for(int i=0;i<k;i++)
    {
        pq.push(arr[i]);
    }
    // for remaining elements , push only if they are smaller than top element
    for(int i=k;i<n;i++)
    {
        int element=arr[i];
        if(element<pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }
    int ans=pq.top();
    return ans;

}


int main()
{
    int arr[]={10,5,20,4,15};
    int n=5;
    int k=2;
    int ans= getKthSmallest(arr,n,k);
    cout<<ans;
    return 0;
}