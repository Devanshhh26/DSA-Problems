#include <iostream>
using namespace std;
int main()
{
    int arr[10], n, count = 0;
    cout << "Enter number of elements";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value" << endl;
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            swap(arr[i], arr[count]);
            count++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}