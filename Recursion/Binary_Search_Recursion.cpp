#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int> &res, int start, int end, int x)
{
    if (start > end)
    {
        return -1;
    }
    int mid = (start + end) / 2;
    if (res[mid] == x)
    {
        return mid;
    }
    if (res[mid] > x)
    {
        return binarySearch(res, start, mid - 1, x);
    }
    if (res[mid] < x)
    {
        return binarySearch(res, mid + 1, end, x);
    }
}
int main()
{
    vector<int> res{1, 2, 3, 4, 5, 6, 7};
    int n = res.size() - 1;
    int i = 0;
    int mid = (i + n) / 2;
    int x = 3;
    int position = -1;
    position = binarySearch(res, i, n, x);
    if (position >= 0)
    {
        cout << position;
    }
    else
    {
        cout << "Not pressent in array";
    }
    return 0;
}