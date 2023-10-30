
//step 1: first element har array ke insert karo heap me 
//step 2: uske baad heap ka top element vector me store karwa denge aur heap se pop karwa denge
//step 3: jis array ka element pop karwaya hoga uska next element check karenge aur push kar denge heap me firse step 2 me jaenge aur step 3 me fir aur isko repeat karenge jab tak heap empty nahi hota

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class info{
    public:
    int data;
    int row;
    int col;

    info(int val,int r,int c)
    {
        data=val;
        row=r;
        col=c;
    }
};

class compare{
    public:
    bool operator()(info*a,info*b)
    {
        return a->data>b->data;
    }

};

vector<int>mergeKSortedArrays(int arr[][4],int k,int n)
{
    priority_queue<info*,vector<info*>,compare>minheap;

    // har array ka first element insert karo

    for(int i=0;i<k;i++)
    {
        info*temp=new info(arr[i][0],i,0);
        minheap.push(temp);
    }
    vector<int>ans;
    while(!minheap.empty())
    {
        info*temp=minheap.top();
        int topElement=temp->data;
        int topRow=temp->row;
        int topCol=temp->col;
        minheap.pop();
        ans.push_back(topElement);
        if(topCol+1<n)
        {
            info* newInfo=new info(arr[topRow][topCol+1],topRow,topCol+1);
            minheap.push(newInfo);
        }
    }
    return ans;
}


int main()
{
    int arr[][4]={{2,4,6,8},{1,3,5,7},{0,9,10,11}};
    int k=3;
    int n=4;
    vector<int>ans=mergeKSortedArrays(arr,k,n);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
}