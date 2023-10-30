// iss question me hume ek rope banani hai saare elements ko jodke but har element ki khudki ek cost hai to hume 2 elements ko jodna hai
// hai aur fir uska sum cost me add karna hai aur sum ko vapis array me replace kar dena hai unn do elements ke badle

// easiest way to do this would be to just keep adding the minimum 2 elements and then replace them with their sum
// so the most efficient way to find the minimum element is fron an min heap

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int arr[]={4,3,2,6};
    int n=4;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);                                    // saare elements ko min heap me daal dia
    }
    int cost=0;
    while(pq.size()!=1)                                 
    {
        int first=pq.top();                                // minimum element nikala
        pq.pop();                                           // fir use pop kar dia
        int second=pq.top();                                // fir next minimum element nikala
        pq.pop();                                           // fir use bhi pop kar dia
        cost+=first+second;                                 // dono ko cost me add kar dia
        int newLength=first+second;                         // dono element ke sum ko first minheap me add kar dia
        pq.push(newLength);
    }
    cout<<cost;
    return 0;
}