#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> res{1, 2, 4, 6, 2, 9, 6, 3, 7, 8, 1, 4, 5, 8, 7};
    set<pair<int, int>> ans;                                     //only takes unique pairs
    int start = 0;
    int end = res.size() - 1;
    int i = 0;
    int j = 1;
    int k = 4;
    sort(res.begin(), res.end());
    while (j < res.size())
    {
        int diff = res[j] - res[i];
        if (diff == k)
        {
            ans.insert({res[i], res[j]});
            i++;
            j++;
        }
        else if (diff > k)                                      // if diff is greater then reduce the size by taking i closer to j
        {
            i++;
        }
        else                                                   // if diff is smaller then increase it by taking j farther from i
        {
            j++;
        }
        if (i == j)
        {
            j++;
        }
    }
    cout << ans.size();
    return 0;
}