#include<iostream>
#include<string>
#include<vector>
using namespace std;

void printSubarrayForEach(vector<int>res,int i,int n)
{
    if(i>n)
    {
        return;
    }
    while(i<n)
    {
        cout<<res[i];
    }
    cout<<endl;
    printSubarrayForEach(res,i+1,n);
}

void printSubarray(vector<int>res)
{
    for(int i=0;i<res.size();i++)
    {   int end=i;
        printSubarrayForEach(res,i,end);
    }
}

int main()
{
    vector<int>res{1,2,3,4,5,6,7,8,9,0};
    printSubarray(res);
    return 0;   
}