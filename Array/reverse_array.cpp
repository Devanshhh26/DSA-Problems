#include <iostream>
using namespace std;
int main()
{
    int arr[10], n, high = n - 1, low = 0, temp = 0;
    cout << "Enter number of elements";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value" << endl;
        cin >> arr[i];
    }
    while (low < high)
    {
        temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}