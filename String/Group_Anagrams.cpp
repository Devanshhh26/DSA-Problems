
// https://leetcode.com/problems/group-anagrams/description/

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    map<string, vector<string>> mp;
    for (auto str : strs)
    {
        string s = str;
        sort(s.begin(), s.end());                   //sort eat -> aet
        mp[s].push_back(str);                       // map aet to eat,tea,ate and ant to tan,nat and abt to bat
    }
    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        ans.push_back(it->second);                  // now simply push eat,tea,ate then push tan,nat and then push abt 
    }
    return 0;
}