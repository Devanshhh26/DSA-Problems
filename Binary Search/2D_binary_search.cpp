#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> res{{1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9}};

    int m = 3;
    int n = 3;
    int s = 0;
    int e = n * m - 1;
    int mid = s + (e - s) / 2;
    int target = 8;
    while (s <= e)
    {
        int row = mid / n;
        int col = mid % n;
        if (res[row][col] == target)
        {
            cout << mid;
            return 0;
        }
        if (res[row][col] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return 0;
}