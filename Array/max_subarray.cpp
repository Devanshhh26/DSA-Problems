#include <iostream>
using namespace std;
int main()
{
    int arr[10] = {1, 2, 3, 4, -50, -6, -7, 8, 9, 10};
    int res = arr[0];
    int maxEnding = arr[0];
    for (int i = 1; i < 10; i++)
    {
        maxEnding = max(maxEnding + arr[i], arr[i]);            // finding max among the current elemnt and the sum of elements uptill now
        res = max(res, maxEnding);                              // handling negative cases
    }
    cout << res << endl;
}