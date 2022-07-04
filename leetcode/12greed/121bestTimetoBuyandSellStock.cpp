#include<iostream>
#include<algorithm>
#include<vector>
#include"helpvector.h"
using namespace std;

/*********************************************************************************************
Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
https://leetcode-cn.com/circle/article/qiAgHn/
*********************************************************************************************/
// LeetCode, Best Time to Buy and Sell Stock
// 时间复杂度 O(n)，空间复杂度 O(1)
class Solution {
public: // 当前位置为最小值，然后每次使用当前元素减去前面的最小值得出的值为最大利润
    int maxProfit(vector<int>& prices) {
        int res = INT32_MIN;
        int min_profit = prices[0];
        for(int i = 0; i < prices.size(); i++)
        {
            min_profit = min(min_profit, prices[i]);
            res = max(res,prices[i] - min_profit);
        }
        return res;
    }
};

int main()
{   
    vector<int> pricces = {7,1,5,3,6,4};
    vec_print(pricces);
    Solution ab;
    int res = ab.maxProfit(pricces);
    cout << "res :  " << res << endl;
    cout << "hello " << endl;
    return 0;
}