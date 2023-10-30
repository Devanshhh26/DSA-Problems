#include <iostream>
#include <limits.h>
using namespace std;
void findMax(int* arr, int n, int i, int &ans)
{
    if (i > n)
    {
        return;
    }
    if (arr[i] >= ans)
    {
        ans = arr[i];
    }
    findMax(arr, n, i + 1, ans);
    cout << ans;
}
int main()
{
    int arr[] = {23, 5, 1, 76, 1, 6, 78, 10};
    int maxi = INT_MIN;
    int i = 0;
    int n = 7;
    findMax(arr, n, i, maxi);
    return 0;
}