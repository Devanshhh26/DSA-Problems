// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(colors[i]==colors[i-1])                  // check if adjacent colors are same
            {
                ans+=min(neededTime[i],neededTime[i-1]);    // if they are same then we have to remove the baloon with they minimum time among the therefore we add it to ans
                neededTime[i]=max(neededTime[i],neededTime[i-1]);       // since we have now removed the baloon with minimum time therefore we store the value of time whose value was greater for further check (we havent actually removed the baloon we are just pretending we have removed therefore we have to overwrite its value with the max of neededtime among them)
            }
        }
        return ans;
}

int main()
{
    string colors="abaac";
    vector<int>neededTime{1,2,3,4,5};
    int ans=minCost(colors,neededTime);
    cout<<ans;
    return 0;
}


