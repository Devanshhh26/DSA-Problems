#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> res{1, 1, 2, 2, 3, 3, 2, 4, 4, 5, 5, 4, 4, 6, 6};
    int start = 0;
    int end = res.size() - 1;
    int ans = 0;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (start == end)
        {
            cout << start;
            return 0;
        }
        if (mid % 2 == 0)
        {
            if (res[mid] == res[mid + 1])
            {
                start = mid + 2;
            }
            else
            {
                ans = mid;
                end = mid;
            }
        }
        else
        {
            if (res[mid] == res[mid - 1])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        mid = start + (end - start) / 2;
    }
    cout << ans;
    return 0;
}