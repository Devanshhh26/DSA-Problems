#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> res{8, 9, 10, 17, 1, 3};
    int s = 0;
    int e = res.size() - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (res[mid] > res[mid + 1] && res[mid + 1] < res.size())   // we are on pivot
        {
            cout << mid;
            break;
        }
        if (res[mid] < res[mid - 1] && res[mid - 1] >= 0)       // we are in second line
        {
            cout << mid - 1;
            break;
        }
        if (res[s] >= res[mid])                                 // we are in second line
        {
            e = mid - 1;
        }
        else                                                  // we are on first line
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return 0;
}