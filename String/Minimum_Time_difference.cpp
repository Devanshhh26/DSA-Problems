
// https://leetcode.com/problems/minimum-time-difference/description/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    vector<string> timePoints{"23:59", "00:00", "12:45", "16:20", "09:56", "19:12"};
    vector<int> ans;
    for (int i = 0; i < timePoints.size(); i++)
    {
        string s = timePoints[i];
        int hour = stoi(s.substr(0, 2));                                     // Extracting hours from string and converting it into int
        int minutes = stoi(s.substr(3, 2));                                 // Extracting minutes from string and converting it into int
        int totalMinutes = hour * 60 + minutes;
        ans.push_back(totalMinutes);
    }
    sort(ans.begin(), ans.end());
    int minDiff = 999999;
    for (int i = 1; i < ans.size(); i++)
    {
        minDiff = min(minDiff, ans[i] - ans[i - 1]);
    }
    int lastDiff = abs(ans[ans.size() - 1] - (ans[0] + 1440)); // to handle "00:00" cases
    minDiff = min(minDiff, lastDiff);
    cout << minDiff;
    return 0;
}