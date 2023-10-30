#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> res{1, 2, 3, 4, 4, 4, 4, 4, 5, 6, 7};
  int start = 0;
  int end = res.size() - 1;
  int temp = -1;
  int target = 4;
  int mid = start + (end - start) / 2;
  while (start <= end)
  {
    mid = start + (end - start) / 2;
    if (res[mid] == target)
    {
      temp = mid;                                       // store as possible ans and move right to check for any other possible answer at right
      start = mid + 1;
    }
    else if (res[mid] > target)
    {
      end = mid - 1;
    }
    else
    {
      start = mid + 1;
    }
  }
  cout << temp;
  return temp;
}