
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include<iostream>
#include<vector>
using namespace std;

 void maxProfitFinder(vector<int>&prices,int index,int& minPrice,int& maxProfit)
    {   
        if(index>=prices.size())
        {
            return;
        }
        if(prices[index]<minPrice)
        {
            minPrice=prices[index];
        }
        if(prices[index]-minPrice>maxProfit)
        {
            maxProfit=prices[index]-minPrice;
        }
        maxProfitFinder(prices,index+1,minPrice,maxProfit);
    }
    int main()
    {
      vector<int>prices{7,1,5,3,6,4};
      int minPrice=INT16_MAX;
      int maxProfit=INT16_MIN;
      maxProfitFinder(prices,0,minPrice,maxProfit);
      cout<<maxProfit;
      return 0;
    }



    // iterative approach
    // int main()
    // {
    //        vector<int>prices{7,1,5,3,6,4};
    //     int profit=0;
    //   int minprice=INT_MAX;
    //     for(int i=0;i<prices.size();i++)
    //     {
    //       minprice=min(minprice,prices[i]);
    //       profit=max(profit,prices[i]-minprice);
    //     }
    //     return profit;
    // }