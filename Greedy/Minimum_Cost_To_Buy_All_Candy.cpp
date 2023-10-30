// when you buy 1 candy you can take any 2 candies for free so we have to find the minimum money we should spend to buy all candies

// sort the prices and take to pointers one at start and one at end
// start is for buying and end is for free candies
// each turn you move start by 1 and end by 2 beacuse you 1 one and get 2 free (it is obvious that you expensive candy will be at
// end as you have sorted the array so to minimize the cost we will buy the cheapest candy and take the two most expensive candy 
// for free)
// when start > end we will get our answer


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int>arr{2,8,6,9,4,7};
    int n=6;
    sort(arr.begin(),arr.end());
    int buy=0;
    int free=n-1;
    int totalPrice=0;
    while(buy<free)
    {
        totalPrice+=arr[buy];
        buy++;
        free--;
        free--;
    }
    cout<<"Total Price : "<<totalPrice;
    return 0;
}
