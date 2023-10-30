#include<iostream>
#include<vector>
using namespace std;
bool checkSorted(vector<int>& res,int& n,int i)
{
    if(i==n-1)
    {
        return true;
    }
    if(res[i]>res[i+1])
    {
        return false;
    }
    checkSorted(res,n,i+1);
}
int main()
{
    vector<int>res{1,2,3,4,5,6,7};
    int n=res.size();
    int i=0;
    bool isSorted=checkSorted(res,n,i);
    if(isSorted)
    {
        cout<<"Array is Sorted";
    }
    else{
        cout<<"array is not sorted";
    }
    return 0;

}