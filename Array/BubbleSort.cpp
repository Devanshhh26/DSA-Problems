#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int>res{45,2,89,21,56,35,98};
    for(int i=1;i<res.size();i++)
    {
        for(int j=0;j<res.size()-1;j++)
        {
            if(res[j]>res[j+1])
            {
                swap(res[j],res[j+1]);
            }
        }
    }
    for(auto it:res)
    {
        cout<<it<<endl;
    }
    return 0;
}