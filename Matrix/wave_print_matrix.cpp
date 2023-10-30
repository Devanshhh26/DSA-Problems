#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<vector<int>>res{{1,2,3},
                        {4,5,6},
                        {7,8,9}};

    for(int i=0;i<res[0].size();i++)
    {   if(i%2==0)
        {
            for(int j=0;j<res.size();j++)
            {
                cout<<res[j][i]<<" ";
            }
        }
        else{
             for(int j=res.size()-1;j>=0;j--)
            {
                cout<<res[j][i]<<" ";
            }
        }
    }
  return 0;
}